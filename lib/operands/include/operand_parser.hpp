#pragma once
#include <unordered_map>

#include "creator.hpp"
#include "iparser.hpp"
namespace elemvm
{
namespace operands
{
namespace parsing
{
class OperandParser : public IParser
{
public:
    OperandParser();
    virtual std::shared_ptr<const IOperand> parse(const std::string& arg) override;
    void setCreator(std::shared_ptr<Creator> creator);

private:
    std::shared_ptr<Creator> m_op_creator;
    std::unordered_map<std::string, eOperandType> m_typesMap;
};

}  // namespace parsing
}  // namespace operands
}  // namespace elemvm