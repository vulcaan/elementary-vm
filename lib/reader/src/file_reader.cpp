#include "file_reader.hpp"

#include <fstream>

namespace elemvm
{
namespace reading
{
std::vector<std::string> FileReader::read(std::istream& in) const
{
    // TODO(1): Fix unused argument
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
            throw std::runtime_error("Error: Couldn't read from file.");
        }
    }
    throw std::runtime_error("Error: Bad input stream.");
};

void FileReader::setOut(std::ostream& out) { m_out.rdbuf(out.rdbuf()); };

}  // namespace reading
}  // namespace elemvm
