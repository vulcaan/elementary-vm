#include "float32.hpp"

#include <iostream>
namespace elemvm
{
namespace operands
{
int Float32::getPrecision() const { return static_cast<int>(getType()); }

eOperandType Float32::getType() const { return eOperandType::Float32; }

double Float32::getValue() const { return m_value; }

}  // namespace operands
}  // namespace elemvm