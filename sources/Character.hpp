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
private:
    Point location;
    int hit_points;
    string name;
    bool assigned_to_a_team;

public:
    Character();
    Character(Point point1, int hit_points, string name);
    virtual ~Character();
    Character(const Character &temp);
    Character &operator=(const Character &other);
    Character(Character &&other) noexcept;
    Character &operator=(Character &&other) noexcept;

    int getHP();
    string getName();
    Point getLocation();
    bool getAssigned();
    void setAssigned(bool state);
    void setPoint(Point point1);
    void setHP(int hit_points1);
    void setName(string name1);

    bool isAlive();
    double distance(Character *other);
    void hit(int num);
    virtual string print();
};