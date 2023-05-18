#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <stdio.h>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "string"
using namespace std;

OldNinja::OldNinja(string name, Point point) : Ninja(point, 150, name, 8)
{
    this->setHP(150);
    this->setName(name);
    this->setPoint(point);
    this->setSpeed(8);
}
OldNinja::~OldNinja() {}
OldNinja::OldNinja(const OldNinja &temp) {}
OldNinja &OldNinja::operator=(const OldNinja &other) { return *this; }
OldNinja::OldNinja(OldNinja &&other) noexcept {}
OldNinja &OldNinja::operator=(OldNinja &&other) noexcept { return *this; }
