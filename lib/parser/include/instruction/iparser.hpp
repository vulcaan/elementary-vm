#ifndef ELEMVM_INSTRUCTION_IPARSER_HPP
#define ELEMVM_INSTRUCTION_IPARSER_HPP

#include <memory>
#include <string>
#include <vector>

#include "instruction/icommand.hpp"
namespace elemvm
{
namespace parsing
{
namespace instructions
{
class IParser
{
public:
    virtual std::unique_ptr<const ICommand> parse(
        const std::string& line) const = 0;
    virtual ~IParser(){};
};
}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
#endif  // ELEMVM_INSTRUCTION_IPARSER_HPP
