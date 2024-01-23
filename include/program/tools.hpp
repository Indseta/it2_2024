#pragma once

#include <iostream>
#include <vector>

std::vector<int> range(int start, int end, int step = 1) {
    std::vector<int> outv;
    if (end == start) {
    } else if (end > start) {
        for (int i = start; i < end; i += step) {
            outv.push_back(i);
        }
    } else if (end < start) {
    }

    return outv;
}


std::vector<int> range(int n) {
    return range(0, n);
}