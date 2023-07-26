#include "operand_parser.hpp"

#include <regex>
namespace elemvm
{
namespace operands
{
namespace parsing
{
OperandParser::OperandParser()
    : m_op_creator(std::make_shared<Creator>())
{
    m_typesMap["int8"] = eOperandType::Int8;
    m_typesMap["int16"] = eOperandType::Int16;
    m_typesMap["int32"] = eOperandType::Int32;
    m_typesMap["int64"] = eOperandType::Int64;
    m_typesMap["float32"] = eOperandType::Float32;
    m_typesMap["float64"] = eOperandType::Float64;
}
std::shared_ptr<const IOperand> OperandParser::parse(const std::string& arg)
{
    std::regex pattern(
        R"((int8|int16|int32|int64|float32|float64)\((-?\d+(\.\d+)?)\))");
    std::smatch match;
    if (std::regex_match(arg, match, pattern))
    {
        return std::shared_ptr<const IOperand>(m_op_creator->createOperand(m_typesMap[match[1]], match[2]));
    }
    else
    {
        throw std::invalid_argument("Invalid Operand format.");
    }
}
void OperandParser::setCreator(std::shared_ptr<Creator> creator)
{
    m_op_creator = creator;
}
}  // namespace parsing
}  // namespace operands
}  // namespace elemvm
