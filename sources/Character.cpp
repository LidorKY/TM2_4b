#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "Point.hpp"
#include "Character.hpp"
using namespace std;

Character::Character()
{
    this->location = Point(0.0, 0.0);
    this->hit_points = 0;
    this->name = "";
}
Character::Character(Point point1, int hit_points1, string name1) : location(point1), hit_points(hit_points1), name(name1)
{
    this->location = point1;
    this->hit_points = hit_points1;
    this->name = name1;
}
Character::~Character() {}
Character::Character(const Character &temp)
{
    this->location = temp.location;
    this->hit_points = temp.hit_points;
    this->name = temp.name;
}
Character &Character::operator=(const Character &other)
{
    this->location = other.location;
    this->hit_points = other.hit_points;
    this->name = other.name;
    return *this;
}
Character::Character(Character &&other) noexcept {}
Character &Character::operator=(Character &&other) noexcept { return *this; }

bool Character::isAlive()
{
    if (this->hit_points > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double Character::distance(Character *other)
{
    return this->location.distance(other->location);
}
void Character::hit(int num)
{
    this->hit_points = this->hit_points - num;
}
string Character::getName()
{
    return this->name;
}
Point Character::getLocation()
{
    return this->location;
}
string Character::print()
{
    return "";
}