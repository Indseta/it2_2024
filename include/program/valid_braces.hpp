#pragma once

#include <string>
#include <vector>

bool valid_braces(std::string braces) {
    std::vector<char> expected;

    for (const auto &b : braces) {
        switch (b) {
        case '{':
            expected.push_back('}');
            break;
        case '[':
            expected.push_back(']');
            break;
        case '(':
            expected.push_back(')');
            break;
        case '}':
        case ']':
        case ')':
            if (expected.back() == b) {
                expected.erase(expected.end());
            } else {
                return false;
            }
            break;
        }
    }

    return true;
}