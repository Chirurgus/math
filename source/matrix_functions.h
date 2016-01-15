#ifndef GUARD_MATRIX_FUNCTIONS_H 
#define GUARD_MATRIX_FUCNTIONS_H
/* I decided to to implement these functions in
a different file because these functions might be 
pretty expensive to call. */
#include "matrix_pointers.h"

#include <iostream>

template<class Ty> Ty det(const Matrix<Ty> &mtx) {
	return Ty();
}

template<class Ty> Matrix<Ty> gauss(std::ostream& os, Matrix<Ty> &mtx) {
	Matrix<Ty> ret_mtx = mtx;

	Matrix<Ty>::size_type width = ret_mtx.GetWidth();
	Matrix<Ty>::size_type height = ret_mtx.GetHeight();

	Matrix<Ty>::size_type count;

	Matrix<Ty>::size_type limit = height >= width ? width : height;

	write(std::cout, ret_mtx);
	std::cout << std::endl;

	for (Matrix<Ty>::size_type count = 0; count < limit; count++) {

		Ty max_val = 0;
		Matrix<Ty>::size_type max_row;
		for (Matrix<Ty>::size_type i = 0; i < height; i++) {
			if (ret_mtx(i, count) > max_val) {
				max_val = ret_mtx(i, count);
				max_row = i;
			}
		}

		if (max_val == 0)
			continue;

		swap_lines(ret_mtx, max_row, count);

		write(std::cout, ret_mtx);
		std::cout << std::endl;

		scale_a_line(ret_mtx, count, 1 / ret_mtx(count, count));

		write(std::cout, ret_mtx);
		std::cout << std::endl;

		for (Matrix<Ty>::size_type i = 0; i < height; i++) {
			if (i == count)
				continue;
			substract_lines(ret_mtx, i, count, 1*ret_mtx(i, count));
			/*ARGH OMG, substract_lines(and add_lines works as intended only if
			the last argument i give it is multi;lied by 1, idk why, i tried 
			passing it to the function by Ty(ret_mtx(i, count)) didn't work either*/
		}

		write(std::cout, ret_mtx);
		std::cout << std::endl;
	}
	
	return ret_mtx;
}

template<class Ty> std::ostream& write(std::ostream &os,const Matrix<Ty> &mtx) {
	Matrix<Ty>::size_type width = mtx.GetWidth();
	Matrix<Ty>::size_type height = mtx.GetHeight();

	for (Matrix<Ty>::size_type i = 0; i < height; i++) {
		os << "|   ";
		for (Matrix<Ty>::size_type j = 0; j < width; j++) {
			os << mtx[i][j] << "   ";
		}
		os << '|' << std::endl;
	}

	return os;
}

#endif