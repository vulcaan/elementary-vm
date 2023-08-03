#ifndef ELEMVM_LIB_READER_INCLUDE_FILE_READER_HPP_
#define ELEMVM_LIB_READER_INCLUDE_FILE_READER_HPP_

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
    FileReader(std::string path);
    virtual std::vector<std::string> read(std::istream& in) const override;
    void setOut(std::ostream& out);
    ~FileReader();

private:
    std::ostream& m_out;
    std::string m_path;
};

}  // namespace reading
}  // namespace elemvm
#endif  // ELEMVM_LIB_READER_INCLUDE_FILE_READER_HPP_
