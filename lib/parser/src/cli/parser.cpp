#include "cli/parser.hpp"

#include <stdexcept>

#include "cli/commands.hpp"
#include "cli/icommand.hpp"
#include "cli/iparser.hpp"
#include "instruction/iparser.hpp"
#include "ireader.hpp"

namespace elemvm
{
namespace parsing
{
namespace cli
{
bool Parser::addSubparser(const std::string& command,
                          eCommand command_type) noexcept
{
    if (!command.empty())
    {
        if (m_stringToCommand.find(command) == m_stringToCommand.end())
        {
            m_stringToCommand[command] = command_type;
            if (m_commandToParser.find(command_type) == m_commandToParser.end())
            {
                auto parser = createSubParser(command_type);
                if (parser == nullptr)
                {
                    return false;
                }
                m_commandToParser[command_type] = std::move(parser);
            }
            return true;
        }
        return true;
    }
    return false;
}

std::unique_ptr<IParser> Parser::createSubParser(const eCommand& command_type) const
{
    switch (command_type)
    {
    case eCommand::HELP:
        return std::make_unique<HelpParser>();
    case eCommand::INPUT_FILE:
        return std::make_unique<InputFromFileParser>();
    case eCommand::INPUT_INTERACT:
        return std::make_unique<InputInteractParser>();
    }
    return nullptr;
}

Parser::~Parser() = default;

std::unique_ptr<ICommand> Parser::parse(const std::vector<std::string>& args) const
{
    if (!args.empty() && m_stringToCommand.find(args[0]) != m_stringToCommand.end())
    {
        return m_commandToParser.at(m_stringToCommand.at(args[0]))->parse({std::begin(args) + 1, std::end(args)});
    }
    throw std::runtime_error("[ERROR] Unknown command, use --help or -h.");
}

std::unique_ptr<ICommand> HelpParser::parse(const std::vector<std::string>& args) const
{
    if (args.size() == 0)
    {
        return std::make_unique<HelpCommand>();
    }
    throw std::runtime_error("[ERROR] Wrong Help Command usage.");
}

std::unique_ptr<ICommand> InputInteractParser::parse(const std::vector<std::string>& args) const
{
    if (args.size() == 0)
    {
        return std::make_unique<InputInteractCommand>();
    }
    throw std::runtime_error("[ERROR] Wrong Input Interact Command usage.");
}

std::unique_ptr<ICommand> InputFromFileParser::parse(const std::vector<std::string>& args) const
{
    if (args.size() == 1)
    {
        return std::make_unique<InputFromFileCommand>(args[0]);
    }
    throw std::runtime_error("[ERROR] Wrong Input From File Command usage.");
}

}  // namespace cli
}  // namespace parsing
}  // namespace elemvm
