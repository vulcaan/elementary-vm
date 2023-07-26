#include <sstream>
#include <string>

#include "instruction/tokenizer.hpp"

namespace elemvm
{
namespace parsing
{
namespace instructions
{
std::vector<std::string> InstructionTokenizer::tokenize(
    const std::string& instruction) const
{
    std::string line_without_comments = remove_comment(std::string(instruction), '#');
    std::vector<std::string> tokens = split(line_without_comments, ' ');
    return tokens;
}
std::vector<std::string> InstructionTokenizer::split(const std::string& line,
                                                     char delimiter) const
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(line);
    while (std::getline(tokenStream, token, delimiter))
    {
        if (token == "")
            continue;
        tokens.push_back(token);
    }
    return tokens;
}

std::string InstructionTokenizer::remove_comment(const std::string& line,
                                                 char symbol) const
{
    if (line == "##")
        return line;
    std::string result = line.substr(0, line.find(symbol));
    return result;
}

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
