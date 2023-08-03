#ifndef ELEMVM_LIB_READER_INCLUDE_IREADER_HPP_
#define ELEMVM_LIB_READER_INCLUDE_IREADER_HPP_

#include <istream>
#include <string>
#include <vector>

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
#endif  // ELEMVM_LIB_READER_INCLUDE_IREADER_HPP_
