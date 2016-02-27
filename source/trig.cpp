#include "trig.h"

#include "polynomial.h"
#include "misc_funcs.h"

namespace my {

	double sin(const double theta) {
		return sin_TAYLOR(std::fmod(theta, PI));
	}

	double cos(const double theta) {
		return cos_TAYLOR(std::fmod(theta, PI));
	}
	
	double tan(const double theta) {
		/* Yeah, I don't remember the the tan DL, and I don't feel like going and calculating it*/
		return sin(theta) / cos(theta);
	}


	double taylor_poly_member(unsigned n) {
		if (n % 2 == 0)
			return double(0.0);
		if ((n + 1) % 4 == 0)
			return -1 * double(1) / double(factorial(n));
		else
			return double(1) / double(factorial(n));
	}
}