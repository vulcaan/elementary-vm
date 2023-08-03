#ifndef ELEMVM_LIB_CONTROLLER_INCLUDE_CONTROLLER_HPP_
#define ELEMVM_LIB_CONTROLLER_INCLUDE_CONTROLLER_HPP_
#include <iostream>
#include <memory>
#include <stack>

namespace elemvm
{
namespace operands
{
class IOperand;
}
namespace parsing::cli
{
class IParser;
}
class ElementaryVM
{
public:
    ElementaryVM();
    ElementaryVM(std::unique_ptr<parsing::cli::IParser> parser);
    int run(int argc, char* argv[]);
    void setOut(std::ostream& out);
    ~ElementaryVM();

private:
    std::unique_ptr<parsing::cli::IParser> configureParser();

    std::unique_ptr<parsing::cli::IParser> m_cli_parser;
    std::ostream& m_out;
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> m_storage;
};
}  // namespace elemvm
#endif  // ELEMVM_LIB_CONTROLLER_INCLUDE_CONTROLLER_HPP_
