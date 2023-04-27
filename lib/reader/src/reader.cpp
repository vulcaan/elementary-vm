#include "reader.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

std::string reader::read_from_console(const std::string &stop)
{
    std::string input;
    std::string output;
    std::cout << "Enter commands, type \'" << stop << "\' to exit:\n";
    while (std::getline(std::cin, input))
    {
        output += input+'\n';
        if (input == stop)
        {
            break;
        }
    }
    return output;
}

std::string reader::read_from_file(const std::string &filename)
{
    std::ifstream file(filename);
    std::string content;
    if (file)
    {
        content = std::string((std::istreambuf_iterator<char>(file)),
                              (std::istreambuf_iterator<char>()));
    }
    else
    {
        std::stringstream ss;
        ss << "Error: Could not open file '" << filename << "'\n";
        throw std::runtime_error(ss.str());
    }
    return content;
}
