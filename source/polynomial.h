#ifndef GUARD_POLYNOMIAL_H
#define GUARD_POLYNOMIAL_H

#include <vector>
#include <initializer_list>

template<class Ty> class Polynomial {
public:
	typedef unsigned size_type;

	Polynomial<Ty>(): Polynomial<Ty>(1, Ty()) {}

	Polynomial<Ty>(size_type size,const Ty &init_val = Ty()): _coefs(size, init_val), _size(size) {}

	Polynomial<Ty>(std::initializer_list<Ty> init_list): _coefs(init_list), _size(_coefs.size()) {}

	Polynomial<Ty>(const std::vector<Ty> &init_vec): _coefs(init_vec), _size(init_vec.size()) {}

	Polynomial<Ty>(const Polynomial<Ty> &old_poly): _coefs(old_poly._coefs), _size(old_poly._size) {}

	Polynomial<Ty>(Ty series(unsigned), unsigned n) : _coefs(n), _size(n) {
		for (Polynomial<Ty>::size_type i = 0; i < n; i++) {
			Ty num = series(i);
			this->_coefs[i] = num;
		}
	}

	Polynomial<Ty>& operator= (const Polynomial<Ty> &rhs_poly);

	size_type deg() const { return _size - 1; }

	Ty operator[](const size_type pos) const;//Forwards the subscript operator to _coefs, but also return range

	Ty operator()(Ty val) const;//Used to evaluate a polynomial at a certain point.

	Polynomial<Ty> operator+(const Polynomial<Ty> &rhs_poly);

	Polynomial<Ty> operator-(const Polynomial<Ty> &rhs_poly);
	
	Polynomial<Ty> operator*(const Polynomial<Ty> &rhs_poly);

private:
	std::vector<Ty> _coefs;
	size_type _size;
};

/*Non-Member Functions*/
template<class Ty>
Polynomial<Ty>& operator+=(Polynomial<Ty> &lhs_poly, const Polynomial<Ty> &rhs_poly);

template<class Ty>
Polynomial<Ty>& operator-=(Polynomial<Ty> &lhs_poly, const Polynomial<Ty> &rhs_poly);

template<class Ty>
Polynomial<Ty>& operator*=(Polynomial<Ty> &lhs_poly, const Polynomial<Ty> &rhs_poly);

#include "polynomial.cpp"

#endif