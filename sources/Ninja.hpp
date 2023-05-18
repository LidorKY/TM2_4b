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
    Ninja();
    Ninja(Point point1, int hit_points, string name, int speed);
    // ~Ninja();
    // Ninja(const Ninja &temp);
    // Ninja &operator=(const Ninja &other);
    // Ninja(Ninja &&other) noexcept;
    // Ninja &operator=(Ninja &&other) noexcept;
    int getSpeed();
    void setSpeed(int num);

    void move(Character *enemy);
    void slash(Character *enemy);
    string print() override;
};