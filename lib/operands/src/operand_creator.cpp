#include "operand_creator.hpp"

#include <stdexcept>

#include "ioperand.hpp"
#include "operand_wrapper.hpp"

namespace elemvm
{
namespace operands
{
Creator::Creator()
{
    m_creators = {
        [this](const std::string& value) { return this->createInt8(value); },
        [this](const std::string& value) { return this->createInt16(value); },
        [this](const std::string& value) { return this->createInt32(value); },
        [this](const std::string& value) { return this->createInt64(value); },
        // [this](const std::string& value) { return this->createInt128(value); },
        [this](const std::string& value) { return this->createFloat32(value); },
        [this](const std::string& value) { return this->createFloat64(value); },
    };
}

const IOperand* Creator::createOperand(eOperandType type,
                                       const std::string& value) const
{
    return m_creators[static_cast<int>(type)](value);
}

const IOperand* Creator::createInt8(const std::string& value) const
{
    long long num_value;
    try
    {
        num_value = std::stoll(value);
    }
    catch (const std::out_of_range&)
    {
        throw std::runtime_error("[ERROR] stoll: Data overflow!");
    }
    if (checkOverflow<char>(num_value))
    {
        throw std::runtime_error("[ERROR] Data overflow!");
    }
    return new Operand<eOperandType::Int8, char, IInteger>(num_value);
}

const IOperand* Creator::createInt16(const std::string& value) const
{
    long long num_value;
    try
    {
        num_value = std::stoll(value);
    }
    catch (const std::out_of_range&)
    {
        throw std::runtime_error("[ERROR] stoll: Data overflow!");
    }
    if (checkOverflow<short>(num_value))
    {
        throw std::runtime_error("[ERROR] Data overflow!");
    }
    return new Operand<eOperandType::Int16, short, IInteger>(num_value);
}

const IOperand* Creator::createInt32(const std::string& value) const
{
    long long num_value;
    try
    {
        num_value = std::stoll(value);
    }
    catch (const std::out_of_range&)
    {
        throw std::runtime_error("[ERROR] stoll: Data overflow!");
    }
    if (checkOverflow<int>(num_value))
    {
        throw std::runtime_error("[ERROR] Data overflow!");
    }
    return new Operand<eOperandType::Int32, int, IInteger>(num_value);
}

const IOperand* Creator::createInt64(const std::string& value) const
{
    long long num_value;
    try
    {
        num_value = std::stoll(value);
    }
    catch (const std::out_of_range&)
    {
        throw std::runtime_error("[ERROR] stoll: Data overflow!");
    }
    if (checkOverflow<long long>(num_value))
    {
        throw std::runtime_error("[ERROR] Data overflow!");
    }
    return new Operand<eOperandType::Int64, long long, IInteger>(num_value);
}

const IOperand* Creator::createFloat32(const std::string& value) const
{
    double num_value;
    try
    {
        num_value = std::stod(value);
    }
    catch (const std::out_of_range&)
    {
        throw std::runtime_error("[ERROR] stod: Data overflow!");
    }
    if (checkOverflow<float>(num_value))
    {
        throw std::runtime_error("[ERROR] Data overflow!");
    }
    return new Operand<eOperandType::Float32, float, IFloat>(num_value);
}

const IOperand* Creator::createFloat64(const std::string& value) const
{
    double num_value;
    try
    {
        num_value = std::stod(value);
    }
    catch (const std::out_of_range&)
    {
        throw std::runtime_error("[ERROR] stod: Data overflow!");
    }
    if (checkOverflow<double>(num_value))
    {
        throw std::runtime_error("[ERROR] Data overflow!");
    }
    return new Operand<eOperandType::Float64, double, IFloat>(num_value);
}

}  // namespace operands
}  // namespace elemvm