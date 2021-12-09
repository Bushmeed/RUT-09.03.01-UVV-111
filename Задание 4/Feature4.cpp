#pragma once
#include <math.h>

class Function {
public:
    virtual double Value() = 0;
    virtual ~Function() = 0;
    virtual double Derivative() = 0;
};

class Constant : public Function {
private:
    double _c;
public:
    Constant(double c) : _c(c) {}
    Constant(const Constant& c) = default;
    ~Constant() = 0;
    double Value() override {
        return _c;
    }

    double Derivative() override {
        return 0;
    };

};

class LinearDependence : public Function {
private:
    double _a;
    double _x;
    double _c;
public:
    LinearDependence(double a, double x, double c) :_a(a), _x(x), _c(c) {}
    LinearDependence(const LinearDependence& ld) = default;
    ~LinearDependence() = default;

    double Value() override {
        return _a * _x + _c;
    };

    double Derivative() override {
        return _a;
    };

};

class Parabola : public Function {
private:

    double _a;
    double _b;
    double _x;
    double _c;

public:

    Parabola(double a, double b, double x, double c) : _a(a), _b(b), _x(x), _c(c) {}
    Parabola(const Parabola& parabola) = default;
    ~Parabola() = 0;

    double Value() override {
        return _a * pow(_x, 2) + _b * _x + _c;
    };

    double Derivative() override {
        return 2 * _a * _x + _b;
    };

};