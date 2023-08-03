#ifndef ELEMVM_PARSER_INSTRUCTION_PARSER_HPP
#define ELEMVM_PARSER_INSTRUCTION_PARSER_HPP

#include <memory>
#include <string>
#include <unordered_map>

#include "instruction/creator.hpp"
#include "instruction/iparser.hpp"
#include "ioperand.hpp"

namespace elemvm
{
namespace parsing
{
namespace instructions
{
class Parser : public IParser
{
public:
    Parser();
    virtual std::unique_ptr<const ICommand> parse(const std::string& line) const override;
    void setCreator(std::shared_ptr<InstructionCreator> creator);

private:
    std::string remove_comment(const std::string& line,
                               char symbol = '#') const;
    bool isConsistOf(const std::string & line, char symbol) const;

    std::shared_ptr<InstructionCreator> m_instrCreator;
    std::unordered_map<std::string, eInstruction> m_instructionsMap;
};

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
#endif  // ELEMVM_PARSER_INSTRUCTION_PARSER_HPP
