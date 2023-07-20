#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

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
    bool addSubparser(const std::string & command,
                      std::unique_ptr<IParser> parser) noexcept;
    virtual std::unique_ptr<ICommand> parse(
        const std::vector<std::string>& args) const override;

private:
    std::unordered_map<std::string, std::unique_ptr<IParser>>
        m_commandsMap;
};

class AddParser : public IParser
{
public:
    virtual std::unique_ptr<ICommand> parse(
        const std::vector<std::string>& args) const override;
};

class PutParser : public IParser
{
public:
    virtual std::unique_ptr<ICommand> parse(
        const std::vector<std::string> & args) const override;
};

class SubParser : public IParser
{
public:
    virtual std::unique_ptr<ICommand> parse(
        const std::vector<std::string> & args) const override;
};

class PopParser : public IParser
{
public:
    virtual std::unique_ptr<ICommand> parse(
        const std::vector<std::string> & args) const override;
};

class AssertParser : public IParser
{
public:
    virtual std::unique_ptr<ICommand> parse(
        const std::vector<std::string> & args) const override;
};

class EndParser : public IParser
{
public:
    virtual std::unique_ptr<ICommand> parse(
        const std::vector<std::string> & args) const override;
};

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
