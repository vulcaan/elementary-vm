#pragma once
#include <filesystem>
#include <string>
namespace reader
{
std::string read_from_console(const std::string& stop = "##");
std::string read_from_file(const std::filesystem::path& filename);
};  // namespace reader
