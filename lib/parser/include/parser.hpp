#ifndef PARSER_HPP
#define PARSER_HPP
#include <string>
#include <vector>

class Parser
{
private:
    std::string remove_comment(const std::string &line, char symbol) const noexcept;
    std::vector<std::string> split(const std::string &line, char delimiter) const noexcept;

public:
    std::vector<std::string> parse(const std::string &line) const noexcept;
    Parser() = default;
    ~Parser() = default;
};

#endif // PARSER_HPP
