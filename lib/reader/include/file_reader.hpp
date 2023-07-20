#pragma once

#if defined(_MSC_VER) && _MSC_VER < 1914
#include <experimental/filesystem>
#elif defined(__has_include)
#if __has_include(<filesystem>)
#include <filesystem>
#elif __has_include(<experimental/filesystem>)
#include <experimental/filesystem>
namespace std
{
namespace filesystem = ::std::experimental::filesystem;
}
#endif
#endif

#include <iostream>
#include <string>
#include <vector>

#include "reader.hpp"

namespace elemvm
{
namespace reading
{
class FileReader : public IReader
{
public:
    FileReader(std::filesystem::path path)
        : m_out(std::cout)
        , m_path(path){};

    virtual std::vector<std::string> read(std::istream& in) const override;
    void setOut(std::ostream& out);

private:
    std::ostream& m_out;
    std::filesystem::path m_path;
};

}  // namespace reading
}  // namespace elemvm
