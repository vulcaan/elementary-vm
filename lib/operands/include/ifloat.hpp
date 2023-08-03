#ifndef ELEMVM_LIB_OPERANDS_INCLUDE_IFLOAT_HPP_
#define ELEMVM_LIB_OPERANDS_INCLUDE_IFLOAT_HPP_
#include "ioperand.hpp"

namespace elemvm
{
namespace operands
{
class IFloat : public IOperand
{
public:
    virtual double getValue() const = 0;
    virtual ~IFloat() = default;
};
}  // namespace operands
}  // namespace elemvm
#endif  // ELEMVM_LIB_OPERANDS_INCLUDE_IFLOAT_HPP_
