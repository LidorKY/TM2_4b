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
    this->setHP(0);
    this->setPoint(Point());
    this->setName("");
    this->speed = 0;
}
Ninja::Ninja(Point point1, int hit_points, string name, int speed1) : Character(point1, hit_points, name), speed(speed1)
{
    this->setHP(hit_points);
    this->setPoint(point1);
    this->setName(name);
    this->speed = speed1;
}
// Ninja::~Ninja() {}
// Ninja::Ninja(const Ninja &temp) {}
// Ninja &Ninja::operator=(const Ninja &other) { return *this; }
// Ninja::Ninja(Ninja &&other) noexcept {}
// Ninja &Ninja::operator=(Ninja &&other) noexcept { return *this; }
int Ninja::getSpeed()
{
    return this->speed;
}

void Ninja::setSpeed(int num)
{
    this->speed = num;
}

void Ninja::move(Character *enemy)
{
    if (enemy == nullptr)
    {
        return;
    }
    this->setPoint(this->getLocation().moveTowards(this->getLocation(), enemy->getLocation(), this->getSpeed()));
}
void Ninja::slash(Character *enemy)
{
    if (enemy == nullptr)
    {
        return;
    }
    else if (this == enemy)
    {
        throw runtime_error("");
    }
    else if (enemy->isAlive() == false)
    {
        throw runtime_error("");
    }
    else if (this->isAlive() == false)
    {
        throw runtime_error("");
    }
    else if (this->distance(enemy) < 1.0)
    {
        enemy->hit(this->getHP() - 40);
    }
}
string Ninja::print()
{
    if (this->isAlive() == false)
    {
        return "(" + this->getName() + ")";
    }
    else
    {
        return "N, name: " + this->getName() + ", hp: " + to_string(this->getHP()) + ", location: (" + to_string(this->getLocation().getX()) + "," + to_string(this->getLocation().getY()) + ").";
    }
}