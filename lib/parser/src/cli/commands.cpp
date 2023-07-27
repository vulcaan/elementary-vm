#include "cli/commands.hpp"

#include <stdexcept>

#include "instruction/parser.hpp"
namespace elemvm
{
namespace parsing
{
namespace cli
{
void HelpCommand::setOut(std::ostream& out) { m_out.rdbuf(out.rdbuf()); };

bool HelpCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>) const
{
    if (m_out)
    {
        m_out << "Elementary VM "
              << "[options]" << std::endl
              << "Options:" << std::endl
              << "-h                    Print this help" << std::endl
              << "-i                    Get commands from a console (## to end)" << std::endl
              << "-f <path-to-file>     Get commands from a file" << std::endl;
        return true;
    }
    return false;
};

bool InputFromFileCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
        storage) const
{
    // TODO(1): Fix workaround with unused iostream argument.
    //       Now used only path variable that is passed via FileReader Ctor.
    //       The fix might be like the following:
    //       1) Unbind FileReader and ConsoleReader from
    //          the same interface (testing via mocks and shared ptrs);
    //       2) Create interface which be useful for both Readers.
    //
    //       Also this method may be unified with InteractiveInput.
    auto lines = m_reader->read(std::cin);
    std::uint16_t lineCounter = 0;
    instructions::eInstrResult instr_result;
    for (const auto& line : lines)
    {
        lineCounter++;
        try
        {
            auto command = m_instr_parser->parse(line);
            if (command == nullptr)
            {
                continue;
            }
            instr_result = command->run(storage);
            // TODO(2): Fix mixing return codes with exceptions.
            if (instr_result == instructions::eInstrResult::ERROR)
                return false;
            if (instr_result == instructions::eInstrResult::END)
                break;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Error at line: " << lineCounter << '\n'
                      << ex.what() << std::endl;
            return false;
        }
    }
    if (instr_result != instructions::eInstrResult::END)
    {
        throw std::runtime_error("[ERROR] End instruction wasn't passed.");
    }
    return true;
};

InputFromFileCommand::InputFromFileCommand(std::string path)
    // TODO(1): Fix workaround with unused iostream argument.
    : m_reader(std::make_unique<reading::FileReader>(path))
    , m_path(path)
    , m_instr_parser(std::make_unique<instructions::Parser>()){};

void InputFromFileCommand::setReader(std::unique_ptr<reading::IReader> reader)
{
    m_reader = std::move(reader);
};

void InputFromFileCommand::setInstrParser(
    std::unique_ptr<instructions::IParser> instrParser)
{
    m_instr_parser = std::move(instrParser);
};

void InputInteractCommand::setReader(std::unique_ptr<reading::IReader> reader)
{
    m_reader = std::move(reader);
};

void InputInteractCommand::setInstrParser(
    std::unique_ptr<instructions::IParser> instrParser)
{
    m_instr_parser = std::move(instrParser);
}

InputInteractCommand::InputInteractCommand()
    : m_reader(std::make_unique<reading::ConsoleReader>())
    , m_instr_parser(std::make_unique<instructions::Parser>()){};

bool InputInteractCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
        storage) const
{
    auto lines = m_reader->read(std::cin);
    std::uint16_t lineCounter = 0;
    instructions::eInstrResult instr_result;
    for (const auto& line : lines)
    {
        lineCounter++;
        try
        {
            auto command = m_instr_parser->parse(line);
            if (command == nullptr)
                continue;
            instr_result = command->run(storage);
            // TODO(2): Fix mixing return codes with exceptions.
            if (instr_result == instructions::eInstrResult::ERROR)
                return false;
            if (instr_result == instructions::eInstrResult::END)
                break;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Error at line: " << lineCounter << '\n'
                      << ex.what() << std::endl;
            return false;
        }
    }
    if (instr_result != instructions::eInstrResult::END)
    {
        throw std::runtime_error("[ERROR] End instruction wasn't passed.");
    }
    return true;
};
}  // namespace cli
}  // namespace parsing
}  // namespace elemvm
