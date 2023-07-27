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
    std::cout << "[AddCommand::run] Start\n";
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
    return eInstrResult::SUCCESS;
};

eInstrResult MulCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
        storage) const
{
    std::cout << "[MulCommand::run] Start\n";
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
    return eInstrResult::SUCCESS;
};

eInstrResult DivCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
        storage) const
{
    std::cout << "[DivCommand::run] Start\n";
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
    return eInstrResult::SUCCESS;
};

eInstrResult ModCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
        storage) const
{
    std::cout << "[ModCommand::run] Start\n";
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
    return eInstrResult::SUCCESS;
};

eInstrResult PutCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
        storage) const
{
    std::cout << "[PutCommand::run] Start.\n";
    std::cout << "[PutCommand::run] Put " << m_operand->toString()
              << " to storage\n";
    storage->push(std::shared_ptr<const operands::IOperand>{m_operand});
    return eInstrResult::SUCCESS;
};

eInstrResult AssertCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
        storage) const
{
    std::cout << "[AssertCommand::run] Start.\n";
    std::cout << "[AssertCommand::run] Assert top value equals \""
              << m_operand->toString() << "\"\n";
    if (storage->size() < 1)
    {
        throw std::runtime_error(
            "Not enough elements in the storage to use the \'assert\' "
            "instruction!");
    }
    auto top_value = storage->top();
    if (*top_value != *m_operand)
    {
        std::cerr << "storage top value: " << top_value->toString() << std::endl
                  << "instr value: " << m_operand->toString() << std::endl;
        throw std::runtime_error(
            "The value on the top of the storage doesn't equal passed value.");
    }
    return eInstrResult::SUCCESS;
};

eInstrResult PopCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
        storage) const
{
    std::cout << "[PopCommand::run] Start.\n";
    if (storage->empty())
    {
        throw std::runtime_error(
            "Not enough elements in the storage to use the \'pop\' "
            "instruction!");
    }
    return eInstrResult::SUCCESS;
};

eInstrResult SubCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
        storage) const
{
    std::cout << "[SubCommand::run] Start.\n";
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
    return eInstrResult::SUCCESS;
};

eInstrResult EndCommand::run(
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
        storage) const
{
    std::cout << "[EndCommand::run] Start.\n";
    // TODO(1): Fix unused argument
    //          dump nonempty storage?
    if (!storage->empty())
    {
        std::cout << "[warning] The End Instruction was passed while storage "
                     "isn't empty."
                  << std::endl;
    }
    return eInstrResult::END;
};

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
