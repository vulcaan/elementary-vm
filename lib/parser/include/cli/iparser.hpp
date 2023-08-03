#ifndef ELEMVM_LIB_PARSER_CLI_INCLUDE_IPARSER_HPP_
#define ELEMVM_LIB_PARSER_CLI_INCLUDE_IPARSER_HPP_

#include <memory>
#include <string>
#include <vector>
namespace elemvm
{
namespace parsing
{
namespace cli
{
class ICommand;
class IParser
{
public:
    virtual std::unique_ptr<ICommand> parse(const std::vector<std::string>& args) const = 0;
    virtual ~IParser(){};
};
}  // namespace cli
}  // namespace parsing
}  // namespace elemvm
#endif  // ELEMVM_LIB_PARSER_CLI_INCLUDE_IPARSER_HPP_
