#ifndef ELEMVM_PARSER_CLI_IPARSER_HPP
#define ELEMVM_PARSER_CLI_IPARSER_HPP

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
#endif  // ELEMVM_PARSER_CLI_IPARSER_HPP
