#include "Stopwatch.h"
#include <memory>
#include <array>
#include <iostream>


// BEGIN 1a
inline double measurePerformanceUnique() {
    Stopwatch sw;
    const int iterations = 1000000;
    sw.start();
    for (int i = 0; i < iterations; i++) {
        std::unique_ptr<int> ptr = std::make_unique<int>(i);
    }
    sw.stop();
    return sw.elapsed() / iterations;
}

inline double measurePerformanceShared() {
    Stopwatch sw;
    const int iterations = 1000000;
    sw.start();
    for (int i = 0; i < iterations; i++) {
        std::shared_ptr<int> ptr = std::make_shared<int>(i);
    }
    sw.stop();
    return sw.elapsed() / iterations;
}

inline double measurePerformanceStack() {
    Stopwatch sw;
    const int iterations = 10000;
    constexpr int size = 10000;
    sw.start();
    for (int i = 0; i < iterations; i++) {
        std::array<int, size> arr1;
        (void)arr1;
    }
    sw.stop();
    return sw.elapsed() / iterations;
}

inline double measurePerformanceHeap() {
    Stopwatch sw;
    const int iterations = 10000;
    constexpr int size = 10000;
    sw.start();
    for (int i = 0; i < iterations; i++) {
        std::array<int, size>* arr2 = new std::array<int, size>;
        delete arr2;
    }
    sw.stop();
    return sw.elapsed() / iterations;
}
// END 1a