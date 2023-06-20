#pragma once
#include <stack>
#include <memory>
namespace elemvm
{
namespace parsing
{
namespace cli
{
class ICommand
{
public:
    virtual bool run(std::shared_ptr<std::stack<int>> storage) const = 0;
    virtual ~ICommand(){};
};
}  // namespace cli
namespace instructions
{
class ICommand
{
public:
    virtual bool run(std::shared_ptr<std::stack<int>> storage) const = 0;
    virtual ~ICommand(){};
};
}  // namespace instructions

}  // namespace parsing
}  // namespace elemvm
