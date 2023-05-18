#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <stdio.h>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "string"
using namespace std;

YoungNinja::YoungNinja(string name, Point point) : Ninja(point, 100, name, 14)
{
    this->setHP(100);
    this->setName(name);
    this->setPoint(point);
    this->setSpeed(14);
}
YoungNinja::~YoungNinja() {}
YoungNinja::YoungNinja(const YoungNinja &temp) {}
YoungNinja &YoungNinja::operator=(const YoungNinja &other) { return *this; }
YoungNinja::YoungNinja(YoungNinja &&other) noexcept {}
YoungNinja &YoungNinja::operator=(YoungNinja &&other) noexcept { return *this; }
