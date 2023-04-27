#include <iostream>
#include <string>

int main(int argc, char *argv[])
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
            std::cout << "Interactive input" << std::endl;
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
            std::cout << "Input from the file: " << std::string(argv[2]) << std::endl;
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