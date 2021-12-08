#include <iostream>
#include "Pair.h"
using namespace std;

double Pair::Mul() const
{
	return _x * _y;
}

double Pair::Add(const Pair& other)
{
	_x = _x + other._x - (_x + _y);
	_y = _x + other._y - (other._x + other._y);
}
