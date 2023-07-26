#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "cli/iparser.hpp"

namespace elemvm
{
namespace parsing
{
namespace cli
{
class Parser : public IParser
{
public:
    bool addSubparser(const std::string& command,
                      eCommand command_type) noexcept;
    virtual std::unique_ptr<ICommand> parse(
        const std::vector<std::string>& args) const override;

private:
    std::unique_ptr<IParser> createSubParser(const eCommand & command_type) const;

    std::unordered_map<eCommand, std::unique_ptr<IParser>>
        m_commandToParser;
    std::unordered_map<std::string, eCommand>
        m_stringToCommand;
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
