#pragma once
#include "operand_wrapper.hpp"
namespace elemvm
{
namespace operands
{
class Float64 : public OperandWrapper<Float64, double, IFloat>
{
public:
    using OperandWrapper::OperandWrapper;
    eOperandType getType() const override;
    int getPrecision() const override;
    double getValue() const override;
};

}  // namespace operands
}  // namespace elemvm