#include "std_lib_facilities.h"
#include "utilities.h"
#include <random>

// BEGIN: 5a
int randomWithLimits(int lowLim, int highLim){
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(lowLim, highLim);
    int number = distribution(generator);
    return number;
}
// END: 5a