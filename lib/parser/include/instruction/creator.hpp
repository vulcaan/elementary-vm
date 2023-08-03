#ifndef ELEMVM_LIB_PARSER_INCLUDE_INSTRUCTION_CREATOR_HPP_
#define ELEMVM_LIB_PARSER_INCLUDE_INSTRUCTION_CREATOR_HPP_

#include <functional>
#include <regex>
#include <unordered_map>
#include <vector>

#include "instruction/icommand.hpp"
#include "instruction/icomplex.hpp"
#include "instruction/itrivial.hpp"
#include "ioperand.hpp"
#include "operand_creator.hpp"

namespace elemvm
{
namespace parsing
{
namespace instructions
{
class InstructionCreator
{
public:
    const ICommand* create(eInstruction type, const std::string& value);

private:
    class ICreator
    {
    public:
        virtual const ICommand* operator()(const std::string& value) const = 0;
    };

    template <class Command, class Type = void>
    class CreateInstruction;

    template <class Command>
    class CreateInstruction<Command,
                            typename std::enable_if<std::is_base_of<IComplex, Command>::value>::type> : public ICreator
    {
    public:
        CreateInstruction();
        const ICommand* operator()(const std::string& value) const;

    private:
        std::unique_ptr<operands::Creator> m_operandCreator;
        std::unordered_map<std::string, operands::eOperandType> m_operandTypesMap;
    };

    template <class Command>
    class CreateInstruction<Command,
                            typename std::enable_if<!std::is_base_of<IComplex, Command>::value>::type> : public ICreator
    {
    public:
        const ICommand* operator()(const std::string& value) const;
    };
};

template <class Command>
InstructionCreator::CreateInstruction<Command,
                                      typename std::enable_if<std::is_base_of<IComplex, Command>::value>::type>::CreateInstruction()

{
    m_operandCreator = std::make_unique<operands::Creator>();
    m_operandTypesMap = {
        {"int8", operands::eOperandType::Int8},
        {"int16", operands::eOperandType::Int16},
        {"int32", operands::eOperandType::Int32},
        {"int64", operands::eOperandType::Int64},
        {"float32", operands::eOperandType::Float32},
        {"float64", operands::eOperandType::Float64},
    };
}

template <class Command>
const ICommand* InstructionCreator::CreateInstruction<Command,
                                                      typename std::enable_if<std::is_base_of<IComplex, Command>::value>::type>::operator()(const std::string& value) const
{
    if (!value.empty())
    {
        std::regex pattern(
            R"([\s]*([a-z0-9]+)\(([-+]?[0-9]*(?:\.[0-9]*(?:f|(?:e\+?[0-9]+))?)?)\)[\s]*)");
        std::smatch match;
        if (std::regex_match(value, match, pattern))
        {
            if (m_operandTypesMap.find(match[1]) != m_operandTypesMap.end())
            {
                return new Command(std::shared_ptr<const operands::IOperand>(m_operandCreator->createOperand(m_operandTypesMap.at(match[1]), match[2])));
            }
        }
    }
    throw std::runtime_error("[ERROR] Wrong Instruction Usage.");
}

template <class Command>
const ICommand* InstructionCreator::CreateInstruction<Command,
                                                      typename std::enable_if<!std::is_base_of<IComplex, Command>::value>::type>::operator()(const std::string& value) const
{
    if (value.empty())
    {
        return new Command();
    }
    throw std::runtime_error("[ERROR] Wrong Instruction Usage.");
}

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
#endif  // ELEMVM_LIB_PARSER_INCLUDE_INSTRUCTION_CREATOR_HPP_
