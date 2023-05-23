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
    /*constructors*/
    Character();
    Character(Point point1, int hit_points, string name);

    /*destructor + copy_ctr + operator=*/
    virtual ~Character();
    Character(const Character &temp);
    Character &operator=(const Character &other);
    Character(Character &&other) noexcept;
    Character &operator=(Character &&other) noexcept;

    /*getteres and setteres.*/
    int getHP();
    string getName();
    Point getLocation();
    bool getAssigned();
    void setAssigned(bool state);
    void setPoint(Point point1);
    void setHP(int hit_points1);
    void setName(string name1);

    /*functions*/
    bool isAlive();
    double distance(Character *other);
    void hit(int num);
    virtual string print();
};