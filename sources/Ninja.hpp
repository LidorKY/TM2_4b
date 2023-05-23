#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <stdio.h>
#include "Point.hpp"
#include "Character.hpp"
#include "string"
using namespace std;

class Ninja : public Character
{
private:
    int speed;

public:
    /*constructors*/
    Ninja();
    Ninja(Point point1, int hit_points, string name, int speed);
    ~Ninja() override;
    Ninja(const Ninja &temp);
    Ninja &operator=(const Ninja &other);
    Ninja(Ninja &&other) noexcept;
    Ninja &operator=(Ninja &&other) noexcept;

    /*getteres and setteres*/
    int getSpeed();
    void setSpeed(int num);

    /*functions*/
    void move(Character *enemy);
    void slash(Character *enemy);
    string print() override;
};