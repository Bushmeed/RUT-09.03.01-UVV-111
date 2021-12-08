#pragma once
#include "Pair.h"
class Complex : public Pair {
private:

	double _real;

	double _imaginary;

public:

	Complex(const double real = 0, const double imaginary = 0)
		: _real(real)
		, _imaginary(imaginary)
	{}

	void operator* (Complex& arg)
	{
		_real = _real * arg._real -_imaginary * arg._imaginary;
		_imaginary = _real * arg._imaginary + _imaginary * arg._real;
	}

	void operator- (Complex& arg)
	{
		_real = _real - _imaginary;
		_imaginary = arg._real - arg._imaginary;
	}
};