#ifndef GUARD_MATRIX_POINTERS_H
#define GUARD_MATRIX_POINTERS_H
/*Old implimentation of Matrix, creates array of arrays, turned out to be slower
then one-dimentional matrix.

It's also hidden under a namespace to prevent overloading while testing.*/

namespace nested_dynamic_arrays {
	template<class Ty> class Matrix {

	public:
		typedef unsigned size_type;

		/*Matrix Default Constructor*/
		Matrix<Ty>() : Matrix<Ty>(1, 1) { }

		/*Matrix Constructor, taking _height(ht) and _width(wd) as arguments*/
		Matrix<Ty>(size_type ht, size_type wd, const Ty &inital_value = Ty()) {
			arrayAllocator(ht, wd);
			for (size_type i = 0; i < _height; i++)
				for (size_type j = 0; j < _width; j++)
					(*this)(i, j) = inital_value;
		}

		/*Matrix Copy Constructor*/
		Matrix<Ty>(const Matrix &old_mtx) {
			arrayAllocator(old_mtx._height, old_mtx._width);
			for (size_type i = 0; i < _height; i++)
				for (size_type j = 0; j < _width; j++)
					_mtx[i][j] = old_mtx._mtx[i][j];
		}

		/*Copy Assignment Cperator*/
		Matrix<Ty> &operator= (const Matrix &old_mtx) {
			if (this != &old_mtx) {
				arrayDelocator(_height);
				arrayAllocator(old_mtx._height, old_mtx._width);
				for (size_type i = 0; i < _height; i++)
					for (size_type j = 0; j < _width; j++)
						this->_mtx[i][j] = old_mtx._mtx[i][j];
			}
			return *this;//This is supposed to return a reference to this object, not an instance of the object, but it seems that C++ should add & implicity
		}

		/*Destructor*/
		~Matrix<Ty>() {
			arrayDelocator(_height);
		}


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
		Ty** _mtx;

		/*Memory allocator*/
		void arrayAllocator(size_type ht, size_type wd) {
			_height = ht;
			_width = wd;
			_mtx = new Ty*[_height];
			for (size_type i = 0; i < _height; i++)
				_mtx[i] = new Ty[_width];
		}

		/*Memory freeyer*/
		void arrayDelocator(const size_type _height) {
			for (size_type i = 0; i < _height; i++)
				delete[] _mtx[i];
			delete[] _mtx;
		}
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
#include "matrix_pointers.cpp"

#endif
