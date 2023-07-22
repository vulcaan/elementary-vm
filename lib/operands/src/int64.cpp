#include "int64.hpp"

#include <iostream>
namespace elemvm
{
namespace operands
{
int Int64::getPrecision() const { return static_cast<int>(getType()); }

eOperandType Int64::getType() const { return eOperandType::Int64; }

int64_t Int64::getValue() const { return m_value; }

}  // namespace operands
}  // namespace elemvm