#include <iostream>

#include "controller.hpp"

int main(int argc, char* argv[])
{
    std::cout << "[main] Start program\n";
    elemvm::ElementaryVM vm;
    auto result = vm.run(argc, argv);
    std::cout << "[main] End program\n";
    return result;
};
