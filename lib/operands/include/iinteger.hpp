#ifndef ELEMVM_LIB_OPERANDS_INCLUDE_IINTEGER_HPP_
#define ELEMVM_LIB_OPERANDS_INCLUDE_IINTEGER_HPP_
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
#endif  // ELEMVM_LIB_OPERANDS_INCLUDE_IINTEGER_HPP_
