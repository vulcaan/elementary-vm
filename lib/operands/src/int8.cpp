#include <iostream>

#include "int8.hpp"
namespace elemvm
{
namespace operands
{
int Int8::getPrecision() const { return static_cast<int>(getType()); }

eOperandType Int8::getType() const { return eOperandType::Int8; }

int64_t Int8::getValue() const { return m_value; }

}  // namespace operands
}  // namespace elemvm