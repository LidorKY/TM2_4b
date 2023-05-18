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

class OldNinja : public Ninja
{
public:
    OldNinja(string name, Point point);
    ~OldNinja() override;
    OldNinja(const OldNinja &temp);
    OldNinja &operator=(const OldNinja &other);
    OldNinja(OldNinja &&other) noexcept;
    OldNinja &operator=(OldNinja &&other) noexcept;
};