#ifndef ELEMVM_INSTRUCTION_COMMANDS_HPP
#define ELEMVM_INSTRUCTION_COMMANDS_HPP

#include "instruction/icomplex.hpp"
#include "instruction/itrivial.hpp"

namespace elemvm
{
namespace parsing
{
namespace instructions
{
class AddCommand : public ITrivial
{
public:
    AddCommand() = default;
    virtual eInstrResult run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const override;
};

class MulCommand : public ITrivial
{
public:
    MulCommand() = default;
    virtual eInstrResult run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const override;
};

class DivCommand : public ITrivial
{
public:
    DivCommand() = default;
    virtual eInstrResult run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const override;
};

class ModCommand : public ITrivial
{
public:
    ModCommand() = default;
    virtual eInstrResult run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const override;
};

class PutCommand : public IComplex
{
public:
    using IComplex::IComplex;
    virtual eInstrResult run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const override;
};

class PopCommand : public ITrivial
{
public:
    PopCommand() = default;
    virtual eInstrResult run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const override;
};

class SubCommand : public ITrivial
{
public:
    SubCommand() = default;
    virtual eInstrResult run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const override;
};

class PrintCommand : public ITrivial
{
public:
    PrintCommand() = default;
    virtual eInstrResult run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const override;
};

class TraceCommand : public ITrivial
{
public:
    TraceCommand() = default;
    virtual eInstrResult run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const override;
};

class AssertCommand : public IComplex
{
public:
    using IComplex::IComplex;
    virtual eInstrResult run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const override;
};

class EndCommand : public ITrivial
{
public:
    EndCommand() = default;
    virtual eInstrResult run(
        std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>>
            storage) const override;
};

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
#endif  // ELEMVM_INSTRUCTION_COMMANDS_HPP
