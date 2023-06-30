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
            "Not enough elements in the storage to use the \'add\' "
            "instruction!");
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

bool AssertCommand::run(std::shared_ptr<std::stack<int>> storage) const
{
    std::cout << "[AssertCommand::run] Start.\n";
    std::cout << "[AssertCommand::run] Assert top value equals \"" << m_value
              << "\"\n";
    if (storage->size() < 1)
    {
        throw new std::runtime_error(
            "Not enough elements in the storage to use the \'assert\' "
            "instruction!");
    }
    auto top_value = storage->top();
    if (top_value != storage->top())
    {
        throw new std::runtime_error(
            "The value on the top of the storage doesn't equal passed value.");
    }
    return true;
};

bool PopCommand::run(std::shared_ptr<std::stack<int>> storage) const
{
    std::cout << "[PopCommand::run] Start.\n";
    if (storage->empty())
    {
        throw new std::runtime_error(
            "Not enough elements in the storage to use the \'pop\' "
            "instruction!");
    }
    return true;
};

bool SubCommand::run(std::shared_ptr<std::stack<int>> storage) const
{
    std::cout << "[SubCommand::run] Start.\n";
    if (storage->size() < 2)
    {
        throw new std::runtime_error(
            "Not enough elements in the storage to use the \'sub\' "
            "instruction!");
    }
    auto value1 = storage->top();
    storage->pop();
    auto value2 = storage->top();
    storage->pop();
    storage->push(value1 - value2);
    return true;
};

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
