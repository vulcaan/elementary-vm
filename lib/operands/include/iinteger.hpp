#pragma once
#include "ioperand.hpp"

namespace elemvm
{
namespace operands
{
class IInteger : public IOperand
{
public:
    virtual int64_t getValue() const = 0;
    virtual ~IInteger() {};
};
}  // namespace operands
}  // namespace elemvm
