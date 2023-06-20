#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "reader.hpp"

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
    void setStop(const std::string & stop);

private:
    std::ostream& m_out;
    std::string m_stop;
};

}  // namespace reading
}  // namespace elemvm
