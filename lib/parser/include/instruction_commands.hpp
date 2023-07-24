#pragma once

#include "command.hpp"

namespace elemvm
{
namespace parsing
{
namespace instructions
{
class AddCommand : public ICommand
{
public:
    AddCommand() = default;
    virtual InstrResult run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const override;
};

class MulCommand : public ICommand
{
public:
    MulCommand() = default;
    virtual InstrResult run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const override;
};

class DivCommand : public ICommand
{
public:
    DivCommand() = default;
    virtual InstrResult run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const override;
};

class PutCommand : public ICommand
{
public:
    PutCommand(std::shared_ptr<const operands::IOperand> value)
        : m_value(value){};
    virtual InstrResult run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const override;

private:
    std::shared_ptr<const operands::IOperand> m_value;
};

class PopCommand : public ICommand
{
public:
    PopCommand() = default;
    virtual InstrResult run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const override;
};

class SubCommand : public ICommand
{
public:
    SubCommand() = default;
    virtual InstrResult run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const override;
};

class AssertCommand : public ICommand
{
public:
    AssertCommand(std::shared_ptr<const operands::IOperand> value)
        : m_value(value){};
    virtual InstrResult run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const override;

private:
    std::shared_ptr<const operands::IOperand> m_value;
};

class EndCommand : public ICommand
{
public:
    EndCommand() = default;
    virtual InstrResult run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const override;
};

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
