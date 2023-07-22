#pragma once
#include <functional>
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
    std::shared_ptr<IOperand> createOperand(eOperandType type,
                                            const std::string& value) const;

private:
    std::vector<std::function<std::shared_ptr<IOperand>(const std::string&)>>
        m_creators;

    const std::shared_ptr<IOperand> createInt8(const std::string& value) const;
    const std::shared_ptr<IOperand> createInt16(const std::string& value) const;
    std::shared_ptr<IOperand> createInt32(const std::string& value) const;
    const std::shared_ptr<IOperand> createInt64(const std::string& value) const;
    // const std::shared_ptr<IOperand> createInt128(
    //     const std::string& value) const;
    const std::shared_ptr<IOperand> createFloat32(
        const std::string& value) const;
    const std::shared_ptr<IOperand> createFloat64(
        const std::string& value) const;
};
}  // namespace operands
}  // namespace elemvm
