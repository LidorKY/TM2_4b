#pragma once
#include <iostream>
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "vector"
using namespace std;
namespace ariel
{
};

class Team
{
public:
    vector<Character *> team;
    Character *_leader;
    Team();
    Team(Character *leader);
    ~Team();
    Team(const Team &temp);
    Team &operator=(const Team &other);
    Team(Team &&other) noexcept;
    Team &operator=(Team &&other) noexcept;
    void add(Character *member);
    void attack(Team *enemy_team);
    int stillAlive();
    void print();
};