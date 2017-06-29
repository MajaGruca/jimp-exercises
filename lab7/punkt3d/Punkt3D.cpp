//
// Created by ktr on 24.04.2017.
//
#include "Punkt3D.h"
#include <iostream>
#include <cmath>

using ::std::pow;
using ::std::sqrt;
using ::std::cout;
using ::std::endl;

Punkt3D::Punkt3D():z_(0) {
    cout << "KONSTRUKTOR BEZPARAMETROWY (PUNKT3D)" << endl;
}

Punkt3D::~Punkt3D() {
    cout << "DESTRUKTOR (PUNKT3D)"<<endl;
}

double Punkt3D::Distance(const Punkt3D &node) const {
    return sqrt(pow(GetX() - node.GetX(), 2) + pow(GetY() - node.GetY(), 2) + pow(GetZ() - node.GetZ(), 2));
}

double Punkt3D::GetZ() const {
    return z_;
}

void Punkt3D::SetZ(double z) {
    z_ = z;
}

Punkt3D::Punkt3D(double x, double y, double z) : Point(x, y) {
    cout << "KONSTRUKTOR PARAMETROWY (PUNKT3D)" << endl;
    z_ = z;
}