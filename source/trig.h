#ifndef GUARD_TRIG_H
#define GUARD_TRIG_H

#include "polynomial.h"
#include "misc_funcs.h"

namespace my {//Hidden under a namespace to eliviate confusion betwen this and <math.h> functions

	const double PI = 3.14159265358979323846;

	double taylor_poly_member(unsigned n);

	const Polynomial<double> sin_TAYLOR(taylor_poly_member, 10);

	const Polynomial<double> cos_TAYLOR(taylor_poly_member, 10);

	double sin(const double theta);
	double cos(const double theta);
	double tan(const double theta);
}

#endif