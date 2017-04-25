//
// Created by ktr on 24.04.2017.
//
#include "iostream"
#include "Punkt3D.h"
int main() {
    Point p2d{1,9};
    Punkt3D p3d{2,5,3}; //najpierw uruchamia konstruktor point2d a potem 3d zeby utworzyc zmienna
    std::cout << "Point2D.distance(Point3D)=" << p2d.Distance(p3d) << std::endl; //liczy dystans 2D (ignoruje 3 wspolrzedna Point3D)
    std::cout << p3d << std::endl; // wypisze pierwsze dwie wspolrzedne
    return 0;
}