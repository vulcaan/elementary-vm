#pragma once
#include "ioperand.hpp"

namespace elemvm
{
namespace operands
{
class IFloat : public IOperand
{
public:
    virtual double getValue() const = 0;
    virtual ~IFloat() {};
};
}  // namespace operands
}  // namespace elemvm
