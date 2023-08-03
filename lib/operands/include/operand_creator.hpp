#ifndef ELEMVM_LIB_OPERANDS_CREATOR_HPP
#define ELEMVM_LIB_OPERANDS_CREATOR_HPP
#include <functional>
#include <limits>
#include <memory>
#include <string>
#include <vector>
namespace elemvm
{
namespace operands
{
class IOperand;
enum class eOperandType;
class Creator
{
public:
    Creator();
    const IOperand* createOperand(eOperandType type,
                                  const std::string& value) const;

private:
    const IOperand* createInt8(const std::string& value) const;
    const IOperand* createInt16(const std::string& value) const;
    const IOperand* createInt32(const std::string& value) const;
    const IOperand* createInt64(const std::string& value) const;
    // const IOperand* createInt128(const std::string& value) const;
    const IOperand* createFloat32(const std::string& value) const;
    const IOperand* createFloat64(const std::string& value) const;
    template <class RequiredType, class ActualType = void>
    bool checkOverflow(ActualType num_value) const;

    std::vector<std::function<const IOperand*(const std::string&)>> m_creators;
};

template <class RequiredType, class ActualType = void>
bool Creator::checkOverflow(ActualType num_value) const
{
    return num_value > std::numeric_limits<RequiredType>::max()
           || num_value < std::numeric_limits<RequiredType>::min();
};
}  // namespace operands
}  // namespace elemvm
#endif  // ELEMVM_LIB_OPERANDS_CREATOR_HPP
