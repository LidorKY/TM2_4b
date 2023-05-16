#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <stdio.h>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "TrainedNinja.hpp"
#include "string"
using namespace std;

TrainedNinja::TrainedNinja(string name, Point point) : Ninja(point, 120, name, 12)
{
    this->hit_points = 120;
    this->name = name;
    this->location = point;
    this->speed = 12;
}
// TrainedNinja::~TrainedNinja() {}
// TrainedNinja::TrainedNinja(const TrainedNinja &temp) {}
// TrainedNinja &TrainedNinja::operator=(const TrainedNinja &other) { return *this; }
// TrainedNinja::TrainedNinja(TrainedNinja &&other) noexcept {}
// TrainedNinja &TrainedNinja::operator=(TrainedNinja &&other) noexcept { return *this; }
