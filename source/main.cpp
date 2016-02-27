#include "polynomial.h"
#include "blankinship.h"
#include "trig.h"
#include "benchmark.h"

#include "misc_funcs.h"

#include <iostream>

int main() {
	Matrix<unsigned> mtx = { {1 , 2}, {3, 4 } };
	mtx *= mtx;
	for (unsigned i = 0; i < 2; i++)
		for (unsigned j = 0; j < 2; j++)
		std::cout << mtx(i, j) << std::endl;
	std::cout << "lets hypohteticly say i edited tis file \n";
	return 0;
}