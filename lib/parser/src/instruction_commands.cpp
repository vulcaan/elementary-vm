#include "instruction_commands.hpp"

#include <iostream>
namespace elemvm
{
namespace parsing
{
namespace instructions
{
bool AddCommand::run(std::shared_ptr<std::stack<int>> storage) const
{
    std::cout << "AddCommand::value " << m_value << std::endl;
    return true;
};

}  // namespace instruction
}  // namespace parsing
}  // namespace elemvm
