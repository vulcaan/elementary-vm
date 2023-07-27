#include <functional>
#include <regex>
#include <unordered_map>
#include <vector>

#include "instruction/icommand.hpp"
#include "instruction/icomplex.hpp"
#include "instruction/itrivial.hpp"
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
    InstructionCreator();
    const ICommand* create(eInstruction type, const std::string& value);

private:
    std::vector<std::function<const ICommand*(const std::string&)>>
        m_creators;

    class ICreator
    {
    public:
        virtual const ICommand* operator()(const std::string& value) const = 0;
    };

    template <class Command, class Type = void>
    class createInstr;

    template <class Command>
    class createInstr<Command,
                      typename std::enable_if<std::is_base_of<IComplex, Command>::value>::type> : public ICreator
    {
    public:
        const ICommand* operator()(const std::string& value) const
        {
            if (!value.empty())
            {
                std::regex pattern(
                    R"([\s]*([a-z0-9]+)\(([-+]?[0-9]*(?:\.[0-9]*(?:f|(?:e\+?[0-9]+))?)?)\)[\s]*)");
                std::smatch match;
                if (std::regex_match(value, match, pattern))
                {
                    std::unordered_map<std::string, operands::eOperandType> m_operandTypesMap;
                    m_operandTypesMap["int8"] = operands::eOperandType::Int8;
                    m_operandTypesMap["int16"] = operands::eOperandType::Int16;
                    m_operandTypesMap["int32"] = operands::eOperandType::Int32;
                    m_operandTypesMap["int64"] = operands::eOperandType::Int64;
                    m_operandTypesMap["float32"] = operands::eOperandType::Float32;
                    m_operandTypesMap["float64"] = operands::eOperandType::Float64;
                    if (m_operandTypesMap.find(match[1]) != m_operandTypesMap.end())
                    {
                        return new Command(std::shared_ptr<const operands::IOperand>(m_operandCreator->createOperand(m_operandTypesMap.at(match[1]), match[2])));
                    }
                }
            }
            throw std::runtime_error("[ERROR] Wrong Instruction Usage.");
        }

    private:
        std::unique_ptr<operands::Creator> m_operandCreator{new operands::Creator()};
    };

    template <class Command>
    class createInstr<Command,
                      typename std::enable_if<!std::is_base_of<IComplex, Command>::value>::type> : public ICreator
    {
    public:
        const ICommand* operator()(const std::string& value) const
        {
            if (value.empty())
            {
                return new Command();
            }
            throw std::runtime_error("[ERROR] Wrong Instruction Usage.");
        }
    };
};
}  // namespace instructions
}  // namespace parsing

}  // namespace elemvm
