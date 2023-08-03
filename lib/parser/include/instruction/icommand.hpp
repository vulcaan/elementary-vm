#ifndef ELEMVM_LIB_PARSER_INCLUDE_INSTRUCTION_ICOMMAND_HPP_
#define ELEMVM_LIB_PARSER_INCLUDE_INSTRUCTION_ICOMMAND_HPP_

#include <memory>
#include <stack>

namespace elemvm
{
namespace operands
{
class IOperand;
}
namespace parsing
{
namespace instructions
{
enum class eInstrResult : int
{
    SUCCESS = 0,
    END,
    ERROR
};
enum class eInstruction : int
{
    PUT = 0,
    POP,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    END,
    ASSERT,
    PRINT,
    TRACE,
};
class ICommand
{
public:
    virtual eInstrResult run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const = 0;
    virtual ~ICommand(){};
};

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
#endif  // ELEMVM_LIB_PARSER_INCLUDE_INSTRUCTION_ICOMMAND_HPP_
