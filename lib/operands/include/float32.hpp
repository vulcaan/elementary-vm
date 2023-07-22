#pragma once
#include "operand_wrapper.hpp"
namespace elemvm
{
namespace operands
{
class Float32 : public OperandWrapper<Float32, float, IFloat>
{
public:
    using OperandWrapper::OperandWrapper;
    eOperandType getType() const override;
    int getPrecision() const override;
    double getValue() const override;
};

}  // namespace operands
}  // namespace elemvm