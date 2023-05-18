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
Team::Team() {}

Team::Team(Character *leader) : _leader(leader)
{
    if (leader == nullptr)
    {
        return;
    }
    this->team.push_back(leader);
    this->_leader = leader;
}

Team::~Team()
{
    for (Character *character : this->team)
    {
        if (dynamic_cast<Cowboy *>(character))
        {
            delete character;
        }
    }
    for (Character *character : this->team)
    {
        if (dynamic_cast<Ninja *>(character))
        {
            delete character;
        }
    }
}
Team::Team(const Team &temp) {}
Team &Team::operator=(const Team &other) {}
Team::Team(Team &&other) noexcept {}
Team &Team::operator=(Team &&other) noexcept { return *this; }

void Team::add(Character *member)
{
    if (member == nullptr)
    {
        return;
    }
    else if (this->team.size() == 10)
    {
        return;
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

void Team::print()
{
    for (Character *character : this->team)
    {
        if (dynamic_cast<Cowboy *>(character))
        {
            character->print();
        }
    }
    for (Character *character : this->team)
    {
        if (dynamic_cast<Ninja *>(character))
        {
            character->print();
        }
    }
}
