// Deklaracja znajduje się w pliku Point.h
#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point {
public:
    Point();

    Point(double x, double y);

    ~Point();

    void ToString(std::ostream *out) const;
    double Distance(const Point &other) const;

    double GetX() const;
    double GetY() const;

    //...
    void SetX(double x);
    void SetY(double y);

    //opcjonalna definicja pozwalająca na uzyskanie
    //dostępu do prywatnych pól z wewnątrz definicji
    //funkcji zadeklarowanej poniżej
//    friend std::istream& operator>>(std::istream &, Point&);
   // ...

private:
    double x_, y_;
};

//właściwa deklaracja, przeciążająca
//operator >> dla strumienia wejściowego
//i klasy punkt
std::istream& operator>>(std::istream &is, Point& point);
std::ostream& operator<<(std::ostream &is, Point& point);
#endif