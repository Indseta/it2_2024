#pragma once


#include <iostream>
#include <vector>


void print(int osv, int indl = 0) {
    for (int i = 0; i < indl; i++) {
        std::cout << '\t';
    }

    std::cout << osv << '\n';
}


template<typename T>
void print(std::vector<T> osv, int indl = 0) {
    for (int i = 0; i < indl; i++) {
        std::cout << '\t';
    }
    std::cout << "{" << '\n';

    for (const auto &o : osv) {
        for (int i = 0; i < indl; i++) {
            std::cout << '\t';
        }

        print(o, true, indl + 1);
    }

    for (int i = 0; i < indl; i++) {
        std::cout << '\t';
    }
    std::cout << "}" << '\n';
}


std::vector<int> range(int start, int stop, int step = 1) {
    std::vector<int> outv;

    if (stop != start) {
        if (stop > start) {
            for (int i = start; i < stop; i += step) {
                outv.push_back(i);
            }
        } else if (stop < start) {
            for (int i = start; i > stop; i -= step) {
                outv.push_back(i);
            }
        }
    }

    return outv;
}


std::vector<int> range(int n) {
    return range(0, n, 1);
}