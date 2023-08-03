#ifndef ELEMVM_LIB_PARSER_INCLUDE_INSTRUCTION_ITRIVIAL_HPP_
#define ELEMVM_LIB_PARSER_INCLUDE_INSTRUCTION_ITRIVIAL_HPP_

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
#endif  // ELEMVM_LIB_PARSER_INCLUDE_INSTRUCTION_ITRIVIAL_HPP_
