#ifndef ELEMVM_CLI_IPARSER_HPP
#define ELEMVM_CLI_IPARSER_HPP

#include <memory>
#include <string>
#include <vector>

#include "cli/icommand.hpp"
namespace elemvm
{
namespace parsing
{
namespace cli
{
enum class eCommand : int
{
    HELP = 0,
    INPUT_INTERACT,
    INPUT_FILE
};
class IParser
{
public:
    virtual std::unique_ptr<ICommand> parse(
        const std::vector<std::string>& args) const = 0;
    virtual ~IParser(){};
};
}  // namespace cli
}  // namespace parsing
}  // namespace elemvm
#endif  // ELEMVM_CLI_IPARSER_HPP
