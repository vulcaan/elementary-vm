#pragma once

namespace elemvm
{
namespace parsing
{
    
class ICommand
{
public:
    virtual bool run() const = 0;
    virtual ~ICommand() = default;
};

}  // namespace parsing
}  // namespace elemvm
