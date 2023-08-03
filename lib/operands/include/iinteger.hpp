#ifndef ELEMVM_LIB_OPERANDS_IINTEGER_HPP
#define ELEMVM_LIB_OPERANDS_IINTEGER_HPP
#include "ioperand.hpp"

namespace elemvm
{
namespace operands
{
class IInteger : public IOperand
{
public:
    virtual int64_t getValue() const = 0;
    virtual ~IInteger() = default;
};
}  // namespace operands
}  // namespace elemvm
#endif  // ELEMVM_LIB_OPERANDS_IINTEGER_HPP
