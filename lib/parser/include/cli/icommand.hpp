#ifndef ELEMVM_PARSER_CLI_ICOMMAND_HPP
#define ELEMVM_PARSER_CLI_ICOMMAND_HPP

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
#endif  // ELEMVM_PARSER_CLI_ICOMMAND_HPP
