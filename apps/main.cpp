#include <iostream>

#include "controller.hpp"

int main(int argc, char* argv[])
{
    elemvm::ElementaryVM vm;
    auto result = vm.run(argc, argv);
    return result;
};
