#pragma once
#include <string_view>

namespace elemvm
{
namespace argparser
{

class ICLICommandParser
{
public:
    virtual bool parse(std::string_view command) const = 0;
    virtual ~ICLICommandParser() = default;
};

class HelpCommandParser : public ICLICommandParser
{
public:
    virtual bool parse(std::string_view command) const override;
};

class InputFromFileCommand : public ICLICommandParser
{
public:
    virtual bool parse(std::string_view command) const override;
};

class InputInteractiveCommandParser : public ICLICommandParser
{
public:
    virtual bool parse(std::string_view command) const override;
};

}  // namespace argparser
}  // namespace elemvm
