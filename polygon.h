#ifndef POLYDATA_H
#define POLYDATA_H

#include <iostream>
#include <string>
#include <vector>
#include "point.h"

using namespace std;

class Polygon{
private:
    vector<Point*> points;
public:
    Polygon(const char *arc);
    void print();
    void saveToFile(const char* arc);
};

#endif /*POLYDATA_H*/