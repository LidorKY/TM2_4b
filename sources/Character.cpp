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
Character::Character(Point point1, int hit_points1, string name1) : location(point1), hit_points(hit_points1), name(name1), assigned_to_a_team(false)
{
    this->location = point1;
    this->hit_points = hit_points1;
    this->name = name1;
    this->assigned_to_a_team = false;
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

int Character::getHP()
{
    return this->hit_points;
}

string Character::getName()
{
    return this->name;
}

Point Character::getLocation()
{
    return this->location;
}

bool Character::getAssigned()
{
    return this->assigned_to_a_team;
}

void Character::setAssigned(bool state)
{
    this->assigned_to_a_team = state;
}

void Character::setPoint(Point point1)
{
    this->location = point1;
}

void Character::setHP(int hit_points1)
{
    this->hit_points = hit_points1;
}

void Character::setName(string name1)
{
    this->name = name1;
}

bool Character::isAlive()
{
    if (this->getHP() > 0)
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
    this->setHP(this->getHP() - num);
}

string Character::print()
{
    return "";
}