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
std::shared_ptr<IOperand> Creator::createOperand(eOperandType type,
                                                 const std::string& value) const
{
    return m_creators[static_cast<int>(type)](value);
}
const std::shared_ptr<IOperand> Creator::createInt8(
    const std::string& value) const
{
    return std::make_shared<Int8>(std::stoll(value));
}
const std::shared_ptr<IOperand> Creator::createInt16(
    const std::string& value) const
{
    return std::make_shared<Int16>(std::stoll(value));
}
std::shared_ptr<IOperand> Creator::createInt32(const std::string& value) const
{
    return std::make_shared<Int32>(std::stoll(value));
}
const std::shared_ptr<IOperand> Creator::createInt64(
    const std::string& value) const
{
    return std::make_shared<Int64>(std::stoll(value));
}

const std::shared_ptr<IOperand> Creator::createFloat32(
    const std::string& value) const
{
    return std::make_shared<Float32>(std::stod(value));
}
const std::shared_ptr<IOperand> Creator::createFloat64(
    const std::string& value) const
{
    return std::make_shared<Float64>(std::stod(value));
}
}  // namespace operands
}  // namespace elemvm