#include "cli_parser.hpp"

#include <iostream>
#include <memory>

#include "cli_commands.hpp"

namespace elemvm
{
namespace parsing
{
namespace cli
{

bool Parser::addSubparser(const std::string & command,
                          std::unique_ptr<IParser> parser) noexcept
{
    if (parser && !command.empty())
    {
        m_commandsMap.emplace(command, std::move(parser));
        return true;
    }
    return false;
}
std::unique_ptr<ICommand> Parser::parse(
    const std::vector<std::string>& args) const
{
    if (!args.empty() && m_commandsMap.find(args[0]) != m_commandsMap.end())
    {
        return m_commandsMap.at(args[0])->parse(
            {std::begin(args) + 1, std::end(args)});
    }
    throw std::runtime_error("Unknown command, use --help or -h.");
}

std::unique_ptr<ICommand> HelpParser::parse(
    const std::vector<std::string>& args) const
{
    if (args.size() == 0)
    {
        return std::make_unique<HelpCommand>();
    }
    throw std::runtime_error("Wrong Help Command usage.");
}

std::unique_ptr<ICommand> InputInteractParser::parse(
    const std::vector<std::string>& args) const
{
    if (args.size() == 0)
    {
        return std::make_unique<InputInteractCommand>();
    }
    throw std::runtime_error("Wrong Input Interact Command usage.");
}

std::unique_ptr<ICommand> InputFromFileParser::parse(
    const std::vector<std::string>& args) const
{
    if (args.size() == 1)
    {
        return std::make_unique<InputFromFileCommand>(args[1]);
    }
    throw std::runtime_error("Wrong Input From File Command usage.");
}

}  // namespace cli
}  // namespace parsing
}  // namespace elemvm
