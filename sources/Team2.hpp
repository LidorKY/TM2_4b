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
#include "Team.hpp"
using namespace std;
namespace ariel
{
};

class Team2 : public Team
{
public:
    Team2(Character *leader);
    ~Team2() override;
    Team2(const Team2 &temp);
    Team2 &operator=(const Team2 &other);
    Team2(Team2 &&other) noexcept;
    Team2 &operator=(Team2 &&other) noexcept;

    void attack(Team *enemy_team) override;
    void print() override;
};