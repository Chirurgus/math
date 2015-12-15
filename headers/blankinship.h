#ifndef GUARD_BLANKINSHIP_H
#define GUARD_BLANKINSHIP_H

#include <vector>

#include "matrix.h"

template<class Ty>
Ty gcd(Ty &a, Ty &b) {

	while (b != 0 && a != 0) {

		if (a >= b)
			a -= b;
		else
			b -= a;

		}

	if(a == 0)
		a = b;
	

	return a;
}

template<class Ty>
std:::vector<Ty> blankinship(Ty &a, Ty &b) {

	matrix<Ty> mtx(3, 1);
	matrix<Ty> mtx1(3, 1);

	mtx[0][0] = 1;	mtx1[0][0] = 0;
	mtx[1][0] = 0;	mtx1[1][0] = 1;
	mtx[2][0] = a;	mtx1[2][0] = b;


	while (mtx1[2][0] != 0 && mtx[2][0] != 0) {

		if (mtx[2][0] >= mtx1[2][0])
			mtx = mtx - mtx1;
		else
			mtx1 = mtx1 - mtx;

	}

	if (mtx[2][0] == 0)
		mtx = mtx1;


	return mtx[2][0];
	cout << "also, the Bezout coefficients are:" << mtx[0][0] << ", " << mtx[1][0] << endl;
}


#endif
