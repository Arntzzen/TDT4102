#include "Stopwatch.h"
#include "optimizeVector.h"
#include <vector>
#include <iostream>


// BEGIN 2a
void testVector() {
    std::vector<int> v;
    for (int i = 0; i < 20; i++) {
        v.push_back(i);
        std::cout << "size: " << v.size()
                  << ", capacity: " << v.capacity() << "\n";
    }
}
// END 2a


void optimizeVector()
    // BEGIN 2d
    void measureVectorPushBack() {
    Stopwatch sw;
    std::vector<int> v;
    sw.start();
    for (int i = 0; i < 1000000; i++) {
        v.push_back(i);
    }
    sw.stop();
    std::cout << "Oppgave 2d: " << sw.elapsed() << "\n";
}
    // END 2d

    // BEGIN 2e
    void measureVectorOptimized() {
    // Med reserve
    {
        Stopwatch sw;
        std::vector<int> v;
        v.reserve(1000000);
        sw.start();
        for (int i = 0; i < 1000000; i++) {
            v.push_back(i);
        }
        sw.stop();
        std::cout << "Oppgave 2e (reserve): " << sw.elapsed() << "\n";
    }
    // END 2e   
}