#include "MyArray.h"

// BEGIN 5d
inline void testMyArray() {
    // Test med int-array av størrelse 5
    MyArray<int, 5> intArr;
    intArr.fill(7);
    std::cout << "MyArray<int, 5> fylt med 7:\n";
    for (int i = 0; i < intArr.getSize(); ++i) {
        std::cout << intArr.at(i) << " ";
    }
    std::cout << "\n";

    // Test med double-array av størrelse 3
    MyArray<double, 3> dblArr;
    dblArr.fill(3.14);
    std::cout << "MyArray<double, 3> fylt med 3.14:\n";
    for (int i = 0; i < dblArr.getSize(); ++i) {
        std::cout << dblArr.at(i) << " ";
    }
    std::cout << "\n";

    // Test unntak – gyldig og ugyldig indeks
    try {
        std::cout << "Gyldig aksess [2]: " << dblArr.at(2) << "\n";
        std::cout << "Ugyldig aksess [10]:\n";
        dblArr.at(10); // Skal kaste unntak
    } catch (const std::out_of_range& e) {
        std::cout << "Unntak fanget: " << e.what() << "\n";
    }
}
// END 5d