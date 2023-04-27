#include "parser.hpp"

#include <sstream>

std::vector<std::string> Parser::split(const std::string &line, char delimiter) const noexcept
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

std::string Parser::remove_comment(const std::string &line, char symbol) const noexcept
{
    if (line == "##")
        return line;
    std::string result = line.substr(0, line.find(symbol));
    return result;
}

std::vector<std::string> Parser::parse(const std::string &line) const noexcept
{
    std::string temp_line;
    std::string line_without_comments = remove_comment(line, '#');
    std::vector<std::string> tokens = split(line_without_comments, ' ');
    return tokens;
}
