#ifndef GUARD_MATRIX_VECTOR_H
#define GUARD_MATRIX_VECTOR_H
/*Old implimentation of Matrix, uses STL vectors, and still turned out to be MANY MANY
times slower then its other implementations.

It's also hidden under a namespace to prevent overloading while testing.*/
#include <vector>

namespace vector
{
	template<class Ty> class Matrix {

	public:
		typedef unsigned size_type;

		/*Matrix Default Constructor*/
		Matrix<Ty>() : Matrix<Ty>(1, 1) { }

		/*Matrix Constructor, taking _height(ht) and _width(wd) as arguments*/
		Matrix<Ty>(size_type ht, size_type wd, const Ty &inital_value = Ty()):
			_height(ht),
			_width(wd),
			_mtx(_height * _width, inital_value)
		{ }

		/*Matrix Copy Constructor*/
		Matrix<Ty>(const Matrix &old_mtx):
			_height(old_mtx._height),
			_width(old_mtx._width),
			_mtx(old_mtx._mtx)
		{ }

		/*Copy Assignment Cperator*/
		Matrix<Ty> &operator= (const Matrix &old_mtx) {
			this->_height = old_mtx._height;
			this->_width = old_mtx._width;
			this->_mtx = old_mtx._mtx;
			return *this;
		}

		/*Destructor*/
		~Matrix<Ty>() { }


		/*Interface*/

		/*Getters*/
		unsigned GetHeight();
		unsigned GetWidth();

		unsigned GetHeight()const;
		unsigned GetWidth()const;


		/*Operators*/

		/*Subscript Operators*/
		Ty& operator() (const size_type i_pos, const size_type j_pos);
		Ty& operator() (const size_type i_pos, const size_type j_pos) const;

		/*Addition Operatosr*/
		Matrix<Ty> &operator+= (const Matrix &rhs_mtx);
		Matrix<Ty> operator+ (const Matrix &rhs_mtx) const;

		/*Substration Operators*/
		Matrix<Ty> &operator-= (const Matrix &rhs_mtx);
		Matrix<Ty> operator- (const Matrix &rhs_mtx) const;

		/*Multiplication Operators*/
		Matrix<Ty> &operator*= (const Matrix &rhs_mtx);
		Matrix<Ty> operator* (const Matrix &rhs_mtx) const;



	private:
		size_type _height;
		size_type _width;
		std::vector<Ty> _mtx;
	};

	/*Non-Member funcitons*/

	/* Multiplicators by a scalar */
	template<class Ty>
	Matrix<Ty> operator* (const Ty &scalar, const Matrix<Ty> &mtx);

	template<class Ty>
	Matrix<Ty> operator* (const Matrix<Ty> &mtx, const Ty &scalar);

	template<class Ty>
	Matrix<Ty>& operator*= (Matrix<Ty> &mtx, const Ty &scalar);

	/* Trace */
	template<class Ty>
	Ty tr(const Matrix<Ty> &mtx);

	/* Basic line operations */
	template<class Ty>
	Matrix<Ty>& swap_lines(Matrix<Ty> &mtx,
		typename Matrix<Ty>::size_type L1,
		typename Matrix<Ty>::size_type L2);

	template<class Ty>
	Matrix<Ty>& swap_columns(Matrix<Ty> &mtx,
		typename Matrix<Ty>::size_type C1,
		typename Matrix<Ty>::size_type C2);

	template<class Ty>
	Matrix<Ty>& scale_a_line(Matrix<Ty> &mtx,
		typename Matrix<Ty>::size_type L1,
		const Ty &coef);

	template<class Ty>
	Matrix<Ty>& add_lines(Matrix<Ty> &mtx,
		typename Matrix<Ty>::size_type L1,
		typename Matrix<Ty>::size_type L2,
		const Ty &coef);

	template<class Ty>
	Matrix<Ty>& substract_lines(Matrix<Ty> &mtx,
		typename Matrix<Ty>::size_type L1,
		typename  Matrix<Ty>::size_type L2,
		const Ty &coef);

}
#include "matrix_vector.cpp"

#endif
