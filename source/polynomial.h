#ifndef GUARD_POLYNOMIAL_H
#define GUARD_POLYNOMIAL_H

#include <vector>

template<class Ty> class Polynomial {
public:
	typedef unsigned size_type;

	Polynomial<Ty>() {}

	Polynomial<Ty>(size_type size):_coefs(size) {}

	Polynomial<Ty>(size_type size, Ty &inital_val) : _coef(size, inital_val) {}

	size_type deg() { return _coefs.size() - 1; }

	Ty poly_func(Ty val){
		Ty ret = Ty();//Hope this will be equal to zero for int, float and co.
		for (size_type i = 0; i < _coefs; i++)
			ret += _coefs[i] * pow(val, i);
		return ret;
	}
private:
	std::vector<Ty> _coefs;
};

#endif
