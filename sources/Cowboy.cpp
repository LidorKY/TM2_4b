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
    this->hit_points = 110;
    this->location = point;
    this->name = name;
    this->num_of_bullets = 6;
}
// Cowboy::~Cowboy() {}
// Cowboy::Cowboy(const Cowboy &temp) {}
// Cowboy &Cowboy::operator=(const Cowboy &other) { return *this; }
// Cowboy::Cowboy(Cowboy &&other) noexcept {}
// Cowboy &Cowboy::operator=(Cowboy &&other) noexcept { return *this; }
void Cowboy::shoot(Character *enemy)
{
    if (this->isAlive() == true && enemy->isAlive() == true && this->num_of_bullets > 0)
    {
        enemy->hit_points = enemy->hit_points - 10;
        this->num_of_bullets = this->num_of_bullets - 1;
    }
}
bool Cowboy::hasboolets()
{
    if (this->num_of_bullets > 0)
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
    this->num_of_bullets = 6;
}
string Cowboy::print()
{
    if (this->isAlive() == false)
    {
        return "(" + this->name + ")";
    }
    else
    {
        return "C, name: " + this->name + ", hp: " + to_string(this->hit_points) + ", location: (" + to_string(this->location.axis_X) + "," + to_string(this->location.axis_Y) + ").";
    }
}
