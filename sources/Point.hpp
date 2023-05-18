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
private:
    double axis_X;
    double axis_Y;

public:
    Point();
    Point(double num_x, double num_y);

    double getX();
    double getY();
    void setX(double num);
    void setY(double num);

    double distance(Point point1);
    void print(Point point1);
    static Point moveTowards(Point sorce_point, Point destination_point, double distance);
};
