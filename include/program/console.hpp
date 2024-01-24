#pragma once


#include <iostream>


namespace cmd {
    void clear() {
#ifdef _WIN32
        std::system("cls");
#else
        std::system("clear");
#endif
    }

    void pause() {
#ifdef _WIN32
        std::system("pause");
#else
        std::system("echo Press any key to continue...");
        std::system("read spkset");
#endif
    }

    void newline() {
        std::cout << '\n';
    }

    void fbuffer() {
        std::cout << std::endl;
    }
}