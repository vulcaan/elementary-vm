#include "instruction/commands.hpp"

#include <iostream>
#include <stdexcept>

#include "ioperand.hpp"
namespace elemvm
{
namespace parsing
{
namespace instructions
{
eInstrResult AddCommand::run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const
{
    if (storage->size() < 2)
    {
        throw std::runtime_error("Not enough elements in the storage to use the \'add\' instruction!");
    }
    auto value1 = storage->top();
    storage->pop();
    auto value2 = storage->top();
    storage->pop();
    storage->push(std::shared_ptr<const operands::IOperand>{*value1 + *value2});
    return eInstrResult::SUCCESS;
};

eInstrResult MulCommand::run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const
{
    if (storage->size() < 2)
    {
        throw std::runtime_error("Not enough elements in the storage to use the \'mul\' instruction!");
    }
    auto value1 = storage->top();
    storage->pop();
    auto value2 = storage->top();
    storage->pop();
    storage->push(std::shared_ptr<const operands::IOperand>{*value1 * *value2});
    return eInstrResult::SUCCESS;
};

eInstrResult DivCommand::run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const
{
    if (storage->size() < 2)
    {
        throw std::runtime_error("Not enough elements in the storage to use the \'div\' instruction!");
    }
    auto value1 = storage->top();
    storage->pop();
    auto value2 = storage->top();
    storage->pop();
    storage->push(std::shared_ptr<const operands::IOperand>{*value1 / *value2});
    return eInstrResult::SUCCESS;
};

eInstrResult ModCommand::run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const
{
    if (storage->size() < 2)
    {
        throw std::runtime_error("Not enough elements in the storage to use the \'mod\' instruction!");
    }
    auto value1 = storage->top();
    storage->pop();
    auto value2 = storage->top();
    storage->pop();
    storage->push(std::shared_ptr<const operands::IOperand>{*value1 % *value2});
    return eInstrResult::SUCCESS;
};

eInstrResult PutCommand::run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const
{
    storage->push(std::shared_ptr<const operands::IOperand>{m_operand});
    return eInstrResult::SUCCESS;
};

eInstrResult AssertCommand::run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const
{
    if (storage->size() < 1)
    {
        throw std::runtime_error("Not enough elements in the storage to use the \'assert\' instruction!");
    }
    auto top_value = storage->top();
    if (*top_value != *m_operand)
    {
        throw std::runtime_error("The value on the top of the storage doesn't equal passed value.");
    }
    return eInstrResult::SUCCESS;
};

eInstrResult PrintCommand::run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const
{
    if (storage->size() < 1)
    {
        throw std::runtime_error("[ERROR] Not enough elements in the storage to use the \'print\' instruction!");
    }
    auto top_value = storage->top();
    if (top_value->getType() != operands::eOperandType::Int8)
    {
        throw std::runtime_error("[ERROR] The value on the top of the storage isn't Int8.");
    }
    std::cout << static_cast<char>(std::stoi(top_value->toString())) << std::endl;
    return eInstrResult::SUCCESS;
};

eInstrResult PopCommand::run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const
{
    if (storage->empty())
    {
        throw std::runtime_error("Not enough elements in the storage to use the \'pop\' instruction!");
    }
    storage->pop();
    return eInstrResult::SUCCESS;
};

eInstrResult SubCommand::run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const
{
    if (storage->size() < 2)
    {
        throw std::runtime_error("Not enough elements in the storage to use the \'sub\' instruction!");
    }
    auto value1 = storage->top();
    storage->pop();
    auto value2 = storage->top();
    storage->pop();
    storage->push(std::shared_ptr<const operands::IOperand>{*value1 - *value2});
    return eInstrResult::SUCCESS;
};

eInstrResult EndCommand::run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>) const
{
    return eInstrResult::END;
};

eInstrResult TraceCommand::run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const
{
    auto storage_copy = *storage;
    while (!storage_copy.empty())
    {
        std::cout << storage_copy.top()->toString() << std::endl;
        storage_copy.pop();
    };
    return eInstrResult::SUCCESS;
};

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
