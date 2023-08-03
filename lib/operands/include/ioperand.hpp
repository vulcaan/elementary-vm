#ifndef ELEMVM_LIB_OPERANDS_INCLUDE_IOPERAND_HPP_
#define ELEMVM_LIB_OPERANDS_INCLUDE_IOPERAND_HPP_
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
    virtual const IOperand* operator%(const IOperand& rhs) const = 0;
    virtual bool operator==(const IOperand& rhs) const = 0;
    virtual bool operator!=(const IOperand& rhs) const = 0;
    virtual const std::string& toString() const = 0;
    virtual ~IOperand() {}
};
}  // namespace operands
}  // namespace elemvm
#endif  // ELEMVM_LIB_OPERANDS_INCLUDE_IOPERAND_HPP_
