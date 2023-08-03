#include "instruction/parser.hpp"

#include <iostream>
#include <memory>
#include <regex>
#include <string>

#include "instruction/commands.hpp"
#include "instruction/icommand.hpp"

namespace elemvm
{
namespace parsing
{
namespace instructions
{
Parser::Parser()
    : m_instrCreator(std::make_shared<InstructionCreator>())
{
    m_instructionsMap = {
        {"put", eInstruction::PUT},
        {"pop", eInstruction::POP},
        {"add", eInstruction::ADD},
        {"sub", eInstruction::SUB},
        {"div", eInstruction::DIV},
        {"mul", eInstruction::MUL},
        {"mod", eInstruction::MOD},
        {"end", eInstruction::END},
        {"assert", eInstruction::ASSERT},
        {"print", eInstruction::PRINT},
        {"trace", eInstruction::TRACE},
    };
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

bool Parser::isConsistOf(const std::string& line, char symbol) const
{
    for (const auto& el : line)
    {
        if (el != symbol)
            return false;
    }
    return true;
}

std::unique_ptr<const ICommand> Parser::parse(
    const std::string& line) const
{
    std::cout << "[InstructionsParser::parse] Parsing instruction...\n";
    std::regex pattern(R"([\s]*([a-z]+)(?:[\s]+([a-z]+[0-9]+\((?:[-+]?[0-9]*(?:\.[0-9]*(?:f|(?:e\+?[0-9]+))?)?)\)))?[\s]*)");
    auto line_without_comments = remove_comment(line);
    if (line_without_comments.empty() || isConsistOf(line_without_comments, ' '))
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
