#pragma once
#include "operand_wrapper.hpp"
namespace elemvm
{
namespace operands
{
class Int64 : public OperandWrapper<Int64, long long, IInteger>
{
public:
    using OperandWrapper::OperandWrapper;
    eOperandType getType() const override;
    int getPrecision() const override;
    int64_t getValue() const override;
};

}  // namespace operands
}  // namespace elemvm