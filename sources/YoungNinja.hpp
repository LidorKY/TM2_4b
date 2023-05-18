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

class YoungNinja : public Ninja
{
public:
    YoungNinja(string name, Point point);
    // ~YoungNinja();
    // YoungNinja(const YoungNinja &temp);
    // YoungNinja &operator=(const YoungNinja &other);
    // YoungNinja(YoungNinja &&other) noexcept;
    // YoungNinja &operator=(YoungNinja &&other) noexcept;
};