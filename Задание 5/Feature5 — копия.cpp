##pragma once
#include "Exception.h"
using namespace std;

struct Angles
{
	double a;
	double b;
};

class Triangle
{
private:
	unsigned int _A;
	unsigned int _B;
public:

	Triangle(unsigned int A, unsigned int B)
	{

	}

	~Triangle() = default;

	Angles Calc(unsigned int A, unsigned int B) {
		Angles ang;
		ang.a = A / sqrt(pow(A, 2) + pow(B, 2));
		ang.b = B / sqrt(pow(A, 2) + pow(B, 2));
		return ang;
	}

	Angles ConversionNoEx() {
		return Calc(_A, _B);
	}
	Angles ConversionThrow() throw() {
		return Calc(_A, _B);
	}

	Angles ConversionSpecification() /* throw(invalid_argument())*/
	{
		if (!(_A > 0 && _B > 0))
			throw invalid_argument("Отрицательный аргумент");
		return Calc(_A, _B);
	}

	Angles ConversionEmptyClass() /*throw(ExeptionEmpty)*/
	{
		if (!(_A > 0 && _B > 0))
			throw ExeptionEmpty();
		return Calc(_A, _B);
	}

	Angles ConversionMyException() /*throw(MyException)*/
	{
		if (!(_A > 0 && _B > 0))
			throw MyException("Отрицательное время");
		return Calc(_A, _B);
	}

	Angles ConversionMyExceptionHier() /*throw(MyExceptionHier)*/
	{
		if (!(_A > 0 && _B > 0))
			throw MyExceptionHier("Отрицательный аргумент", 0);
		return Calc(_A, _B);
	}
};