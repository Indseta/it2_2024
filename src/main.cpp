#include <program/console.hpp>
#include <program/application.hpp>

#include <cstdlib>
#include <iostream>
#include <stdexcept>


int main() {
    cmd::clear();

    try {
        run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}