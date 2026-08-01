#pragma once
#include <iostream>
#include <exception>

// BEGIN 5a

// END 5a
class MyArray
{
    private:
        // BEGIN 5b

        // END 5b
    public:
        // BEGIN 5c
 int getSize() const {
        return Size;
    }
    Type& at(int index) {
        if (index < 0 || index >= Size) {
            throw std::out_of_range(
                "Indeks " + std::to_string(index) +
                " er utenfor arrayet med størrelse " +
                std::to_string(Size)
            );
        }
        return elements[index];
    }
    void fill(const Type& value) {
        for (int i = 0; i < Size; ++i) {
            elements[i] = value;
        }
    }
        // END 5c
};

// BEGIN 5d

// END 5d