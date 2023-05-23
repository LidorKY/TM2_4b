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
    /*constructor*/
    Cowboy(string name, Point point);
    ~Cowboy() override;
    Cowboy(const Cowboy &temp);
    Cowboy &operator=(const Cowboy &other);
    Cowboy(Cowboy &&other) noexcept;
    Cowboy &operator=(Cowboy &&other) noexcept;

    /*getteres and setteres*/
    int getNumOfBullets();
    void setNumOfBullets(int num);

    /*functions*/
    void shoot(Character *enemy);
    bool hasboolets();
    void reload();
    string print() override;
};