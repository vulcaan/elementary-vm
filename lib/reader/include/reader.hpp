#pragma once
#include <string>
#include <vector>
#include <istream>
namespace elemvm
{
namespace reading
{

class IReader
{
public:
    virtual std::vector<std::string> read(std::istream& in) const = 0;
    virtual ~IReader(){};
};

}  // namespace reading
}  // namespace elemvm
