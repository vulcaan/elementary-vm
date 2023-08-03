#ifndef ELEMVM_LIB_OPERANDS_INCLUDE_WRAPPER_HPP_
#define ELEMVM_LIB_OPERANDS_INCLUDE_WRAPPER_HPP_

#include <iostream>
#include <limits>
#include <memory>
#include <stdexcept>
#include <string>

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
    _OperandWrapper(DataType value = 0);
    eOperandType getType() const override;
    int getPrecision() const override;
    const IOperand* operator+(const IOperand& rhs) const override;
    const IOperand* operator-(const IOperand& rhs) const override;
    const IOperand* operator*(const IOperand& rhs) const override;
    const IOperand* operator/(const IOperand& rhs) const override;
    bool operator==(const IOperand& rhs) const override;
    bool operator!=(const IOperand& rhs) const override;
    const std::string& toString() const override;

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

    const IOperand* operator%(const IOperand&) const override;
    double getValue() const override;
};

template <eOperandType eNumType, class DataType, class Category>
class Operand<eNumType,
              DataType,
              Category,
              typename std::enable_if<std::is_same<IInteger, Category>::value>::type> : public _OperandWrapper<eNumType, DataType, Category>
{
public:
    using _OperandWrapper<eNumType, DataType, Category>::_OperandWrapper;

    const IOperand* operator%(const IOperand& rhs) const override;
    int64_t getValue() const override;
};

template <class DataType>
std::unique_ptr<const IOperand> upCast(eOperandType type, DataType value)
{
    using ptr = std::unique_ptr<const IOperand>;
    switch (type)
    {
    case eOperandType::Int8:
        return ptr{new Operand<eOperandType::Int8, char, IInteger>(value)};
    case eOperandType::Int16:
        return ptr{new Operand<eOperandType::Int16, short, IInteger>(value)};
    case eOperandType::Int32:
        return ptr{new Operand<eOperandType::Int32, int, IInteger>(value)};
    case eOperandType::Int64:
        return ptr{new Operand<eOperandType::Int64, long long, IInteger>(value)};
    case eOperandType::Float32:
        return ptr{new Operand<eOperandType::Float32, float, IFloat>(value)};
    case eOperandType::Float64:
        return ptr{new Operand<eOperandType::Float64, double, IFloat>(value)};

    default:
        throw std::logic_error("Unknown operand type passed while upcasting!");
    };
}

template <eOperandType eNumType, class DataType, class Category>
_OperandWrapper<eNumType, DataType, Category>::_OperandWrapper(DataType value)
    : m_value{value}
{
    m_str_value = std::to_string(m_value);
}

template <eOperandType eNumType, class DataType, class Category>
eOperandType _OperandWrapper<eNumType, DataType, Category>::getType() const
{
    return eNumType;
}

template <eOperandType eNumType, class DataType, class Category>
int _OperandWrapper<eNumType, DataType, Category>::getPrecision() const
{
    return static_cast<int>(getType());
}

template <eOperandType eNumType, class DataType, class Category>
const IOperand* _OperandWrapper<eNumType, DataType, Category>::operator+(const IOperand& rhs) const
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

template <eOperandType eNumType, class DataType, class Category>
const IOperand* _OperandWrapper<eNumType, DataType, Category>::operator-(const IOperand& rhs) const
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
        return *upCast(rhs.getType(), m_value) - rhs;
    }
}

template <eOperandType eNumType, class DataType, class Category>
const IOperand* _OperandWrapper<eNumType, DataType, Category>::operator*(const IOperand& rhs) const
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

template <eOperandType eNumType, class DataType, class Category>
const IOperand* _OperandWrapper<eNumType, DataType, Category>::operator/(const IOperand& rhs) const
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
        return *upCast(rhs.getType(), m_value) / rhs;
    }
};

template <eOperandType eNumType, class DataType, class Category>
bool _OperandWrapper<eNumType, DataType, Category>::operator==(const IOperand& rhs) const
{
    auto rhs_value = (rhs.getType() >= eOperandType::Float32
                          ? static_cast<const IFloat&>(rhs).getValue()
                          : static_cast<const IInteger&>(rhs).getValue());
    return this->m_value == rhs_value;
};

template <eOperandType eNumType, class DataType, class Category>
bool _OperandWrapper<eNumType, DataType, Category>::operator!=(const IOperand& rhs) const
{
    return !(*this == rhs);
};

template <eOperandType eNumType, class DataType, class Category>
const std::string& _OperandWrapper<eNumType, DataType, Category>::toString() const
{
    return m_str_value;
}

template <eOperandType eNumType, class DataType, class Category>
const IOperand* Operand<eNumType,
                        DataType,
                        Category,
                        typename std::enable_if<!std::is_same<IInteger, Category>::value>::type>::operator%(const IOperand&) const
{
    throw std::runtime_error("[ERROR] Modulus for Float types isn't allowed!");
}

template <eOperandType eNumType, class DataType, class Category>
double Operand<eNumType,
               DataType,
               Category,
               typename std::enable_if<!std::is_same<IInteger, Category>::value>::type>::getValue() const
{
    return this->m_value;
}

template <eOperandType eNumType, class DataType, class Category>
const IOperand* Operand<eNumType,
                        DataType,
                        Category,
                        typename std::enable_if<std::is_same<IInteger, Category>::value>::type>::operator%(const IOperand& rhs) const
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
        return *upCast(rhs.getType(), this->m_value) % rhs;
    }
}

template <eOperandType eNumType, class DataType, class Category>
int64_t Operand<eNumType,
                DataType,
                Category,
                typename std::enable_if<std::is_same<IInteger, Category>::value>::type>::getValue() const
{
    return this->m_value;
}

}  // namespace operands
}  // namespace elemvm
#endif  // ELEMVM_LIB_OPERANDS_INCLUDE_WRAPPER_HPP_
