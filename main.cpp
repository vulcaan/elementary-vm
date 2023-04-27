#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

#include "reader.hpp"
#include "parser.hpp"

int main(int argc, char *argv[])
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
                std::stringstream input;
                input << reader::read_from_console();
                Parser parser;
                std::string line;
                while (std::getline(input, line))
                    for (auto i : parser.parse(line))
                    {
                        std::cout << i << std::endl;
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
                input << reader::read_from_file(std::string(argv[2]));
                Parser parser;
                std::string line;
                while (std::getline(input, line))
                    for (auto i : parser.parse(line))
                    {
                        std::cout << i << std::endl;
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
    catch (const std::runtime_error &error)
    {
        std::cout << error.what() << std::endl;
    }
}
