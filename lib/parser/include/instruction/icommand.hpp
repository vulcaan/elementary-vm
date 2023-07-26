#pragma once
#include <memory>
#include <stack>

#include "ioperand.hpp"
namespace elemvm
{
namespace parsing
{
namespace instructions
{
enum class InstrResult
{
    SUCCESS,
    END,
    ERROR
};
class ICommand
{
public:
    virtual InstrResult run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const = 0;
    virtual ~ICommand(){};
};

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
