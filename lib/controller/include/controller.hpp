#pragma once
#include <iostream>

#include "cli_parser.hpp"

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

    std::shared_ptr<std::stack<int>> m_storage;
};
}  // namespace elemvm
