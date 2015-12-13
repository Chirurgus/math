#ifndef MATRIX_POINTERS_CPP
#define MATRIX_POINTERS_CPP

#include "matrix_pointers.h"

/*Member functions*/
/*Interface*/

/*Acessors*/
template<class Ty>
unsigned Matrix<Ty>::GetHeight() { return _height; }

template<class Ty>
unsigned Matrix<Ty>::GetWidth() { return _width; }

/*Trace*/
template<class Ty>
Ty Matrix<Ty>::tr() {
	if (_height == _width) {
		Ty sum = 0;
		for (size_type i = 0; i < _height; i++)
			sum += _mtx[i][i];
		return sum;
	}
	else {
		;//TODO: waht to do if the matrix is not squre
	}
}

/*Discriminant */
template<class Ty>
Ty Matrix<Ty>::det() {
	if (_width == _height) {

		/*initilizing this to 1 might actualy suppose
		something about the end value, one case I
		can see right now if the Matrix is emty
		UPDATE: actualy i see a BIG fucking problem,
		whatever the template type might be, it might not
		accept 1 as a value
		But a one will have to do for now*/

		if (_width == 1)
			return _mtx[0][0];

		if (_width == 2)
			return _mtx[0][0] * _mtx[1][1] - _mtx[0][1] * _mtx[1][0];

		Ty positive_diagonals = 0;
		Ty negative_diagonals = 0;

		for (size_type mtplx_index = 0; mtplx_index < _width; mtplx_index++) {

			Ty a_positive_diagonal = 1;
			Ty a_negative_diagonal = 1;

			for (size_type i = mtplx_index, j = 0; j < _width; j++, i++) {
				size_type hos_pos = i%_width;

				a_positive_diagonal *= _mtx[j][hos_pos];
				a_negative_diagonal *= _mtx[j][(_width - 1) - hos_pos];

			}
			positive_diagonals += a_positive_diagonal;
			negative_diagonals += a_negative_diagonal;
		}
		return positive_diagonals - negative_diagonals;
	}
	else {
		//TODO: implement what to do if Matrix is not squraed
	}
}


/*Operators*/

/*Funcotor*/
template<class Ty>
Ty Matrix<Ty>::operator() (const size_type i_pos, const size_type j_pos) {
	return _mtx[i_pos][j_pos];
}

template<class Ty>
Ty Matrix<Ty>::operator() (const size_type i_pos, const size_type j_pos) const{
	return _mtx[i_pos][j_pos];
}

/*Addition Operatosr*/
template<class Ty>
Matrix<Ty>& Matrix<Ty>::operator+= (const Matrix &rhs__mtx) {
	if (_height == rhs__mtx._height && _width == rhs__mtx._width) {
		for (size_type i = 0; i < _height; i++)
			for (size_type j = 0; j < _width; j++)
				_mtx[i][j] = _mtx[i][j] + rhs__mtx[i][j];
		return *this;
	}
	else {
		;//TODO: add what to do if matrxies are not same size
	}
}

template<class Ty>
Matrix<Ty> Matrix<Ty>::operator+ (const Matrix &rhs__mtx) const {
	if (_height == rhs__mtx._height && _width == rhs__mtx._width) {
		return Matrix<Ty>(*this) += rhs__mtx;
	}
	else {
		;	//TODO:add what to do if the size is not the same.
	}
}

/*Substration Operators*/
template<class Ty>
Matrix<Ty>& Matrix<Ty>::operator-= (const Matrix &rhs__mtx) {
	if (_height == rhs__mtx._height && _width == rhs__mtx._width) {
		for (size_type i = 0; i < _height; i++)
			for (size_type j = 0; j < _width; j++)
				_mtx[i][j] = _mtx[i][j] - rhs__mtx[i][j];
		return *this;
	}
	else {
		;//TODO: add what to do if matrxies are not same size
	}
}

template<class Ty>
Matrix<Ty> Matrix<Ty>::operator- (const Matrix &rhs__mtx) const {
	if (_height == rhs__mtx._height && _width == rhs__mtx._width) {
		return Matrix<Ty>(*this) -= rhs__mtx;
	}
	else {
		;	//TODO:add what to do if the size is not the same.
	}
}

/*Multiplication Operators*/
template<class Ty>
Matrix<Ty>& Matrix<Ty>::operator*= (const Matrix &rhs__mtx) {
	if (_width == rhs__mtx._height) {
		Matrix<Ty> ret__mtx(_height, rhs__mtx._height);
		for (size_type i = 0; i < _height; i++)
			for (size_type j = 0; j < _width; j++) {
				Ty sum = 0;
				for (size_type add_index = 0; add_index < _width; add_index++)
					sum += ret__mtx[i][add_index] * rhs__mtx[add_index][j];
				ret__mtx[i][j] = sum;
			}
		*this = ret__mtx;
		return *this;
	}
	else {
		;//TODO:add waht to do if sizes are not equal
	}
}

template<class Ty>
Matrix<Ty> Matrix<Ty>::operator* (const Matrix &rhs__mtx) const {
	if (_width == rhs__mtx._height) {
		return Matrix<Ty>(*this) *= rhs__mtx;
	}
}
/*</Member_functions>*/

#endif
