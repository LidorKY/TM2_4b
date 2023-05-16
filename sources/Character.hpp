#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <stdio.h>
#include "Point.hpp"
#include "string"
using namespace std;

class Character
{
public:
    Point location;
    int hit_points;
    string name;

    Character();
    Character(Point point1, int hit_points, string name);
    virtual ~Character();
    Character(const Character &temp);
    Character &operator=(const Character &other);
    Character(Character &&other) noexcept;
    Character &operator=(Character &&other) noexcept;
    bool isAlive();
    double distance(Character *other);
    void hit(int num);
    string getName();
    Point getLocation();
    virtual string print();
};