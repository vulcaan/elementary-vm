#pragma once
#include <memory>
#include <stack>

#include "ioperand.hpp"
namespace elemvm
{
namespace parsing
{
namespace cli
{
class ICommand
{
public:
    virtual bool run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const = 0;
    virtual ~ICommand(){};
};
}  // namespace cli
}  // namespace parsing
}  // namespace elemvm
