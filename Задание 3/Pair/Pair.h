#pragma once

class Pair {
private:
	/*
	* \brief x
	*/
	double _x;
	/*
	* \brief y
	*/
	double _y;

public:
	/*
	* \brief Конструктор по умолчанию
	* \param x
	* \param y
	*/
	Pair(const double x = 0, const double y = 0)
		: _x(x)
		, _y(y)
	{}
	/*
	* \brief Конструктор копирования по умолчанию
	*/
	Pair(const Pair& other) = default;
	/*
	* \brief Деструктор
	*/
	~Pair() = default;

	/*
	* \brief Setter x
	*/
	void SetX(const double x) { _x = x; }
	/*
	* \brief Setter y
	*/
	void SetY(const double y) { _y = y; }
	/*
	* \brief Getter x
	*/
	double GetX() { return _x; }
	/*
	* \brief Getter y
	*/
	double GetY() { return _y; }

	double Mul() const;
	double Add(const Pair& other);
};
