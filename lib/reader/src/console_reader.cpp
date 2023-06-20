#include "console_reader.hpp"

namespace elemvm
{
namespace reading
{
std::vector<std::string> ConsoleReader::read(std::istream& in) const
{
    std::string input;
    std::vector<std::string> output;
    m_out << "Enter commands, type \'" << m_stop << "\' to exit:\n";
    while (std::getline(in, input))
    {
        if (input == m_stop)
        {
            break;
        }
        output.push_back(std::move(input));
    }
    return output;
};

void ConsoleReader::setOut(std::ostream& out) { m_out.rdbuf(out.rdbuf()); };
void ConsoleReader::setStop(const std::string & stop) { m_stop = stop; };

}  // namespace reading
}  // namespace elemvm
