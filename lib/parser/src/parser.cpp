#include "parser.hpp"

#include <sstream>
namespace parser
{
namespace
{
std::vector<std::string> split(const std::string& line, char delimiter) noexcept
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

std::string remove_comment(const std::string& line, char symbol) noexcept
{
    if (line == "##")
        return line;
    std::string result = line.substr(0, line.find(symbol));
    return result;
}
}  // namespace

std::vector<std::string> parse(const std::string& line) noexcept
{
    std::string temp_line;
    std::string line_without_comments = remove_comment(line, '#');
    std::vector<std::string> tokens = split(line_without_comments, ' ');
    return tokens;
}
}  // namespace parser
