#ifndef POLYDATA_H
#define POLYDATA_H

#include <iostream>
#include <string>
#include <vector>
#include "point.h"
#include "polygon.h"

using namespace std;

class Polydata{
private:
    vector<Point*> point;
    vector<Polygon*> polygon;
public:
    Polydata(const char *arc);
    void print_polygon();
    void print_point();
    void saveToFile(const char* arc);
};

#endif /*POLYDATA_H*/