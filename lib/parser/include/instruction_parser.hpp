#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "operand_parser.hpp"
#include "parser.hpp"

namespace elemvm
{
namespace parsing
{
namespace instructions
{
class Parser : public IParser
{
public:
    bool addSubparser(const std::string& command,
                      std::unique_ptr<IParser> parser) noexcept;
    virtual std::unique_ptr<ICommand> parse(
        const std::vector<std::string>& args) const override;

private:
    std::unordered_map<std::string, std::unique_ptr<IParser>> m_commandsMap;
};

class AddParser : public IParser
{
public:
    virtual std::unique_ptr<ICommand> parse(
        const std::vector<std::string>& args) const override;
};

class MulParser : public IParser
{
public:
    virtual std::unique_ptr<ICommand> parse(
        const std::vector<std::string>& args) const override;
};

class DivParser : public IParser
{
public:
    virtual std::unique_ptr<ICommand> parse(
        const std::vector<std::string>& args) const override;
};
class PutParser : public IParser
{
public:
    PutParser();
    virtual std::unique_ptr<ICommand> parse(
        const std::vector<std::string>& args) const override;
    void setOperandsParser(
        std::shared_ptr<operands::parsing::IParser> op_parser);

private:
    std::shared_ptr<operands::parsing::IParser> m_op_parser;
};

class SubParser : public IParser
{
public:
    virtual std::unique_ptr<ICommand> parse(
        const std::vector<std::string>& args) const override;
};

class PopParser : public IParser
{
public:
    virtual std::unique_ptr<ICommand> parse(
        const std::vector<std::string>& args) const override;
};

class AssertParser : public IParser
{
public:
    AssertParser();
    virtual std::unique_ptr<ICommand> parse(
        const std::vector<std::string>& args) const override;
    void setOperandsParser(
        std::shared_ptr<operands::parsing::IParser> op_parser);

private:
    std::shared_ptr<operands::parsing::IParser> m_op_parser;
};

class EndParser : public IParser
{
public:
    virtual std::unique_ptr<ICommand> parse(
        const std::vector<std::string>& args) const override;
};

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
