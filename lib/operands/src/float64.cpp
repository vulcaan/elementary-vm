#include "float64.hpp"

#include <iostream>
namespace elemvm
{
namespace operands
{
int Float64::getPrecision() const { return static_cast<int>(getType()); }

eOperandType Float64::getType() const { return eOperandType::Float64; }

double Float64::getValue() const { return m_value; }

}  // namespace operands
}  // namespace elemvm