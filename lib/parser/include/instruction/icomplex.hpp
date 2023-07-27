#pragma once
#include <memory>
#include <stack>

#include "instruction/icommand.hpp"
namespace elemvm
{
namespace parsing
{
namespace instructions
{
class IComplex : public ICommand
{
public:
    IComplex(std::shared_ptr<const operands::IOperand> value)
        : m_operand(value){};
    virtual eInstrResult run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const = 0;

protected:
    std::shared_ptr<const operands::IOperand> m_operand;
};

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
