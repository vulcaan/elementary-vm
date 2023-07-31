#ifndef ELEMVM_OPERAND_CREATOR_HPP
#define ELEMVM_OPERAND_CREATOR_HPP
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
    const IOperand* createOperand(
        eOperandType type, const std::string& value) const;

private:
    std::vector<std::function<const IOperand*(const std::string&)>>
        m_creators;

    const IOperand* createInt8(const std::string& value) const;
    const IOperand* createInt16(const std::string& value) const;
    const IOperand* createInt32(const std::string& value) const;
    const IOperand* createInt64(const std::string& value) const;
    //  const IOperand * createInt128(
    //     const std::string& value) const;
    const IOperand* createFloat32(
        const std::string& value) const;
    const IOperand* createFloat64(
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
#endif // ELEMVM_OPERAND_CREATOR_HPP
