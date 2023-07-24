#pragma once

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
    FileReader(std::string path)
        : m_out(std::cout)
        , m_path(path){};

    virtual std::vector<std::string> read(std::istream& in) const override;
    void setOut(std::ostream& out);

private:
    std::ostream& m_out;
    std::string m_path;
};

}  // namespace reading
}  // namespace elemvm
