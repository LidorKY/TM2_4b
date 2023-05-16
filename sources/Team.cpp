#include <iostream>
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Team.hpp"
#include "vector"
using namespace std;

Team::Team(Character *leader) : _leader(leader)
{
    this->team.push_back(leader);
    this->_leader = leader;
}
Team::~Team()
{
    for (unsigned long i = 0; i < this->team.size(); i++)
    {
        if (this->team.at(i) != nullptr)
        {
            delete this->team.at(i);
        }
    }
}
Team::Team(const Team &temp)
{
    for (unsigned long i = 0; i < temp.team.size(); i++)
    {
        if (temp.team.at(i) != nullptr)
        {
            this->team.at(i) = temp.team.at(i);
        }
    }
    if (temp._leader != nullptr)
    {
        this->_leader = temp._leader;
    }
}
Team &Team::operator=(const Team &other)
{
    for (unsigned long i = 0; i < other.team.size(); i++)
    {
        if (other.team.at(i) != nullptr)
        {
            this->team.at(i) = other.team.at(i);
        }
    }
    if (other._leader != nullptr)
    {
        this->_leader = other._leader;
    }
    return *this;
}
Team::Team(Team &&other) noexcept {}
Team &Team::operator=(Team &&other) noexcept { return *this; }

void Team::add(Character *member)
{
    if (member == nullptr)
    {
    }
    else if (this->team.size() == 10)
    {
    }
    else
    {
        this->team.push_back(member);
    }
}
void Team::attack(Team *enemy_team) {}
int Team::stillAlive()
{
    int counter_alive = 0;
    for (unsigned long i = 0; i < this->team.size(); i++)
    {
        if (this->team.at(i) != nullptr && this->team.at(i)->isAlive() == true)
        {
            counter_alive = counter_alive + 1;
        }
    }
    return counter_alive;
}
void Team::print() {}
