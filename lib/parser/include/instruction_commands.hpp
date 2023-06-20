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
    AddCommand(int value)
        : m_value(value){};
    virtual bool run(std::shared_ptr<std::stack<int>> storage) const override;

private:
    int m_value;
};

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
