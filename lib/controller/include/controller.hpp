#ifndef ELEMVM_CONTROLLER_HPP
#define ELEMVM_CONTROLLER_HPP
#include <iostream>

#include "cli/parser.hpp"
#include "ioperand.hpp"

namespace elemvm
{
namespace pc = parsing::cli;
class ElementaryVM
{
public:
    ElementaryVM();
    ElementaryVM(std::unique_ptr<parsing::cli::IParser> parser)
        : m_cli_parser(std::move(parser))
        , m_out(std::cout){};
    int run(int argc, char* argv[]);
    void setOut(std::ostream& out);

private:
    std::unique_ptr<parsing::cli::IParser> m_cli_parser;
    std::ostream& m_out;
    std::shared_ptr<std::stack<std::shared_ptr<const operands::IOperand>>> m_storage;
    std::unique_ptr<parsing::cli::IParser> configureParser();
};
}  // namespace elemvm
#endif  // ELEMVM_CONTROLLER_HPP
