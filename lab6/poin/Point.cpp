//Definicja w Point.cpp
#include "Point.h"
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>



using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using ::std::cout;

using ::std::istream;
using ::std::ws;

//Helper functions:
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


// Właściwa definicja, obydwa argumenty funkcji nie
//są zadeklarowane jako const, bo obydwa są modyfikowane
//wewnątrz funkcji (STL nie używa naszej konwencji z przekazywaniem
//przez wskaźnik)
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






Point::Point():x_(0),y_(0){
}

Point::Point(double x, double y){
    x_ = x;
    y_ = y;
}

Point::~Point(){
}

double Point::Distance(const Point &other) const{
    return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
}

void Point::ToString(ostream *out) const{
    (*out) << "(" << GetX() << ";" << GetY() << ")";
}

double Point::GetX() const
{
    return x_;
}
double Point::GetY() const{
    return y_;
}


void Point::SetX(double x)
{
    x_=x;
}
void Point::SetY(double y)
{
    y_=y;
}