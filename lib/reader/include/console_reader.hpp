#ifndef ELEMVM_READER_CONSOLE_HPP
#define ELEMVM_READER_CONSOLE_HPP

#include <iostream>
#include <string>
#include <vector>

#include "ireader.hpp"

namespace elemvm
{
namespace reading
{
class ConsoleReader : public IReader
{
public:
    ConsoleReader()
        : m_out(std::cout)
        , m_stop("##"){};

    virtual std::vector<std::string> read(std::istream& in) const override;
    void setOut(std::ostream& out);
    void setStop(const std::string& stop);

private:
    std::ostream& m_out;
    std::string m_stop;
};

}  // namespace reading
}  // namespace elemvm
#endif  // ELEMVM_READER_CONSOLE_HPP
