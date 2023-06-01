#pragma once
#include <memory>
#include <string_view>
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
    bool addSubparser(std::string_view command,
                      std::unique_ptr<IParser> parser) noexcept;
    virtual std::unique_ptr<ICommand> parse(
        std::vector<std::string_view> args) const override ;

private:
    std::unordered_map<std::string_view, std::unique_ptr<IParser>>
        m_commandsMap;
};

class HelpParser : public IParser
{
public:
    virtual std::unique_ptr<ICommand> parse(
        std::vector<std::string_view> args) const override;
};

class InputInteractParser : public IParser
{
public:
    virtual std::unique_ptr<ICommand> parse(
        std::vector<std::string_view> args) const override;
};

class InputFromFileParser : public IParser
{
public:
    virtual std::unique_ptr<ICommand> parse(
        std::vector<std::string_view> args) const override;
};

}  // namespace cli
}  // namespace parsing
}  // namespace elemvm
