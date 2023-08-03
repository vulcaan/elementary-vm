#ifndef ELEMVM_PARSER_INSTRUCTION_IPARSER_HPP
#define ELEMVM_PARSER_INSTRUCTION_IPARSER_HPP

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
#endif  // ELEMVM_PARSER_INSTRUCTION_IPARSER_HPP
