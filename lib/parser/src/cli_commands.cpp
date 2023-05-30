#include "cli_commands.hpp"

namespace elemvm
{
namespace argparser
{
bool HelpCommandParser::parse(std::string_view command) const
{
    if (command == "-h" || command == "--help")
    {
        return true;
    }
    return false;
}
bool InputInteractiveCommandParser::parse(std::string_view command) const
{
    if (command == "-i")
    {
        return true;
    }
    return false;
}
bool InputFromFileCommand::parse(std::string_view command) const
{
    if (command == "-f")
    {
        return true;
    }
    return false;
}
}  // namespace argparser
}  // namespace elemvm
