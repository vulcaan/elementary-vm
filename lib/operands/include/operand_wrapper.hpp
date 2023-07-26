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
template <eOperandType eNumType, class DataType, class Category, class Float = void>
class Operand;
template <eOperandType eNumType, class DataType, class Category>
class _OperandWrapper : public Category
{
public:
    _OperandWrapper(DataType value = 0)
        : m_value{value}
    {
        m_str_value = std::to_string(m_value);
    }

    eOperandType getType() const override
    {
        return eNumType;
    }

    int getPrecision() const override
    {
        return static_cast<int>(getType());
    }

    const IOperand* operator+(const IOperand& rhs) const override
    {
        if (this->getType() >= rhs.getType())
        {
            auto rhs_value = (rhs.getType() >= eOperandType::Float32
                                  ? static_cast<const IFloat&>(rhs).getValue()
                                  : static_cast<const IInteger&>(rhs).getValue());
            if ((rhs_value >= 0 && m_value > ((int)std::numeric_limits<DataType>::max() - rhs_value))
                || (rhs_value < 0 && m_value < ((int)std::numeric_limits<DataType>::lowest() - rhs_value)))
            {
                throw std::runtime_error("[ERROR] Data type overflow detected!");
            }
            return new Operand<eNumType, DataType, Category>(m_value + rhs_value);
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
            auto rhs_value = (rhs.getType() >= eOperandType::Float32
                                  ? static_cast<const IFloat&>(rhs).getValue()
                                  : static_cast<const IInteger&>(rhs).getValue());

            if ((rhs_value >= 0 && m_value < std::numeric_limits<DataType>::lowest() + rhs_value)
                || (rhs_value < 0 && m_value > std::numeric_limits<DataType>::max() + rhs_value))
            {
                throw std::runtime_error("[ERROR] Data type overflow detected!");
            }

            return new Operand<eNumType, DataType, Category>(m_value - rhs_value);
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
            auto rhs_value = (rhs.getType() >= eOperandType::Float32
                                  ? static_cast<const IFloat&>(rhs).getValue()
                                  : static_cast<const IInteger&>(rhs).getValue());

            if ((rhs_value > 0 && m_value > std::numeric_limits<DataType>::max() / rhs_value)
                || (rhs_value < 0 && m_value < std::numeric_limits<DataType>::lowest() / rhs_value))
            {
                throw std::runtime_error("[ERROR] Data type overflow detected!");
            }

            return new Operand<eNumType, DataType, Category>(m_value * rhs_value);
        }
        else
        {
            return rhs * *this;
        }
    }

    const IOperand* operator/(const IOperand& rhs) const override
    {
        if (this->getType() >= rhs.getType())
        {
            auto rhs_value = (rhs.getType() >= eOperandType::Float32
                                  ? static_cast<const IFloat&>(rhs).getValue()
                                  : static_cast<const IInteger&>(rhs).getValue());
            if (rhs_value == 0)
            {
                throw std::runtime_error("[ERROR] Division by zero detected!");
            }
            if (m_value == std::numeric_limits<DataType>::lowest() && rhs_value == -1)
            {
                throw std::runtime_error("[ERROR] Data type overflow detected!");
            }

            return new Operand<eNumType, DataType, Category>(m_value / rhs_value);
        }
        else
        {
            return rhs / *this;
        }
    };

    bool operator==(const IOperand& rhs) const override
    {
        auto rhs_value = (rhs.getType() >= eOperandType::Float32
                              ? static_cast<const IFloat&>(rhs).getValue()
                              : static_cast<const IInteger&>(rhs).getValue());
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
};

template <eOperandType eNumType, class DataType, class Category>
class Operand<eNumType,
              DataType,
              Category,
              typename std::enable_if<!std::is_same<IInteger, Category>::value>::type> : public _OperandWrapper<eNumType, DataType, Category>
{
public:
    using _OperandWrapper<eNumType, DataType, Category>::_OperandWrapper;

    const IOperand* operator%(const IOperand&) const override
    {
        throw std::runtime_error("[ERROR] Modulus for Float types isn't allowed!");
    }
    double getValue() const override
    {
        return this->m_value;
    }
};

template <eOperandType eNumType, class DataType, class Category>
class Operand<eNumType,
              DataType,
              Category,
              typename std::enable_if<std::is_same<IInteger, Category>::value>::type> : public _OperandWrapper<eNumType, DataType, Category>
{
public:
    using _OperandWrapper<eNumType, DataType, Category>::_OperandWrapper;

    const IOperand* operator%(const IOperand& rhs) const override
    {
        if (this->getType() >= rhs.getType() && rhs.getType() < eOperandType::Float32)
        {
            auto rhs_value = static_cast<const IInteger&>(rhs).getValue();
            if (rhs_value == 0
                || (this->m_value == std::numeric_limits<DataType>::lowest() && rhs_value == -1))
            {
                throw std::runtime_error("[ERROR] Data type overflow detected!");
            }

            return new Operand<eNumType, DataType, Category>(this->m_value % rhs_value);
        }
        else
        {
            return rhs % *this;
        }
    }

    int64_t getValue() const override
    {
        return this->m_value;
    }
};

}  // namespace operands
}  // namespace elemvm