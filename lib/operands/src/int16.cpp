#include "int16.hpp"

#include <iostream>
namespace elemvm
{
namespace operands
{
int Int16::getPrecision() const { return static_cast<int>(getType()); }

eOperandType Int16::getType() const { return eOperandType::Int16; }

int64_t Int16::getValue() const { return m_value; }

}  // namespace operands
}  // namespace elemvm