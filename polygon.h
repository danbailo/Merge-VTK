#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
#include <string>
#include <vector>

class Polygon{
public:
    int three,p1,p2,p3;
    Polygon(int p1, int p2, int p3);
    Polygon(const char* str);
    void print_polygon();
};

#endif /*POLYGON_H*/