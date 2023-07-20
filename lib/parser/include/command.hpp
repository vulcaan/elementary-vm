#pragma once
#include <memory>
#include <stack>
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
enum class InstrResult
{
    SUCCESS,
    END,
    ERROR
};
class ICommand
{
public:
    virtual InstrResult run(std::shared_ptr<std::stack<int>> storage) const = 0;
    virtual ~ICommand(){};
};

}  // namespace instructions

}  // namespace parsing
}  // namespace elemvm
