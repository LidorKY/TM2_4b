#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <stdio.h>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "string"
using namespace std;

Ninja::Ninja()
{
    this->hit_points = 0;
    this->location = Point();
    this->name = "";
    this->speed = 0;
}
Ninja::Ninja(Point point1, int hit_points, string name, int speed1) : Character(point1, hit_points, name), speed(speed1)
{
    this->hit_points = hit_points;
    this->location = point1;
    this->name = name;
    this->speed = speed1;
}
// Ninja::~Ninja() {}
// Ninja::Ninja(const Ninja &temp) {}
// Ninja &Ninja::operator=(const Ninja &other) { return *this; }
// Ninja::Ninja(Ninja &&other) noexcept {}
// Ninja &Ninja::operator=(Ninja &&other) noexcept { return *this; }
void Ninja::move(Character *enemy)
{
    this->location.moveTowards(this->location, enemy->location, this->speed);
}
void Ninja::slash(Character *enemy)
{
    if (this->isAlive() == true && enemy->isAlive() == true && this->distance(enemy) <= 1.0)
    {
        enemy->hit(40);
    }
}
string Ninja::print()
{
    if (this->isAlive() == false)
    {
        return "(" + this->name + ")";
    }
    else
    {
        return "N, name: " + this->name + ", hp: " + to_string(this->hit_points) + ", location: (" + to_string(this->location.axis_X) + "," + to_string(this->location.axis_Y) + ").";
    }
}