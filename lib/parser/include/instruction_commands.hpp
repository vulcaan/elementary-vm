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
    virtual bool run(std::shared_ptr<std::stack<int>> storage) const override;
};
class PutCommand : public ICommand
{
public:
    PutCommand(int value)
        : m_value(value){};
    virtual bool run(std::shared_ptr<std::stack<int>> storage) const override;

private:
    int m_value;
};

class PopCommand : public ICommand
{
public:
    PopCommand() = default;
    virtual bool run(std::shared_ptr<std::stack<int>> storage) const override;
};

class SubCommand : public ICommand
{
public:
    SubCommand() = default;
    virtual bool run(std::shared_ptr<std::stack<int>> storage) const override;
};

class AssertCommand : public ICommand
{
public:
    AssertCommand(int value)
        : m_value(value){};
    virtual bool run(std::shared_ptr<std::stack<int>> storage) const override;

private:
    int m_value;
};

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
