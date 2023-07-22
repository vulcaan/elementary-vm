#include "cli_commands.hpp"

#include "instruction_parser.hpp"

namespace elemvm
{
namespace parsing
{
namespace cli
{
void HelpCommand::setOut(std::ostream& out) { m_out.rdbuf(out.rdbuf()); };

bool HelpCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
        storage) const
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

std::unique_ptr<instructions::Parser> generateInstrParser()
{
    auto instr_parser = std::make_unique<instructions::Parser>();
    instr_parser->addSubparser(std::string("add"),
                               std::make_unique<instructions::AddParser>());
    instr_parser->addSubparser(std::string("put"),
                               std::make_unique<instructions::PutParser>());
    instr_parser->addSubparser(std::string("sub"),
                               std::make_unique<instructions::SubParser>());
    instr_parser->addSubparser(std::string("assert"),
                               std::make_unique<instructions::AssertParser>());
    instr_parser->addSubparser(std::string("pop"),
                               std::make_unique<instructions::PopParser>());
    instr_parser->addSubparser(std::string("end"),
                               std::make_unique<instructions::EndParser>());
    return instr_parser;
};

bool InputFromFileCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
        storage) const
{
    std::cout << "[InputFromFileCommand::run] Start\n";
    // TODO(1): Fix workaround with unused iostream argument.
    //       Now used only path variable that is passed via FileReader Ctor.
    //       The fix might be like the following:
    //       1) Unbind FileReader and ConsoleReader from
    //          the same interface (testing via mocks and shared ptrs);
    //       2) Create interface which be useful for both Readers.
    //
    //       Also this method may be unified with InteractiveInput.
    auto lines = m_reader->read(std::cin);
    std::uint16_t lineCounter = 1;
    for (const auto& line : lines)
    {
        try
        {
            auto unparsed = m_tokenizer->tokenize(line);
            if (unparsed.empty())
            {
                continue;
            }
            auto command = m_instr_parser->parse(unparsed);
            auto instr_result = command->run(storage);
            // TODO(2): Fix mixing return codes with exceptions.
            if (instr_result == instructions::InstrResult::ERROR)
                return false;
            if (instr_result == instructions::InstrResult::END)
                break;
            lineCounter++;
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

InputFromFileCommand::InputFromFileCommand(std::filesystem::path path)
    // TODO(1): refer to other TODO with the same number
    : m_reader(std::make_unique<reading::FileReader>(path))
    , m_path(path)
    , m_tokenizer(std::make_unique<instructions::InstructionTokenizer>())
{
    m_instr_parser = generateInstrParser();
};

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

void InputInteractCommand::setTokenizer(
    std::unique_ptr<instructions::InstructionTokenizer> tokenizer)
{
    m_tokenizer = std::move(tokenizer);
};

InputInteractCommand::InputInteractCommand()
    : m_reader(std::make_unique<reading::ConsoleReader>())
    , m_tokenizer(std::make_unique<instructions::InstructionTokenizer>())
{
    m_instr_parser = generateInstrParser();
};
bool InputInteractCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
        storage) const
{
    std::cout << "[InputInteractCommand::run] Start\n";
    auto lines = m_reader->read(std::cin);
    std::uint16_t lineCounter = 1;
    for (const auto& line : lines)
    {
        try
        {
            auto unparsed = m_tokenizer->tokenize(line);
            if (unparsed.empty())
            {
                continue;
            }
            auto command = m_instr_parser->parse(unparsed);
            auto instr_result = command->run(storage);
            // TODO(2): Fix mixing return codes with exceptions.
            if (instr_result == instructions::InstrResult::ERROR)
                return false;
            if (instr_result == instructions::InstrResult::END)
                break;
            lineCounter++;
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
