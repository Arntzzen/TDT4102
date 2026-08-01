#pragma once
#include <random>
#include <iostream>
#include <string>
#include <vector>

// BEGIN 4a
template<typename T>
T maximum(T lhs, T rhs) {
    return (lhs > rhs) ? lhs : rhs;
}
// END 4a

// BEGIN 4b
template<typename T>
void shuffle(std::vector<T>& v) {
    for (int i = static_cast<int>(v.size()) - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(v[i], v[j]);
    }
}
// END 4b

void testTemplateFunctions();