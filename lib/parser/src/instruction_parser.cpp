#include "instruction_parser.hpp"

#include <iostream>
#include <memory>
#include <string>

#include "instruction_commands.hpp"

namespace elemvm
{
namespace parsing
{
namespace instructions
{
bool Parser::addSubparser(const std::string& command,
                          std::unique_ptr<IParser> parser) noexcept
{
    if (parser && !command.empty())
    {
        m_commandsMap.emplace(command, std::move(parser));
        return true;
    }
    return false;
};

std::unique_ptr<ICommand> Parser::parse(
    const std::vector<std::string>& args) const
{
    std::cout << "[InstructionsParser::parse] Start.\n";
    if (!args.empty() && m_commandsMap.find(args[0]) != m_commandsMap.end())
    {
        return m_commandsMap.at(args[0])->parse(
            {std::begin(args) + 1, std::end(args)});
    }
    throw std::runtime_error("[ERROR] Unknown Instruction.");
};

std::unique_ptr<ICommand> AddParser::parse(
    const std::vector<std::string>& args) const
{
    if (args.size() == 0)
    {
        return std::make_unique<AddCommand>();
    }
    throw std::runtime_error("[ERROR] Wrong Add Instruction usage.");
};

std::unique_ptr<ICommand> MulParser::parse(
    const std::vector<std::string>& args) const
{
    if (args.size() == 0)
    {
        return std::make_unique<MulCommand>();
    }
    throw std::runtime_error("[ERROR] Wrong Mul Instruction usage.");
};

std::unique_ptr<ICommand> DivParser::parse(
    const std::vector<std::string>& args) const
{
    if (args.size() == 0)
    {
        return std::make_unique<DivCommand>();
    }
    throw std::runtime_error("[ERROR] Wrong Div Instruction usage.");
};

std::unique_ptr<ICommand> ModParser::parse(
    const std::vector<std::string>& args) const
{
    if (args.size() == 0)
    {
        return std::make_unique<ModCommand>();
    }
    throw std::runtime_error("[ERROR] Wrong Mod Instruction usage.");
};

std::unique_ptr<ICommand> PutParser::parse(
    const std::vector<std::string>& args) const
{
    if (args.size() == 1)
    {
        return std::make_unique<PutCommand>(m_op_parser->parse(args[0]));
    }
    throw std::runtime_error("[ERROR] Wrong Put Instruction usage.");
};

std::unique_ptr<ICommand> AssertParser::parse(
    const std::vector<std::string>& args) const
{
    if (args.size() == 1)
    {
        return std::make_unique<AssertCommand>(m_op_parser->parse(args[0]));
    }
    throw std::runtime_error("[ERROR] Wrong Assert Instruction usage.");
};

std::unique_ptr<ICommand> SubParser::parse(
    const std::vector<std::string>& args) const
{
    if (args.size() == 0)
    {
        return std::make_unique<SubCommand>();
    }
    throw std::runtime_error("[ERROR] Wrong Sub Instruction usage.");
};

std::unique_ptr<ICommand> PopParser::parse(
    const std::vector<std::string>& args) const
{
    if (args.size() == 0)
    {
        return std::make_unique<PopCommand>();
    }
    throw std::runtime_error("[ERROR] Wrong Pop Instruction usage.");
};

std::unique_ptr<ICommand> EndParser::parse(
    const std::vector<std::string>& args) const
{
    if (args.size() == 0)
    {
        return std::make_unique<EndCommand>();
    }
    throw std::runtime_error("[ERROR] Wrong End Instruction usage.");
};

PutParser::PutParser()
    : m_op_parser(std::make_shared<operands::parsing::OperandParser>())
{
}

void PutParser::setOperandsParser(
    std::shared_ptr<operands::parsing::IParser> op_parser)
{
    m_op_parser = op_parser;
}

AssertParser::AssertParser()
    : m_op_parser(std::make_shared<operands::parsing::OperandParser>())
{
}

void AssertParser::setOperandsParser(
    std::shared_ptr<operands::parsing::IParser> op_parser)
{
    m_op_parser = op_parser;
}

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
