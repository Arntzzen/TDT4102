#include "test.h"

void testCallByValue()
{
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimes(v0, increment, iterations);
	cout << "v0: " << v0 << " increment: " << increment
		 << " iterations: " << iterations << " result: " << result << '\n';
}

void testCallByReference()
{
	// BEGIN: 1d
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimesRef(v0, increment, iterations);
	cout << "v0: " << v0 << " increment: " << increment
		 << " iterations: " << iterations << " result: " << result << '\n';
	// END: 1d

}


void testString(){
	// 3b OG 3e gjøres inne i her
	// BEGIN: 3e
	string grades = randomizeString(8, 'F', 'A');
	cout << grades << endl;
	// END: 3e
}