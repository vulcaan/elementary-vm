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
namespace cli
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

class HelpParser : public IParser
{
public:
    virtual std::unique_ptr<ICommand> parse(
        const std::vector<std::string>& args) const override;
};

class InputInteractParser : public IParser
{
public:
    virtual std::unique_ptr<ICommand> parse(
        const std::vector<std::string>& args) const override;
};

class InputFromFileParser : public IParser
{
public:
    virtual std::unique_ptr<ICommand> parse(
        const std::vector<std::string>& args) const override;
};

}  // namespace cli
}  // namespace parsing
}  // namespace elemvm
