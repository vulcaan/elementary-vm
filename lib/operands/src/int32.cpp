#include "int32.hpp"

#include <iostream>
namespace elemvm
{
namespace operands
{
int Int32::getPrecision() const { return static_cast<int>(getType()); }

eOperandType Int32::getType() const { return eOperandType::Int32; }

int64_t Int32::getValue() const { return m_value; }

}  // namespace operands
}  // namespace elemvm