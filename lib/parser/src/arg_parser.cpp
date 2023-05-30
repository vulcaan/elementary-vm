#include "arg_parser.hpp"

namespace elemvm
{
namespace argparser
{

CLICommand CLIParser::parse(int argc, char* argv[]) const
{
    switch (argc)
    {
    case 2:
        if (m_helpCommandParser->parse(argv[1]))
        {
            return CLICommand::HelpCommand;
        }
        if (m_inputFromFileCommandParser->parse(argv[1]))
        {
            return CLICommand::InputFromFileCommand;
        }
        break;
    case 3:
        if (m_inputFromFileCommandParser->parse(argv[1]))
        {
            return CLICommand::InputFromFileCommand;
        }
        break;
    default:
        return CLICommand::IncorrectCommand;
    }
    return CLICommand::IncorrectCommand;
}
}  // namespace argparser
}  // namespace elemvm
