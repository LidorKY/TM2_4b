#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <stdio.h>
using namespace std;

class Point
{
public:
    double axis_X;
    double axis_Y;
    Point();
    Point(double num_x, double num_y);

    double distance(Point point1);
    void print(Point point1);
    static Point moveTowards(Point sorce_point, Point destination_point, double distance);
};
