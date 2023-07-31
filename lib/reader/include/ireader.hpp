#ifndef ELEMVM_READER_IREADER_HPP
#define ELEMVM_READER_IREADER_HPP

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
#endif  // ELEMVM_READER_IREADER_HPP
