//
// Created by ktr on 21.03.2017.
//

#include <cmath>
#include <iostream>
#include "Point.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using ::std::cout;
using ::std::istream;
using ::std::ws;

Point::Point():x_(0),y_(0) {
    cout << "KONSTRUKTOR BEZPARAMETROWY (POINT)" << endl;
}

Point::Point(double x, double y) {
    cout << "KONSTRUKTOR PARAMETROWY (POINT)" << endl;
    x_ = x;
    y_ = y;
}

Point::~Point() {
    cout << "DESTUKTOR (POINT)";
    cout << endl;
}

double Point::Distance(const Point &other) const {
    return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2));
}

void Point::ToString(ostream *out) const {
    (*out) << "(" << GetX() << ";" << GetY() << ")";
}

double Point::GetX() const {
    return x_;
}

double Point::GetY() const {
    return y_;
}

void Point::SetX(double x) {
    x_ = x;
}

void Point::SetY(double y) {
    y_ = y;

}

void CheckNextChar(char c, istream* is) {
    int next_char = is->peek();
    if (next_char != c) {
        throw std::runtime_error("invalid character");
    }
    is->ignore();
}

void IgnoreWhitespace(istream* is) {
    (*is) >> ws;
}

double ReadNumber(istream* is) {
    double d;
    (*is) >> d;
    return d;
}

istream& operator>>(istream & input, Point& p){
    CheckNextChar('(', &input);
    p.SetX(ReadNumber(&input));
    CheckNextChar(',', &input);
    IgnoreWhitespace(&input);
    p.SetY(ReadNumber(&input));
    CheckNextChar(')', &input);
    return input;      // Umożliwia cin >> a >> b >> c;
}

ostream& operator<<(ostream & output,Point& p){
    output<<"("<<p.GetX()<<","<<p.GetY()<<")";

    return output;
}