#ifndef MATRIX_POINTERS_CPP
#define MATRIX_POINTERS_CPP

#include "matrix_pointers.h"
namespace nested_dynamic_arrays {
	/*Member functions*/
	/*Interface*/

	/*Acessors*/
	template<class Ty>
	unsigned Matrix<Ty>::GetHeight() { return _height; }

	template<class Ty>
	unsigned Matrix<Ty>::GetWidth() { return _width; }

	template<class Ty>
	unsigned Matrix<Ty>::GetHeight() const { return _height; }

	template<class Ty>
	unsigned Matrix<Ty>::GetWidth() const { return _width; }

	/*Operators*/

	/*Funcotor*/
	/*Subscript Operators*/

	template<class Ty>
	Ty& Matrix<Ty>::operator() (const size_type i_pos, const size_type j_pos) {
		return _mtx[i_pos][j_pos];
	}

	template<class Ty>
	Ty& Matrix<Ty>::operator() (const size_type i_pos, const size_type j_pos) const {
		return _mtx[i_pos][j_pos];
	}

	/*Addition Operatosr*/
	template<class Ty>
	Matrix<Ty>& Matrix<Ty>::operator+= (const Matrix &rhs__mtx) {
		for (size_type i = 0; i < _height; i++)
			for (size_type j = 0; j < _width; j++)
				this->_mtx[i][j] = this->_mtx[i][j] + rhs__mtx._mtx[i][j];
		return *this;
	}

	template<class Ty>
	Matrix<Ty> Matrix<Ty>::operator+ (const Matrix &rhs__mtx) const {
		return Matrix<Ty>(*this) += rhs__mtx;
	}

	/*Substration Operators*/
	template<class Ty>
	Matrix<Ty>& Matrix<Ty>::operator-= (const Matrix &rhs__mtx) {
		for (size_type i = 0; i < _height; i++)
			for (size_type j = 0; j < _width; j++)
				this->_mtx[i][j] = this->_mtx[i][j] - rhs__mtx._mtx[i][j];
		return *this;
	}

	template<class Ty>
	Matrix<Ty> Matrix<Ty>::operator- (const Matrix &rhs__mtx) const {
		return Matrix<Ty>(*this) -= rhs__mtx;
	}

	/*Multiplication Operators*/
	template<class Ty>
	Matrix<Ty>& Matrix<Ty>::operator*= (const Matrix &rhs_mtx) {
		return *this = *this * rhs_mtx;
	}

	template<class Ty>
	Matrix<Ty> Matrix<Ty>::operator* (const Matrix &rhs_mtx) const {
		Matrix<Ty>::size_type ret_mtx_height = this->GetHeight();
		Matrix<Ty>::size_type ret_mtx_width = rhs_mtx.GetWidth();

		/*The count variable is based on left hand side width*/
		Matrix<Ty>::size_type side_length = this->GetWidth();

		Matrix<Ty> ret_mtx(ret_mtx_height, ret_mtx_width);

		for (Matrix<Ty>::size_type i = 0; i < ret_mtx_height; i++) {
			for (Matrix<Ty>::size_type j = 0; j < ret_mtx_width; j++) {

				Ty sum = Ty();

				for (Matrix<Ty>::size_type count = 0; count < side_length; count++)
					sum += this->_mtx[i][count] * rhs_mtx._mtx[count][j];

				ret_mtx._mtx[i][j] = sum;
			}
		}
		return ret_mtx;
	}
	/*</Member_functions>*/

	/*Non-Member Functions*/

	/*Multiplication by a scalar*/
	template<class Ty>
	Matrix<Ty> operator* (const Ty &scalar, const Matrix<Ty> &mtx) {
		Matrix<Ty> ret_mtx(mtx);

		Matrix<Ty>::size_type height = mtx.GetHeight();
		Matrix<Ty>::size_type width = mtx.GetWidth();

		for (Matrix<Ty>::size_type i = 0; i < height; i++)
			for (Matrix<Ty>::size_type j = 0; j < width; j++)
				ret_mtx(i, j) *= scalar;

		return ret_mtx;
	}

	template<class Ty>
	Matrix<Ty> operator* (const Matrix<Ty> &mtx, const Ty &scalar) {
		return scalar * mtx;
	}

	template<class Ty>
	Matrix<Ty>& operator*= (Matrix<Ty> &mtx, const Ty &scalar) {
		return mtx = mtx * scalar;
	}

	/*Trace*/
	template<class Ty>
	Ty tr(const Matrix<Ty> &mtx) {
		Matrix<Ty>::size_type min_side = mtx.GetHeight();
		Matrix<Ty>::size_type width = mtx.GetWidth();

		if (min_side > width)
			min_side = width;

		Ty sum = 0;
		for (size_type i = 0; i < min_side; i++)
			sum += _mtx[i][i];

		return sum;
	}

	/*Basic line opertions*/
	template<class Ty>
	Matrix<Ty>& swap_lines(Matrix<Ty> &mtx,
		typename Matrix<Ty>::size_type L1,
		typename Matrix<Ty>::size_type L2) {
		Matrix<Ty>::size_type width = mtx.GetWidth();
		for (Matrix<Ty>::size_type i = 0; i < width; i++) {
			Ty tmp = mtx(L1, i);
			mtx(L1, i) = mtx(L2, i);
			mtx(L2, i) = tmp;
		}
		return mtx;
	}

	template<class Ty>
	Matrix<Ty>& swap_columns(Matrix<Ty> &mtx,
		typename Matrix<Ty>::size_type C1,
		typename Matrix<Ty>::size_type C2) {
		Matrix<Ty>::size_type height = mtx.GetHeight();
		for (Matrix<Ty>::size_type i = 0; i < height; i++) {
			Ty tmp = mtx(i, C1);
			mtx(i, C1) = mtx(i, C2);
			mtx(i, C2) = tmp;
		}
		return mtx;
	}

	template<class Ty>
	Matrix<Ty>& scale_a_line(Matrix<Ty> &mtx,
		typename Matrix<Ty>::size_type L1,
		const Ty &coef) {
		Matrix<Ty>::size_type width = mtx.GetWidth();
		for (Matrix<Ty>::size_type i = 0; i < width; i++) {
			mtx[L1][i] *= coef;
		}
		return mtx;
	}

	template<class Ty>
	Matrix<Ty>& add_lines(Matrix<Ty> &mtx,
		typename Matrix<Ty>::size_type L1,
		typename Matrix<Ty>::size_type L2,
		const Ty &coef = 1) {

		Matrix<Ty>::size_type width = mtx.GetWidth();

		for (Matrix<Ty>::size_type i = 0; i < width; i++) {
			mtx(L1, i) += mtx(L2, i)*coef;
		}

		return mtx;
	}

	template<class Ty>
	Matrix<Ty>& substract_lines(Matrix<Ty> &mtx,
		typename Matrix<Ty>::size_type L1,
		typename  Matrix<Ty>::size_type L2,
		const Ty &coef) {

		Matrix<Ty>::size_type width = mtx.GetWidth();

		for (Matrix<Ty>::size_type i = 0; i < width; i++) {
			mtx(L1, i) -= mtx(L2, i)*coef;
		}

		return mtx;
	}
}

#endif

