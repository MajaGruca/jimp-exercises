//
// Created by ktr on 21.03.2017.
//

#include <iostream>
#include <Point.h>
#include "Square.h"

using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using ::std::cout;
namespace geometry
{
    Square::Square():l_up_(0,0),l_down_(0,0),r_down_(0,0),r_up_(0,0){
    }

    Square::Square(Point l_up,Point l_down,Point r_up,Point r_down){
        l_up_ = l_up;
        l_down_ = l_down;
        r_up_ = r_up;
        r_down_ = r_down;
    }

    Square::~Square(){
    }

    bool Square::Check() {

        if (r_down_.Distance(r_up_) == r_up_.Distance(l_up_)) {
            if (r_down_.Distance(l_up_) == l_down_.Distance(r_up_))
                return true;
        }
        return false;

    }

    double Square::Circumference() {

        if(Check())
        {
            return this->r_down_.Distance(r_up_)*4;

        } else
            return 0;
    }

    double Square::Area(){

        if(Check())
        {
            return pow(this->r_down_.Distance(r_up_),2);
        } else
            return 0;
    }


}