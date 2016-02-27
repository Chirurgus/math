#ifndef GUARD_POLYNOMIAL_CPP
#define GUARD_POLYNOMIAL_CPP

#include "polynomial.h"

template<class Ty>
Ty Polynomial<Ty>::operator[](const size_type pos) const {	
	if (pos < this->_size)
		return this->_coefs[pos];
	else
		return Ty();//assumed to be zero or equivalent
}

template<class Ty>
Polynomial<Ty>& Polynomial<Ty>::operator= (const Polynomial<Ty> &rhs_poly) {
	this->_coefs = rhs_poly._coefs;
	this->_size = rhs_poly._size;
	return *this;
}

template<class Ty>
Ty Polynomial<Ty>::operator()(Ty val) const {
	Ty ret = Ty();//Hope this will be equal to zero for int, float and co.
	Polynomial<Ty>::size_type size = this->_size;
	for (Polynomial<Ty>::size_type i = 0; i < size; i++)
		ret += (*this)[i] * pow(val, i);
	return ret;
}

template<class Ty>
Polynomial<Ty> Polynomial<Ty>::operator+ (const Polynomial<Ty> &rhs_poly) {
	std::vector<Ty> ret_vec;
	Polynomial<Ty>::size_type max_size =
		this->_size > rhs_poly._size ? this->_size : rhs_poly._size;
	ret_vec.reserve(max_size);
	for (auto i = 0; i < max_size; i++)
		ret_vec.push_back(this->coef(i) + rhs_poly.coef(i));
	return Polynomial<Ty>(ret_vec);
}

template<class Ty>
Polynomial<Ty> Polynomial<Ty>::operator- (const Polynomial<Ty> &rhs_poly) {
	std::vector<Ty> ret_vec;
	Polynomial<Ty>::size_type max_size =
		this->_size > rhs_poly._size ? this->_size : rhs_poly._size;
	ret_vec.reserve(max_size);
	for (auto i = 0; i < max_size; i++)
		ret_vec.push_back((*this)[i] - rhs_poly[i]);
	return Polynomial<Ty>(ret_vec);
}

template<class Ty>
Polynomial<Ty> Polynomial<Ty>::operator* (const Polynomial<Ty> &rhs_poly) {
	Polynomial<Ty>::size_type rhs_size = rhs_poly._size,
		lhs_size = this->_size,
		ret_size = rhs_size + lhs_size;
	std::vector<Ty> ret_vec(ret_size);
	for (Polynomial<Ty>::size_type i = 0; i < lhs_size; i++)
		for (Polynomial<Ty>::size_type j = 0; j < rhs_size; j++)
			ret_vec[i + j] += (*this)[i] * rhs_poly[j];
	return Polynomial<Ty>(ret_vec);
}


/*Non-Member Functions*/
template<class Ty>
Polynomial<Ty>& operator-= (Polynomial<Ty> &lhs_poly, const Polynomial<Ty> &rhs_poly) {
	return lhs_poly = lhs_poly - rhs_poly;
}

template<class Ty>
Polynomial<Ty>& operator*= (Polynomial<Ty> &lhs_poly, const Polynomial<Ty> &rhs_poly) {
	return lhs_poly = lhs_poly * rhs_poly;
}

template<class Ty>
Polynomial<Ty>& operator+= (Polynomial<Ty> &lhs_poly, const Polynomial<Ty> &rhs_poly) {
	return lhs_poly = lhs_poly + rhs_poly;
}

#endif
