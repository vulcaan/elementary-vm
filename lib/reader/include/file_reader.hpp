#ifndef ELEMVM_READER_FILE_HPP
#define ELEMVM_READER_FILE_HPP

#include <iostream>
#include <string>
#include <vector>

#include "ireader.hpp"

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
#endif  // ELEMVM_READER_FILE_HPP
