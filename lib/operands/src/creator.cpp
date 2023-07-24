#include "creator.hpp"

#include "float32.hpp"
#include "float64.hpp"
#include "int16.hpp"
#include "int32.hpp"
#include "int64.hpp"
#include "int8.hpp"

namespace elemvm
{
namespace operands
{
Creator::Creator()
{
    m_creators.push_back(
        [this](const std::string& value) { return this->createInt8(value); });
    m_creators.push_back(
        [this](const std::string& value) { return this->createInt16(value); });
    m_creators.push_back(
        [this](const std::string& value) { return this->createInt32(value); });
    m_creators.push_back(
        [this](const std::string& value) { return this->createInt64(value); });
    // m_creators.push_back([this](const std::string& value) {
    //     return this->createInt128(value);
    // });
    m_creators.push_back([this](const std::string& value) {
        return this->createFloat32(value);
    });
    m_creators.push_back([this](const std::string& value) {
        return this->createFloat64(value);
    });
}
std::shared_ptr<const IOperand> Creator::createOperand(
    eOperandType type, const std::string& value) const
{
    return m_creators[static_cast<int>(type)](value);
}
std::shared_ptr<const IOperand> Creator::createInt8(
    const std::string& value) const
{
    auto num_value = std::stoll(value);

    if (checkOverflow<char, long long>(num_value))
    {
        throw std::runtime_error("Error: Data overflow!");
    }
    return std::make_shared<Int8>(num_value);
}
std::shared_ptr<const IOperand> Creator::createInt16(
    const std::string& value) const
{
    auto num_value = std::stoll(value);

    if (checkOverflow<short, long long>(num_value))
    {
        throw std::runtime_error("Error: Data overflow!");
    }
    return std::make_shared<Int16>(num_value);
}
std::shared_ptr<const IOperand> Creator::createInt32(
    const std::string& value) const
{
    auto num_value = std::stoll(value);

    if (checkOverflow<int, long long>(num_value))
    {
        throw std::runtime_error("Error: Data overflow!");
    }
    return std::make_shared<Int32>(num_value);
}
std::shared_ptr<const IOperand> Creator::createInt64(
    const std::string& value) const
{
    auto num_value = std::stoll(value);

    if (checkOverflow<long long, long long>(num_value))
    {
        throw std::runtime_error("Error: Data overflow!");
    }
    return std::make_shared<Int64>(num_value);
}

std::shared_ptr<const IOperand> Creator::createFloat32(
    const std::string& value) const
{
    auto num_value = std::stod(value);

    if (checkOverflow<float, double>(num_value))
    {
        throw std::runtime_error("Error: Data overflow!");
    }
    return std::make_shared<Float32>(num_value);
}
std::shared_ptr<const IOperand> Creator::createFloat64(
    const std::string& value) const
{
    auto num_value = std::stod(value);

    if (checkOverflow<double, double>(num_value))
    {
        throw std::runtime_error("Error: Data overflow!");
    }
    return std::make_shared<Float64>(num_value);
}
}  // namespace operands
}  // namespace elemvm