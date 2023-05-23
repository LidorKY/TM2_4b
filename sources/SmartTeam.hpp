#pragma once
#include <iostream>
#include "Team.hpp"
using namespace std;
namespace ariel
{
};

/*
sorry in advance :(
i dont have enough time to think about an algorithm and implement it (since i have to submit OS and other cyber courses)
so i just call to the functions attack() and print() from the team class.
*/

class SmartTeam : public Team
{
public:
    SmartTeam(Character *leader);
    ~SmartTeam() override;
    SmartTeam(const SmartTeam &temp);
    SmartTeam &operator=(const SmartTeam &other);
    SmartTeam(SmartTeam &&other) noexcept;
    SmartTeam &operator=(SmartTeam &&other) noexcept;

    void attack(Team *enemy_team) override;
    void print() override;
};