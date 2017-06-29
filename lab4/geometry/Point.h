//
// Created by ktr on 21.03.2017.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H
#include <cmath>
#include <ostream>
#include "Point.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
namespace geometry{

    class Point {
    public:

        Point();

        Point(double x, double y);

        ~Point();

        void ToString(std::ostream *out) const;
        double Distance(const Point &other) const;

        double GetX() const;
        double GetY() const;

        void SetX(double x);
        void SetY(double y);
    private:
        double x_, y_;
    };
}



#endif //JIMP_EXERCISES_POINT_H
