#pragma once
#include <string>
#include <vector>

namespace command_parser
{
std::vector<std::string> parse(const std::string& line) noexcept;
};
