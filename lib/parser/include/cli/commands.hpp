#ifndef ELEMVM_LIB_PARSER_CLI_INCLUDE_COMMANDS_HPP_
#define ELEMVM_LIB_PARSER_CLI_INCLUDE_COMMANDS_HPP_

#include <iostream>
#include <memory>
#include <stack>
#include <string>
#include <unordered_map>

#include "cli/icommand.hpp"

namespace elemvm
{
namespace operands
{
class IOperand;
}
namespace reading
{
class IReader;
}
namespace parsing
{
namespace instructions
{
class IParser;
}
namespace cli
{
class HelpCommand : public ICommand
{
public:
    HelpCommand();
    void setOut(std::ostream& out);
    virtual bool run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const override;

private:
    std::ostream& m_out;
};

class InputFromFileCommand : public ICommand
{
public:
    InputFromFileCommand(std::string path);
    virtual bool run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const override;
    void setReader(std::unique_ptr<reading::IReader> reader);
    void setInstrParser(std::unique_ptr<instructions::IParser> instrParser);

private:
    std::unique_ptr<reading::IReader> m_reader;
    std::string m_path;
    std::unique_ptr<instructions::IParser> m_instr_parser;
};

class InputInteractCommand : public ICommand
{
public:
    InputInteractCommand();
    virtual bool run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const override;
    void setReader(std::unique_ptr<reading::IReader> reader);
    void setInstrParser(std::unique_ptr<instructions::IParser> instrParser);

private:
    std::unique_ptr<reading::IReader> m_reader;
    std::unique_ptr<instructions::IParser> m_instr_parser;
};

}  // namespace cli
}  // namespace parsing
}  // namespace elemvm
#endif  // ELEMVM_LIB_PARSER_CLI_INCLUDE_COMMANDS_HPP_
