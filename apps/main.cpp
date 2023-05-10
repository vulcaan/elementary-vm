#include <functional>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "parser.hpp"
#include "reader.hpp"

int main(int argc, char* argv[])
{
    try
    {
        switch (argc)
        {
        case 2:
            if (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help")
            {
                std::cout << argv[0] << "[options]" << std::endl
                          << "Options:" << std::endl
                          << "-h                    Print this help" << std::endl
                          << "-i                    Get commands from a console (## to end)" << std::endl
                          << "-f <path-to-file>     Get commands from a file" << std::endl;
            }
            else if (std::string(argv[1]) == "-i")
            {
                std::stack<int32_t> storage;
                std::unordered_map<std::string, std::function<void(std::vector<std::string>)>> commands_1{
                    {"put", [](std::vector<std::string> ar)
                     {
                         for (auto x : ar)
                         {
                             std::cout << x << '|';
                         }
                         std::cout << std::endl;
                     }},
                    {"assert", [](std::vector<std::string> ar)
                     {
                         for (auto x : ar)
                         {
                             std::cout << x << '|';
                         }
                         std::cout << std::endl;
                     }},
                };
                std::unordered_map<std::string, std::function<void()>> commands_2{
                    {"add", []()
                     {
                         std::cout << "add" << std::endl;
                     }},
                    {"sub", []()
                     {
                         std::cout << "sub" << std::endl;
                     }},
                    {"pop", []()
                     {
                         std::cout << "pop" << std::endl;
                     }},
                    {"##", []()
                     {
                         std::cout << "##" << std::endl;
                     }},
                };
                std::stringstream input;
                input << Reader::read_from_console();
                std::string line;
                std::size_t line_counter = 1;
                while (std::getline(input, line))
                {
                    auto parsed_line = Parser::parse(line);
                    if (parsed_line[0] != "")
                    {
                        try
                        {
                            commands_1[parsed_line[0]](std::vector<std::string>(parsed_line.begin() + 1, parsed_line.end()));
                        }
                        catch (...)
                        {
                            std::cout << "Wrong command at line " << line_counter << std::endl;
                        }
                    }
                    line_counter++;
                    std::cout << std::endl;
                }
            }
            else
            {
                std::cout << "Wrong usage, please use \'-h\' to get list of arguments"
                          << std::endl;
            }
            break;
        case 3:
            if (std::string(argv[1]) == "-f")
            {
                std::stringstream input;
                input << Reader::read_from_file(std::string(argv[2]));
                Parser parser;
                std::string line;
                std::stack<int32_t> storage;
                std::size_t line_counter = 1;
                std::unordered_map<std::string, std::function<void(std::vector<std::string>)>> commands_2{
                    {"put", [](std::vector<std::string> ar)
                     {
                         for (auto x : ar)
                         {
                             std::cout << x << '|';
                         }
                         std::cout << std::endl;
                     }},
                    {"assert", [](std::vector<std::string> ar)
                     {
                         for (auto x : ar)
                         {
                             std::cout << x << '|';
                         }
                         std::cout << std::endl;
                     }},
                };
                std::unordered_map<std::string, std::function<void()>> commands_1{
                    {"add", []()
                     {
                         std::cout << "add" << std::endl;
                     }},
                    {"sub", []()
                     {
                         std::cout << "sub" << std::endl;
                     }},
                    {"pop", []()
                     {
                         std::cout << "pop" << std::endl;
                     }},
                    {"##", []()
                     {
                         std::cout << "##" << std::endl;
                     }},
                };
                while (std::getline(input, line))
                {
                    // seg fault on first blank line
                    // make bruteforce then enhance
                    auto parsed_line = parser.parse(line);
                    for (auto x : parsed_line)
                    {
                        std::cout << x << '|';
                    }
                    std::cout << std::endl;
                    try
                    {
                        switch (parsed_line.size())
                        {
                        case 1:
                            if (parsed_line[0] != "")
                                continue;
                            commands_1[parsed_line[0]]();
                            break;
                        case 2:
                            commands_2[parsed_line[0]](std::vector<std::string>(parsed_line.begin() + 1, parsed_line.end()));
                            break;
                        default:
                            throw std::runtime_error("");
                        }
                    }
                    catch (...)
                    {
                        std::cout << "Wrong command at line " << line_counter << std::endl;
                    }
                    line_counter++;
                }
            }
            else
            {
                std::cout << "Wrong usage, please use \'-h\' to get list of arguments"
                          << std::endl;
            }
            break;
        default:
            std::cout << "Wrong usage, please use \'-h\' to get list of arguments"
                      << std::endl;
        }
    }
    catch (const std::runtime_error& error)
    {
        std::cout << error.what() << std::endl;
    }
}
