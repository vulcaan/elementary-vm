#ifndef ELEMVM_PARSER_INSTRUCTION_ICOMMAND_HPP
#define ELEMVM_PARSER_INSTRUCTION_ICOMMAND_HPP

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
#endif  // ELEMVM_PARSER_INSTRUCTION_ICOMMAND_HPP
