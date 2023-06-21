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
    throw std::runtime_error("Unknown Instruction.");
};

std::unique_ptr<ICommand> AddParser::parse(
    const std::vector<std::string>& args) const
{
    if (args.size() == 0)
    {
        return std::make_unique<AddCommand>();
    }
    throw std::runtime_error("Wrong Add Instruction usage.");
};

std::unique_ptr<ICommand> PutParser::parse(
    const std::vector<std::string>& args) const
{
    if (args.size() == 1)
    {
        return std::make_unique<PutCommand>(std::stoi(args[0].data()));
    }
    throw std::runtime_error("Wrong Put Instruction usage.");
};

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
