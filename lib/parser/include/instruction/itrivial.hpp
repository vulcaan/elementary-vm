#ifndef ELEMVM_PARSER_INSTRUCTION_ITRIVIAL_HPP
#define ELEMVM_PARSER_INSTRUCTION_ITRIVIAL_HPP

#include <memory>
#include <stack>

#include "instruction/icommand.hpp"
namespace elemvm
{
namespace parsing
{
namespace instructions
{
class ITrivial : public ICommand
{
public:
    virtual eInstrResult run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const = 0;
};

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
#endif  // ELEMVM_PARSER_INSTRUCTION_ITRIVIAL_HPP
