#pragma once
#include <memory>
#include <string_view>
#include <vector>

#include "command.hpp"
namespace elemvm
{
namespace parsing
{

class IParser
{
public:
    virtual std::unique_ptr<ICommand> parse(std::vector<std::string_view> args) const = 0;
    virtual ~IParser() = default;
};

}  // namespace parsing
}  // namespace elemvm
