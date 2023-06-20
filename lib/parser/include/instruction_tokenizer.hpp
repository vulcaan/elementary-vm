#pragma once
#include "tokenizer.hpp"

namespace elemvm
{
namespace parsing
{
namespace instructions
{

class InstructionTokenizer : public ITokenizer
{
public:
    virtual std::vector<std::string> tokenize(
        const std::string & instruction) const override;

private:
    std::vector<std::string> split(const std::string & line,
                                        char delimiter) const;
    std::string remove_comment(const std::string & line, char symbol) const;
};

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
