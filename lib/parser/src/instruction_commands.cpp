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
    std::cout << "[AddCommand::run] Start\n";
    if (storage->size() < 2)
    {
        throw new std::runtime_error(
            "Not enough elements in storage to use \'add\' instruction!");
    }
    auto value1 = storage->top();
    storage->pop();
    auto value2 = storage->top();
    storage->pop();
    storage->push(value1 + value2);
    return true;
};
bool PutCommand::run(std::shared_ptr<std::stack<int>> storage) const
{
    std::cout << "[PutCommand::run] Start.\n";
    std::cout << "[PutCommand::run] Put " << m_value << " to storage\n";
    storage->push(m_value);
    return true;
};

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
