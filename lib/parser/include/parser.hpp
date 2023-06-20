#pragma once
#include <memory>
#include <string>
#include <vector>

#include "command.hpp"
namespace elemvm
{
namespace parsing
{
namespace cli
{
class IParser
{
public:
    virtual std::unique_ptr<ICommand> parse(
        const std::vector<std::string>& args) const = 0;
    virtual ~IParser(){};
};
}  // namespace cli

namespace instructions
{
class IParser
{
public:
    virtual std::unique_ptr<ICommand> parse(
        const std::vector<std::string>& args) const = 0;
    virtual ~IParser(){};
};
}  // namespace instructions

}  // namespace parsing
}  // namespace elemvm
