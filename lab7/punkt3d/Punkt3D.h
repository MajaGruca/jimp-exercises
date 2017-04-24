//
// Created by ktr on 24.04.2017.
//

#ifndef JIMP_EXERCISES_PUNKT3D_H
#define JIMP_EXERCISES_PUNKT3D_H


#include "Point.h"

class Punkt3D : public Point {
protected:
    double z_;

public:
    Punkt3D();
    Punkt3D(double x, double y, double z);
    ~Punkt3D();
    double Distance(const Punkt3D &node) const;
    double GetZ() const;
    void SetZ(double z);
};




#endif //JIMP_EXERCISES_PUNKT3D_H
