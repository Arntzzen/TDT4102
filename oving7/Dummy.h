#pragma once
#include <utility>

class Dummy {
public:
    int *num;

    Dummy() {
        num = new int{0};
    }
    // BEGIN: 3c
    Dummy(const Dummy& rhs) {
        num = new int{ *rhs.num };
    }
    // END: 3c

    // Copy-Swap: Tar inn rhs som kopi, bytter medlemsvariable
    // BEGIN: 3d
	Dummy& operator=(const Dummy& rhs) {

    if (this == &rhs) {     // beskytter mot self-assignment
        return *this;
    }

    delete num;             // slett gammelt minne
    num = new int{ *rhs.num };  // alloker nytt og kopier

    return *this;
}
    // END: 3d
    
    ~Dummy() {
        delete num;
    }
};

void dummyTest();