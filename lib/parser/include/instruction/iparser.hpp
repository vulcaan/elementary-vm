#ifndef ELEMVM_LIB_PARSER_INCLUDE_INSTRUCTION_IPARSER_HPP_
#define ELEMVM_LIB_PARSER_INCLUDE_INSTRUCTION_IPARSER_HPP_

#include <memory>
#include <string>
#include <vector>

namespace elemvm
{
namespace parsing
{
namespace instructions
{
class ICommand;
class IParser
{
public:
    virtual std::unique_ptr<const ICommand> parse(const std::string& line) const = 0;
    virtual ~IParser(){};
};
}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
#endif  // ELEMVM_LIB_PARSER_INCLUDE_INSTRUCTION_IPARSER_HPP_
