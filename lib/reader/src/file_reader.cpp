#include "file_reader.hpp"

#include <fstream>

namespace elemvm
{
namespace reading
{
FileReader::FileReader(std::string path)
    : m_out(std::cout)
    , m_path(path){};

std::vector<std::string> FileReader::read(std::istream& in) const
{
    // TODO(1): Fix workaround with unused iostream argument.
    if (in)
    {
        std::ifstream file(m_path);
        if (file)
        {
            std::string input;
            std::vector<std::string> output;
            while (std::getline(file, input))
            {
                output.push_back(std::move(input));
            }
            return output;
        }
        else
        {
            throw std::runtime_error("[ERROR] Couldn't read from file.");
        }
    }
    throw std::runtime_error("[ERROR] Bad input stream.");
};

FileReader::~FileReader() = default;

void FileReader::setOut(std::ostream& out) { m_out.rdbuf(out.rdbuf()); };

}  // namespace reading
}  // namespace elemvm
