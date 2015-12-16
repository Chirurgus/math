#ifndef GUARD_MATRIX_POINTERS_H
#define GUARD_MATRIX_POINTERS_H

template<class Ty>class Matrix {

public:
	typedef unsigned int size_type;

	/*Matrix Default Constructor*/
	Matrix<Ty>() : Matrix<Ty>(1,1) { }

	/*Matrix Constructor, taking _height(ht) and _width(wd) as arguments*/
	Matrix<Ty> (size_type ht, size_type wd, const Ty &inital_value = Ty()) {
		arrayAllocator(ht, wd);
		for (size_type i = 0; i < _height; i++)
			for (size_type j = 0; j < _width; j++)
				_mtx[i][j] = inital_value;
	}

	/*Matrix Copy Constructor*/
	Matrix<Ty>(const Matrix &old_mtx) {
		arrayAllocator(old_mtx._height, old_mtx._width);
		for (size_type i = 0; i < _height; i++)
			for (size_type j = 0; j < _width; j++)
				_mtx[i][j] = old_mtx[i][j];
	}

	/*Copy Assignment Cperator*/
	Matrix &operator= (const Matrix &old_mtx) {
		if (this != &old_mtx) {
			arrayDelocator(_height);
			arrayAllocator(old_mtx._height, old_mtx._width);
			for (size_type i = 0; i < _height; i++)
				for (size_type j = 0; j < _width; j++)
					_mtx[i][j] = old_mtx[i][j];
		}
		return *this;//This is supposed to return a reference to this object, not an instance of the object, but it seems that C++ should add & implicity
	}

	/*Destructor*/
	~Matrix<Ty>() {
		arrayDelocator(_height);
	}


	/*Interface*/

	/*Trace*/
	Ty tr();

	/*Discriminant */
	Ty det();

	/*Inversion*/
	bool isInversible() {
		return det() != 0;
	}

	/*Getters*/
	unsigned GetHeight();
	unsigned GetWidth();


	/*Operators*/

	/*Subscript Operators*/
	Ty* operator[] (const size_type pos) {
		if (pos < _height)
			return _mtx[pos];
		else
			;//TODO what to do if <code>pos</code> is out of range
	}
	Ty* operator[] (const size_type pos) const {
		if (pos < _height)
			return _mtx[pos];
		else
			;//TODO what to do if <code>pos</code> is out of range
	}

	Ty operator() (const size_type i_pos, const size_type j_pos);
	Ty operator() (const size_type i_pos, const size_type j_pos) const;

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

#include "matrix.cpp"

#endif
