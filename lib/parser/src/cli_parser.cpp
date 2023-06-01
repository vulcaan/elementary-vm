#include "cli_parser.hpp"

#include <memory>

#include "cli_commands.hpp"

namespace elemvm
{
namespace parsing
{
namespace cli
{

bool Parser::addSubparser(std::string_view command,
                          std::unique_ptr<IParser> parser)
{
    if (parser && !command.empty())
    {
        m_commandsMap[command] = std::move(parser);
        return true;
    }
    return false;
}
std::unique_ptr<ICommand> Parser::parse(
    std::vector<std::string_view> args) const
{
    if (m_commandsMap.find(args[0]) != m_commandsMap.end())
    {
        return m_commandsMap.at(args[0])->parse(
            {std::begin(args) + 1, std::end(args)});
    }
    throw std::runtime_error("Unknown command.");
}

std::unique_ptr<ICommand> HelpParser::parse(
    std::vector<std::string_view> args) const
{
    if (args.size() == 1)
    {
        return std::make_unique<HelpCommand>();
    }
    throw std::runtime_error("Wrong Help Command usage.");
}

std::unique_ptr<ICommand> InputInteractParser::parse(
    std::vector<std::string_view> args) const
{
    if (args.size() == 1)
    {
        return std::make_unique<InputInteractiveCommand>();
    }
    throw std::runtime_error("Wrong Input Interact Command usage.");
}

std::unique_ptr<ICommand> InputFromFileParser::parse(
    std::vector<std::string_view> args) const
{
    if (args.size() == 2 && std::filesystem::exists(args[1]))
    {
        return std::make_unique<InputInteractiveCommand>();
    }
    throw std::runtime_error("Wrong Input From File Command usage.");
}

}  // namespace cli
}  // namespace parsing
}  // namespace elemvm
