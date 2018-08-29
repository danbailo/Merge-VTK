#ifndef POINTS_H
#define POINTS_H

#include <iostream>
#include <string>
#include <vector>

/** Declaração da classe Point, onde esta
  * contém os elementos x, y e z referentes ao espaço tridimensional;
  */
class Point{
public:
    double x,y,z;
    Point(double x, double y, double z);
    Point(const char* str);
    void print();
};

#endif /*POINTS_H*/