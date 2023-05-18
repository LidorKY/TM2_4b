#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <stdio.h>
#include "Point.hpp"
#include "Character.hpp"
#include "string"
using namespace std;

class Cowboy : public Character
{
private:
    int num_of_bullets;

public:
    Cowboy(string name, Point point);
    // ~Cowboy();
    // Cowboy(const Cowboy &temp);
    // Cowboy &operator=(const Cowboy &other);
    // Cowboy(Cowboy &&other) noexcept;
    // Cowboy &operator=(Cowboy &&other) noexcept;
    int getNumOfBullets();
    void setNumOfBullets(int num);

    void shoot(Character *enemy);
    bool hasboolets();
    void reload();
    string print() override;
};