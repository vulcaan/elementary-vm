#ifndef READER_HPP
#define READER_HPP
#include <string>
namespace reader
{
    std::string read_from_console(const std::string &stop = "##");

    std::string read_from_file(const std::string &filename);
}

#endif // READER_HPP
