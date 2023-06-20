#include "controller.hpp"

namespace elemvm
{
ElementaryVM::ElementaryVM()
    : m_out(std::cout)
{
    m_storage = std::make_shared<std::stack<int>>();

    auto cli_parser = std::make_unique<pc::Parser>();
    cli_parser->addSubparser(std::string("-h"),
                             std::make_unique<pc::HelpParser>());
    cli_parser->addSubparser(std::string("--help"),
                             std::make_unique<pc::HelpParser>());
    cli_parser->addSubparser(std::string("-i"),
                             std::make_unique<pc::InputInteractParser>());
    cli_parser->addSubparser(std::string("--interactive"),
                             std::make_unique<pc::InputInteractParser>());
    cli_parser->addSubparser(std::string("-f"),
                             std::make_unique<pc::InputFromFileParser>());
    cli_parser->addSubparser(std::string("--file"),
                             std::make_unique<pc::InputFromFileParser>());

    m_cli_parser = std::move(cli_parser);
}
int ElementaryVM::run(int argc, char* argv[])
{
    std::cout << "[ElementaryVM::run] Start\n";
    try
    {
        auto command = m_cli_parser->parse({argv + 1, argv + argc});
        auto result = command->run(m_storage);
        return result;
    }
    catch (std::runtime_error& e)
    {
        m_out << e.what() << std::endl;
    };
    return 1;
};

void ElementaryVM::setOut(std::ostream& out) { m_out.rdbuf(out.rdbuf()); };

}  // namespace elemvm
