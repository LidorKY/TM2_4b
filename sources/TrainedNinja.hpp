#pragma once
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

class TrainedNinja : public Ninja
{
public:
    TrainedNinja(string name, Point point);
    ~TrainedNinja();
    TrainedNinja(const TrainedNinja &temp);
    TrainedNinja &operator=(const TrainedNinja &other);
    TrainedNinja(TrainedNinja &&other) noexcept;
    TrainedNinja &operator=(TrainedNinja &&other) noexcept;
};