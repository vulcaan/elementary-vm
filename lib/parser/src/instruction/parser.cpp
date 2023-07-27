#include "instruction/parser.hpp"

#include <iostream>
#include <memory>
#include <regex>
#include <string>

#include "instruction/commands.hpp"

namespace elemvm
{
namespace parsing
{
namespace instructions
{
Parser::Parser()
    : m_instrCreator(std::make_shared<InstructionCreator>())
{
    m_instructionsMap["put"] = eInstruction::PUT;
    m_instructionsMap["pop"] = eInstruction::POP;
    m_instructionsMap["add"] = eInstruction::ADD;
    m_instructionsMap["sub"] = eInstruction::SUB;
    m_instructionsMap["div"] = eInstruction::DIV;
    m_instructionsMap["mul"] = eInstruction::MUL;
    m_instructionsMap["mod"] = eInstruction::MOD;
    m_instructionsMap["end"] = eInstruction::END;
    m_instructionsMap["assert"] = eInstruction::ASSERT;
}

void Parser::setCreator(std::shared_ptr<InstructionCreator> creator)
{
    m_instrCreator = creator;
}

std::string Parser::remove_comment(const std::string& line,
                                   char symbol) const
{
    if (line == "##")
        return line;
    std::string result = line.substr(0, line.find(symbol));
    return result;
}

std::unique_ptr<const ICommand> Parser::parse(
    const std::string& line) const
{
    std::cout << "[InstructionsParser::parse] Parsing instruction...\n";
    std::regex pattern(
        R"([\s]*([a-z]+)([\s]+[a-z]+[0-9]+\((?:[-+]?[0-9]*(?:\.[0-9]*(?:f|(?:e\+?[0-9]+))?)?)\))?[\s]*)");
    auto line_without_comments = remove_comment(line);
    if (line_without_comments.empty())
    {
        return nullptr;
    }
    std::smatch match;
    if (std::regex_match(line_without_comments, match, pattern))
    {
        if (m_instructionsMap.find(match[1]) != m_instructionsMap.end())
        {
            return std::unique_ptr<const ICommand>(m_instrCreator->create(m_instructionsMap.at(match[1]), match[2]));
        }
    }

    throw std::runtime_error("[ERROR] Unknown Instruction.");
};

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
