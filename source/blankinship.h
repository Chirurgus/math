#ifndef GUARD_BLANKINSHIP_H
#define GUARD_BLANKINSHIP_H

#include "matrix.h"

#include <vector>
template<class Ty>
Ty gcd(Ty a, Ty b) {
	const Ty zero_equivalent();

	while (b != zero_equivalent && a != zero_equivalent) {

		if (a >= b)
			a -= b;
		else
			b -= a;

		}

	if(a == zero_equivalent)
		a = b;

	return a;
}

template<class Ty>
std::vector<Ty> blankinship(Ty a, Ty b) {
	Matrix<Ty> mtx0 = { {1},
						{0},
						{a} };
	Matrix<Ty> mtx1 = { {0},
						{1},
						{b} };

	while (mtx1(2, 0) != 0 && mtx0(2, 0) != 0) {

		if (mtx0(2, 0) >= mtx1(2, 0))
			mtx0 = mtx0 - mtx1;
		else
			mtx1 = mtx1 - mtx0;

	}

	if (mtx0(2, 0) == 0)
		mtx0 = mtx1;


	return std::vector<Ty>{ mtx0(0, 0), mtx0(1, 0) };
	}


#endif
