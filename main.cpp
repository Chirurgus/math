#include "matrix_pointers.h"

#include <iostream>
#include <vector>

int main() {
	Matrix<unsigned> mtx(2,2);

	Matrix<unsigned> amtx = mtx * mtx;

	std::cout << amtx(0, 0) << ',' << amtx(0, 1) << std::endl;
	std::cout << amtx(1, 0) << ',' << amtx(1, 1) << std::endl;



	return 0;
}
