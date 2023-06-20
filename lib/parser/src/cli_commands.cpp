#include "cli_commands.hpp"

#include "instruction_parser.hpp"

namespace elemvm
{
namespace parsing
{
namespace cli
{
void HelpCommand::setOut(std::ostream& out) { m_out.rdbuf(out.rdbuf()); };

bool HelpCommand::run(std::shared_ptr<std::stack<int>> storage) const
{
    if (m_out)
    {
        m_out << "Elementary VM "
              << "[options]" << std::endl
              << "Options:" << std::endl
              << "-h                    Print this help" << std::endl
              << "-i                    Get commands from a console (## to end)"
              << std::endl
              << "-f <path-to-file>     Get commands from a file" << std::endl;
        return true;
    }
    return false;
};

bool InputFromFileCommand::run(std::shared_ptr<std::stack<int>> storage) const
{
    std::cout << "[InputFromFileCommand::run] Start";
    return true;
};

void InputInteractCommand::setReader(std::unique_ptr<reading::IReader> reader)
{
    m_reader = std::move(reader);
};
void InputInteractCommand::setTokenizer(
    std::unique_ptr<instructions::InstructionTokenizer> tokenizer)
{
    m_tokenizer = std::move(tokenizer);
};
InputInteractCommand::InputInteractCommand()
    : m_reader(std::make_unique<reading::ConsoleReader>())
    , m_tokenizer(std::make_unique<instructions::InstructionTokenizer>())
{
    auto instr_parser = std::make_unique<instructions::Parser>();
    instr_parser->addSubparser(std::string("add"),
                               std::make_unique<instructions::AddParser>());
    m_instr_parser = std::move(instr_parser);
};
bool InputInteractCommand::run(std::shared_ptr<std::stack<int>> storage) const
{
    std::cout << "[InputInteractCommand::run] Start\n";
    auto lines = m_reader->read(std::cin);
    std::uint16_t lineCounter = 1;
    for (const auto& line : lines)
    {
        try
        {
            auto command = m_instr_parser->parse(m_tokenizer->tokenize(line));
            command->run(storage);
        }
        catch (const std::exception& ex)
        {
            std::cout << "Error at line: " << lineCounter << '\n'
                      << ex.what() << std::endl;
            return false;
        }
    }

    return true;
};
}  // namespace cli
}  // namespace parsing
}  // namespace elemvm
