#ifndef POINTS_H
#define POINTS_H

#include <iostream>
#include <string>
#include <vector>

class Point{
public:
    double x,y,z;
    Point(double x, double y, double z);
    Point(const char* str);
    void print_point();
};

#endif /*POINTS_H*/