#ifndef ELEMVM_OPERAND_IINTEGER_HPP
#define ELEMVM_OPERAND_IINTEGER_HPP
#include "ioperand.hpp"

namespace elemvm
{
namespace operands
{
class IInteger : public IOperand
{
public:
    virtual int64_t getValue() const = 0;
    virtual ~IInteger(){};
};
}  // namespace operands
}  // namespace elemvm
#endif  // ELEMVM_OPERAND_IINTEGER_HPP
