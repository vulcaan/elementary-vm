#ifndef ELEMVM_LIB_PARSER_INCLUDE_INSTRUCTION_COMMANDS_HPP_
#define ELEMVM_LIB_PARSER_INCLUDE_INSTRUCTION_COMMANDS_HPP_
#include <memory>
#include <stack>

#include "instruction/icomplex.hpp"
#include "instruction/itrivial.hpp"

namespace elemvm
{
namespace operands
{
class IOperand;
}
namespace parsing
{
namespace instructions
{
class AddCommand : public ITrivial
{
public:
    virtual eInstrResult run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const override;
};

class MulCommand : public ITrivial
{
public:
    virtual eInstrResult run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const override;
};

class DivCommand : public ITrivial
{
public:
    virtual eInstrResult run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const override;
};

class ModCommand : public ITrivial
{
public:
    virtual eInstrResult run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const override;
};

class PutCommand : public IComplex
{
public:
    using IComplex::IComplex;
    virtual eInstrResult run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const override;
};

class PopCommand : public ITrivial
{
public:
    virtual eInstrResult run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const override;
};

class SubCommand : public ITrivial
{
public:
    virtual eInstrResult run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const override;
};

class PrintCommand : public ITrivial
{
public:
    virtual eInstrResult run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const override;
};

class TraceCommand : public ITrivial
{
public:
    virtual eInstrResult run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const override;
};

class AssertCommand : public IComplex
{
public:
    using IComplex::IComplex;
    virtual eInstrResult run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const override;
};

class EndCommand : public ITrivial
{
public:
    virtual eInstrResult run(std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> storage) const override;
};

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
#endif  // ELEMVM_LIB_PARSER_INCLUDE_INSTRUCTION_COMMANDS_HPP_
