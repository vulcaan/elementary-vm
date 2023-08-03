#ifndef ELEMVM_LIB_PARSER_CLI_INCLUDE_ICOMMAND_HPP_
#define ELEMVM_LIB_PARSER_CLI_INCLUDE_ICOMMAND_HPP_

#include <memory>
#include <stack>
namespace elemvm
{
namespace operands
{
class IOperand;
}
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
class ICommand
{
public:
    virtual bool run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const = 0;
    virtual ~ICommand(){};
};
}  // namespace cli
}  // namespace parsing
}  // namespace elemvm
#endif  // ELEMVM_LIB_PARSER_CLI_INCLUDE_ICOMMAND_HPP_
