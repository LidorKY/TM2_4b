#include <iostream>
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Team.hpp"
#include "SmartTeam.hpp"
#include "vector"
using namespace std;

SmartTeam::SmartTeam(Character *leader) : Team(leader) {}
SmartTeam::~SmartTeam() {}
SmartTeam::SmartTeam(const SmartTeam &temp) {}
SmartTeam &SmartTeam::operator=(const SmartTeam &other) { return *this; }
SmartTeam::SmartTeam(SmartTeam &&other) noexcept {}
SmartTeam &SmartTeam::operator=(SmartTeam &&other) noexcept { return *this; }

void SmartTeam::attack(Team *enemy_team)
{
    Team::attack(enemy_team);
}

void SmartTeam::print()
{
    Team::print();
}