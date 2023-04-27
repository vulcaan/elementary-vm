#include <iostream>
#include <string>
#include <stdexcept>

#include "reader.hpp"


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
                std::cout << reader::read_from_console() << std::endl;
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
                std::cout << reader::read_from_file(std::string(argv[2])) << std::endl;
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
