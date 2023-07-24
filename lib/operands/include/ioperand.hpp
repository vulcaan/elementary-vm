#pragma once
#include <memory>
#include <string>

namespace elemvm
{
namespace operands
{
enum class eOperandType : int
{
    Int8 = 0,
    Int16,
    Int32,
    Int64,
    // Int128,
    Float32,
    Float64
};
class IOperand
{
public:
    virtual int getPrecision() const = 0;
    virtual eOperandType getType() const = 0;
    virtual const IOperand* operator+(const IOperand& rhs) const = 0;
    virtual const IOperand* operator-(const IOperand& rhs) const = 0;
    virtual const IOperand* operator*(const IOperand& rhs) const = 0;
    virtual const IOperand* operator/(const IOperand& rhs) const = 0;
    // virtual const IOperand* operator%(const IOperand& rhs) const = 0;
    virtual bool operator==(const IOperand& rhs) const = 0;
    virtual bool operator!=(const IOperand& rhs) const = 0;
    virtual const std::string& toString() const = 0;
    virtual ~IOperand() {}
};
}  // namespace operands
}  // namespace elemvm
