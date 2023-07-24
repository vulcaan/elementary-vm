#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "command.hpp"
#include "console_reader.hpp"
#include "file_reader.hpp"
#include "instruction_tokenizer.hpp"
#include "ioperand.hpp"
#include "parser.hpp"

namespace elemvm
{
namespace parsing
{
namespace cli
{
class HelpCommand : public ICommand
{
public:
    HelpCommand()
        : m_out(std::cout){};
    void setOut(std::ostream& out);
    virtual bool run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const override;

private:
    std::ostream& m_out;
};

class InputFromFileCommand : public ICommand
{
public:
    InputFromFileCommand(std::string path);
    virtual bool run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const override;
    void setReader(std::unique_ptr<reading::IReader> reader);
    void setTokenizer(
        std::unique_ptr<instructions::InstructionTokenizer> tokenizer);
    void setInstrParser(std::unique_ptr<instructions::IParser> instrParser);

private:
    std::unique_ptr<reading::IReader> m_reader;
    std::string m_path;
    std::unique_ptr<instructions::IParser> m_instr_parser;
    std::unique_ptr<instructions::ITokenizer> m_tokenizer;
};

class InputInteractCommand : public ICommand
{
public:
    InputInteractCommand();
    virtual bool run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const override;

    void setReader(std::unique_ptr<reading::IReader> reader);
    void setTokenizer(
        std::unique_ptr<instructions::InstructionTokenizer> tokenizer);
    void setInstrParser(std::unique_ptr<instructions::IParser> instrParser);

private:
    std::unique_ptr<instructions::IParser> m_instr_parser;
    std::unique_ptr<reading::IReader> m_reader;
    std::unique_ptr<instructions::ITokenizer> m_tokenizer;
};

}  // namespace cli
}  // namespace parsing
}  // namespace elemvm
