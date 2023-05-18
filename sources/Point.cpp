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

double Point::getX()
{
    return this->axis_X;
}
double Point::getY()
{
    return this->axis_Y;
}
void Point::setX(double num)
{
    this->axis_X = num;
}
void Point::setY(double num)
{
    this->axis_Y = num;
}

double Point::distance(Point point1)
{
    double distance = sqrt(pow(this->getX() - point1.getX(), 2) + pow(this->getY() - point1.getY(), 2));
    return distance;
}

void Point::print(Point point1)
{
    cout << "(" << this->getX() << "," << this->getY() << ")";
}

Point Point::moveTowards(Point sorce_point, Point destination_point, double distance)
{
    if (distance < 0)
    {
        throw invalid_argument("error");
    }
    if (sorce_point.distance(destination_point) <= distance)
    {
        return destination_point;
    }
    else
    {
        // Calculate the unit vector from source to destination
        double unitVectorX = (destination_point.getX() - sorce_point.getX()) / sorce_point.distance(destination_point);
        double unitVectorY = (destination_point.getY() - sorce_point.getY()) / sorce_point.distance(destination_point);

        // Calculate the coordinates of the nearest point within maxDistance from source
        double nearestX = sorce_point.getX() + unitVectorX * distance;
        double nearestY = sorce_point.getY() + unitVectorY * distance;

        Point nearestPoint{nearestX, nearestY};
        return nearestPoint;
    }
}
