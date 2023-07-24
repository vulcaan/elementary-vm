#pragma once
#include <iostream>
#include <limits>

#include "ifloat.hpp"
#include "iinteger.hpp"
#include "ioperand.hpp"
namespace elemvm
{
namespace operands
{
// Class: actual interface implementation, e.g.: Int8, Int32, Float32, etc.
// DataType: data type of the Class, e.g.: char, int, double, etc.
// Category: either Integer or Float.
template <class Class, class DataType, class Category>
class OperandWrapper : public Category
{
public:
    OperandWrapper(DataType value = 0)
        : m_value{value}
    {
        m_str_value = std::to_string(m_value);
    }

    const IOperand* operator+(const IOperand& rhs) const override
    {
        if (this->getType() >= rhs.getType())
        {
            auto rhs_value = getRhsValue(rhs);
            if ((rhs_value >= 0 && m_value > ((int)std::numeric_limits<DataType>::max() - rhs_value))
                || (rhs_value < 0 && m_value < ((int)std::numeric_limits<DataType>::lowest() - rhs_value)))
            {
                throw std::runtime_error("Data type overflow detected!");
            }
            return new Class(m_value + rhs_value);
        }
        else
        {
            return rhs + *this;
        }
    }

    const IOperand* operator-(const IOperand& rhs) const override
    {
        if (this->getType() >= rhs.getType())
        {
            auto rhs_value = getRhsValue(rhs);

            if ((rhs_value >= 0 && m_value < std::numeric_limits<DataType>::lowest() + rhs_value)
                || (rhs_value < 0 && m_value > std::numeric_limits<DataType>::max() + rhs_value))
            {
                throw std::runtime_error("Data type overflow detected!");
            }

            return new Class(m_value - rhs_value);
        }
        else
        {
            return rhs - *this;
        }
    }

    const IOperand* operator*(const IOperand& rhs) const override
    {
        if (this->getType() >= rhs.getType())
        {
            auto rhs_value = getRhsValue(rhs);

            if ((rhs_value > 0 && m_value > std::numeric_limits<DataType>::max() / rhs_value)
            || (rhs_value < 0 && m_value < std::numeric_limits<DataType>::min() / rhs_value))
            {
                throw std::runtime_error("Data type overflow detected!");
            }

            return new Class(m_value * rhs_value);
        }
        else
        {
            return rhs * *this;
        }
    }

    bool operator==(const IOperand& rhs) const override
    {
        auto rhs_value = getRhsValue(rhs);
        return this->m_value == rhs_value;
    };

    bool operator!=(const IOperand& rhs) const override
    {
        return !(*this == rhs);
    };

    const std::string& toString() const override { return m_str_value; }

protected:
    DataType m_value;
    std::string m_str_value;

private:
    auto getRhsValue(const IOperand& rhs) const
    {
        return (rhs.getType() >= eOperandType::Float32
                    ? static_cast<const IFloat&>(rhs).getValue()
                    : static_cast<const IInteger&>(rhs).getValue());
    }
};

}  // namespace operands
}  // namespace elemvm