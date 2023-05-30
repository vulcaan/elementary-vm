#pragma once
#include <memory>
#include <string_view>

#include "cli_commands.hpp"

namespace elemvm
{
namespace argparser
{

enum class CLICommand
{
    HelpCommand,
    InputInteractiveCommand,
    InputFromFileCommand,
    IncorrectCommand,
};

class ICLIParser
{
public:
    virtual CLICommand parse(int argc, char* argv[]) const = 0;
    virtual ~ICLIParser() = default;
};
class CLIParser : public ICLIParser
{
public:
    CLIParser(std::unique_ptr<ICLICommandParser> helpCommandParser,
              std::unique_ptr<ICLICommandParser> inputInteractiveCommandParser,
              std::unique_ptr<ICLICommandParser> inputFromFileCommandParser)
        : m_helpCommandParser(std::move(helpCommandParser))
        , m_inputInteractiveCommandParser(std::move(inputInteractiveCommandParser))
        , m_inputFromFileCommandParser(std::move(inputFromFileCommandParser))
    {
    }

    virtual CLICommand parse(int argc, char* argv[]) const override;

private:
    std::unique_ptr<ICLICommandParser> m_helpCommandParser;
    std::unique_ptr<ICLICommandParser> m_inputInteractiveCommandParser;
    std::unique_ptr<ICLICommandParser> m_inputFromFileCommandParser;
};
}  // namespace argparser

}  // namespace elemvm
