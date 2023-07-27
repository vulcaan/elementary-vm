#include "instruction/commands.hpp"

#include <iostream>
namespace elemvm
{
namespace parsing
{
namespace instructions
{
eInstrResult AddCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
        storage) const
{
    std::cout << "[AddCommand::run] Adding numbers...\n";
    if (storage->size() < 2)
    {
        throw std::runtime_error(
            "Not enough elements in the storage to use the \'add\' "
            "instruction!");
    }
    auto value1 = storage->top();
    storage->pop();
    auto value2 = storage->top();
    storage->pop();
    storage->push(std::shared_ptr<const operands::IOperand>{*value1 + *value2});
    std::cout << "[AddCommand::run] Done.\n";
    return eInstrResult::SUCCESS;
};

eInstrResult MulCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
        storage) const
{
    std::cout << "[MulCommand::run] Multiplying numbers...\n";
    if (storage->size() < 2)
    {
        throw std::runtime_error(
            "Not enough elements in the storage to use the \'mul\' "
            "instruction!");
    }
    auto value1 = storage->top();
    storage->pop();
    auto value2 = storage->top();
    storage->pop();
    storage->push(std::shared_ptr<const operands::IOperand>{*value1 * *value2});
    std::cout << "[MulCommand::run] Done.\n";
    return eInstrResult::SUCCESS;
};

eInstrResult DivCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
        storage) const
{
    std::cout << "[DivCommand::run] Dividing numbers...\n";
    if (storage->size() < 2)
    {
        throw std::runtime_error(
            "Not enough elements in the storage to use the \'div\' "
            "instruction!");
    }
    auto value1 = storage->top();
    storage->pop();
    auto value2 = storage->top();
    storage->pop();
    storage->push(std::shared_ptr<const operands::IOperand>{*value1 / *value2});
    std::cout << "[DivCommand::run] Done.\n";
    return eInstrResult::SUCCESS;
};

eInstrResult ModCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
        storage) const
{
    std::cout << "[ModCommand::run] Getting Modulus of numbers...\n";
    if (storage->size() < 2)
    {
        throw std::runtime_error(
            "Not enough elements in the storage to use the \'mod\' "
            "instruction!");
    }
    auto value1 = storage->top();
    storage->pop();
    auto value2 = storage->top();
    storage->pop();
    storage->push(std::shared_ptr<const operands::IOperand>{*value1 % *value2});
    std::cout << "[ModCommand::run] Done.\n";
    return eInstrResult::SUCCESS;
};

eInstrResult PutCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
        storage) const
{
    std::cout << "[PutCommand::run] Putting " << m_operand->toString()
              << " to the storage\n";
    storage->push(std::shared_ptr<const operands::IOperand>{m_operand});
    std::cout << "[PutCommand::run] Done.\n";
    return eInstrResult::SUCCESS;
};

eInstrResult AssertCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
        storage) const
{
    std::cout << "[AssertCommand::run] Asserting top value equals \""
              << m_operand->toString() << "\"...\n";
    if (storage->size() < 1)
    {
        throw std::runtime_error(
            "Not enough elements in the storage to use the \'assert\' "
            "instruction!");
    }
    auto top_value = storage->top();
    if (*top_value != *m_operand)
    {
        throw std::runtime_error(
            "The value on the top of the storage doesn't equal passed value.");
    }
    std::cout << "[AssertCommand::run] Done.\n";
    return eInstrResult::SUCCESS;
};

eInstrResult PrintCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
        storage) const
{
    std::cout << "[PrintCommand::run] Printing top value...\n";
    if (storage->size() < 1)
    {
        throw std::runtime_error(
            "[ERROR] Not enough elements in the storage to use the \'print\' "
            "instruction!");
    }
    auto top_value = storage->top();
    if (top_value->getType() != operands::eOperandType::Int8)
    {
        throw std::runtime_error(
            "[ERROR] The value on the top of the storage isn't Int8.");
    }
    std::cout << static_cast<char>(std::stoi(top_value->toString())) << std::endl;
    std::cout << "[PrintCommand::run] Done.\n";
    return eInstrResult::SUCCESS;
};

eInstrResult PopCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
        storage) const
{
    std::cout << "[PopCommand::run] Popping from the storage...\n";
    if (storage->empty())
    {
        throw std::runtime_error(
            "Not enough elements in the storage to use the \'pop\' "
            "instruction!");
    }
    std::cout << "[PopCommand::run] Done.\n";
    return eInstrResult::SUCCESS;
};

eInstrResult SubCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
        storage) const
{
    std::cout << "[SubCommand::run] Subtracting numbers...\n";
    if (storage->size() < 2)
    {
        throw std::runtime_error(
            "Not enough elements in the storage to use the \'sub\' "
            "instruction!");
    }
    auto value1 = storage->top();
    storage->pop();
    auto value2 = storage->top();
    storage->pop();
    storage->push(std::shared_ptr<const operands::IOperand>{*value1 - *value2});
    std::cout << "[SubCommand::run] Done.\n";
    return eInstrResult::SUCCESS;
};

eInstrResult EndCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>) const
{
    std::cout << "[EndCommand::run] Ending program...\n";
    return eInstrResult::END;
};

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
