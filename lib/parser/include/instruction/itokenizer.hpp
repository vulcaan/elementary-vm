#pragma once
#include <string>
#include <vector>

namespace elemvm
{
namespace parsing
{
namespace instructions
{

class ITokenizer
{
public:
    virtual std::vector<std::string> tokenize(const std::string &) const = 0;
    virtual ~ITokenizer(){};
};
}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
