#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
using namespace std;

Cowboy::Cowboy(string name, Point point) : num_of_bullets(6), Character(point, 110, name)
{
    // this->setHP(110);
    // this->setPoint(point);
    // this->setName(name);
    this->num_of_bullets = 6;
}
Cowboy::~Cowboy() {}
Cowboy::Cowboy(const Cowboy &temp) {}
Cowboy &Cowboy::operator=(const Cowboy &other) { return *this; }
Cowboy::Cowboy(Cowboy &&other) noexcept {}
Cowboy &Cowboy::operator=(Cowboy &&other) noexcept { return *this; }

int Cowboy::getNumOfBullets()
{
    return this->num_of_bullets;
}

void Cowboy::setNumOfBullets(int num)
{
    this->num_of_bullets = num;
}

void Cowboy::shoot(Character *enemy)
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
    else if (this->num_of_bullets > 0)
    {
        enemy->hit(10);
        this->setNumOfBullets(this->getNumOfBullets() - 1);
    }
    else
    {
        return;
    }
}
bool Cowboy::hasboolets()
{
    if (this->getNumOfBullets() > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Cowboy::reload()
{
    if (this->isAlive() == false)
    {
        throw runtime_error("");
    }
    this->setNumOfBullets(6);
}
string Cowboy::print()
{
    if (this->isAlive() == false)
    {
        return "(" + this->getName() + ")";
    }
    else
    {
        return "C, name: " + this->getName() + ", hp: " + to_string(this->getHP()) + ", location: (" + to_string(this->getLocation().getX()) + "," + to_string(this->getLocation().getY()) + ").";
    }
}
