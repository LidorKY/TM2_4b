#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <cmath>
#include "Point.hpp"
using namespace std;

Point::Point()
{
    Point(0.0, 0.0);
}

Point::Point(double x, double y) : axis_X(x), axis_Y(y)
{
    this->axis_X = x;
    this->axis_Y = y;
}

double Point::distance(Point point1)
{
    double distance = sqrt(pow(this->axis_X - point1.axis_X, 2) + pow(this->axis_Y - point1.axis_Y, 2));
    return distance;
}

void Point::print(Point point1)
{
    cout << "(" << this->axis_X << "," << this->axis_Y << ")";
}

Point Point::moveTowards(Point sorce_point, Point destination_point, double distance)
{
    if (sorce_point.distance(destination_point) <= distance)
    {
        return destination_point;
    }
    else
    {
        // Calculate the unit vector from source to destination
        double unitVectorX = (destination_point.axis_X - sorce_point.axis_X) / sorce_point.distance(destination_point);
        double unitVectorY = (destination_point.axis_Y - sorce_point.axis_Y) / sorce_point.distance(destination_point);

        // Calculate the coordinates of the nearest point within maxDistance from source
        double nearestX = sorce_point.axis_X + unitVectorX * sorce_point.distance(destination_point);
        double nearestY = sorce_point.axis_Y + unitVectorY * sorce_point.distance(destination_point);

        Point nearestPoint{nearestX, nearestY};
        return nearestPoint;
    }
}
