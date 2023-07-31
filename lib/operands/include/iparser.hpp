#ifndef ELEMVM_OPERAND_IPARSER_HPP
#define ELEMVM_OPERAND_IPARSER_HPP
#include <memory>

#include "creator.hpp"
#include "ioperand.hpp"
namespace elemvm
{
namespace operands
{
namespace parsing
{
class IParser
{
public:
    virtual std::shared_ptr<const IOperand> parse(const std::string& arg) = 0;
    virtual ~IParser(){};
};

}  // namespace parsing
}  // namespace operands
}  // namespace elemvm
#endif  // ELEMVM_OPERAND_IPARSER_HPP
