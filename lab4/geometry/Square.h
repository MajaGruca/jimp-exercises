//
// Created by ktr on 21.03.2017.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include <Point.h>
namespace geometry{

    class Square {
    public:
        Square();
        Square(Point l_up,Point l_down,Point r_down,Point r_up);
        ~Square();


        bool Check();
        double Circumference();
        double Area();

    private:

        Point l_up_,l_down_,r_up_,r_down_;
    };
}



#endif //JIMP_EXERCISES_SQUARE_H
