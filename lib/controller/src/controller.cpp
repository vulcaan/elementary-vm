#include "controller.hpp"

#include "cli/icommand.hpp"
#include "cli/parser.hpp"
#include "ioperand.hpp"

namespace elemvm
{
namespace pc = parsing::cli;
ElementaryVM::ElementaryVM()
    : m_out(std::cout)
{
    m_storage = std::make_shared<std::stack<std::shared_ptr<const operands::IOperand>>>();
    m_cli_parser = configureParser();
}

ElementaryVM::ElementaryVM(std::unique_ptr<parsing::cli::IParser> parser)
    : m_cli_parser(std::move(parser))
    , m_out(std::cout){};

ElementaryVM::~ElementaryVM() = default;

std::unique_ptr<pc::IParser> ElementaryVM::configureParser()
{
    auto cli_parser = std::make_unique<pc::Parser>();
    bool isSubParserAdded;

    isSubParserAdded = cli_parser->addSubparser(std::string("-h"),
                                                pc::eCommand::HELP);
    if (!isSubParserAdded)
        return nullptr;

    isSubParserAdded = cli_parser->addSubparser(std::string("--help"),
                                                pc::eCommand::HELP);
    if (!isSubParserAdded)
        return nullptr;

    isSubParserAdded = cli_parser->addSubparser(std::string("-i"),
                                                pc::eCommand::INPUT_INTERACT);
    if (!isSubParserAdded)
        return nullptr;

    isSubParserAdded = cli_parser->addSubparser(std::string("--interactive"),
                                                pc::eCommand::INPUT_INTERACT);
    if (!isSubParserAdded)
        return nullptr;

    isSubParserAdded = cli_parser->addSubparser(std::string("-f"),
                                                pc::eCommand::INPUT_FILE);
    if (!isSubParserAdded)
        return nullptr;

    isSubParserAdded = cli_parser->addSubparser(std::string("--file"),
                                                pc::eCommand::INPUT_FILE);
    if (!isSubParserAdded)
        return nullptr;
    return cli_parser;
}

int ElementaryVM::run(int argc, char* argv[])
{
    try
    {
        if (!m_cli_parser)
        {
            throw std::runtime_error("[ERROR] The CLI Parser is badly configured.");
        }
        auto command = m_cli_parser->parse({argv + 1, argv + argc});
        auto result = command->run(m_storage);
        return result ? 0 : 1;
    }
    catch (std::runtime_error& e)
    {
        m_out << e.what() << std::endl;
    }
    catch (...)
    {
        m_out << "Unexpected exception has been thrown, aborting..."
              << std::endl;
    };
    return 1;
};

void ElementaryVM::setOut(std::ostream& out) { m_out.rdbuf(out.rdbuf()); };

}  // namespace elemvm
