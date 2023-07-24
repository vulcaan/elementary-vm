#pragma once
#include <functional>
#include <limits>
#include <memory>
#include <vector>

#include "ioperand.hpp"
namespace elemvm
{
namespace operands
{
class Creator
{
public:
    Creator();
    std::shared_ptr<const IOperand> createOperand(
        eOperandType type, const std::string& value) const;

private:
    std::vector<std::function<std::shared_ptr<const IOperand>(const std::string&)>>
        m_creators;

    std::shared_ptr<const IOperand> createInt8(const std::string& value) const;
    std::shared_ptr<const IOperand> createInt16(const std::string& value) const;
    std::shared_ptr<const IOperand> createInt32(const std::string& value) const;
    std::shared_ptr<const IOperand> createInt64(const std::string& value) const;
    //  std::shared_ptr<const IOperand> createInt128(
    //     const std::string& value) const;
    std::shared_ptr<const IOperand> createFloat32(
        const std::string& value) const;
    std::shared_ptr<const IOperand> createFloat64(
        const std::string& value) const;
    template <class RequiredType, class ActualType>
    bool checkOverflow(ActualType num_value) const
    {
        return num_value > std::numeric_limits<RequiredType>::max()
               || num_value < std::numeric_limits<RequiredType>::min();
    };
};
}  // namespace operands
}  // namespace elemvm
