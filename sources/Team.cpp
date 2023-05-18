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
#include <cfloat>
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
        if (character != nullptr)
        {
            if (dynamic_cast<Cowboy *>(character))
            {
                delete character;
            }
        }
    }
    for (Character *character : this->team)
    {
        if (character != nullptr)
        {
            if (dynamic_cast<Ninja *>(character))
            {
                delete character;
            }
        }
    }
}
Team::Team(const Team &temp) {}
Team &Team::operator=(const Team &other) { return *this; }
Team::Team(Team &&other) noexcept {}
Team &Team::operator=(Team &&other) noexcept { return *this; }

vector<Character *> Team::getTeam()
{
    return this->team;
}

Character &Team::getLeader()
{
    return *this->_leader;
}

void Team::setLeader(Character *new_laeder)
{
    this->_leader = new_laeder;
}

void Team::add(Character *member)
{
    if (member == nullptr || this->team.size() == 10)
    {
        return;
    }
    // else if (this->team.size() == 10)
    // {
    //     return;
    // }
    else
    {
        this->team.push_back(member);
    }
}
void Team::attack(Team *enemy_team)
{
    if (enemy_team == nullptr)
    {
        return;
    }
    if (this->stillAlive() == 0)
    {
        return;
    }
    if (enemy_team->stillAlive() == 0)
    {
        return;
    }
    if (this->_leader->isAlive() == false)
    {
        this->_leader = find_new_leader(this); // finding new leader for the attacking team
    }
    Character *victim = find_victim(enemy_team); // finding a victim in the enmy team
    for (Character *temp : this->team)           // starting the attack with cowboys.
    {
        if (temp->isAlive() == true && dynamic_cast<Cowboy *>(temp))
        {
            if (victim->isAlive() == true)
            {
                if (dynamic_cast<Cowboy *>(temp)->getNumOfBullets() > 0)
                {
                    dynamic_cast<Cowboy *>(temp)->shoot(victim);
                }
                else
                {
                    dynamic_cast<Cowboy *>(temp)->reload();
                }
            }
            else
            {
                if (enemy_team->stillAlive() == 0)
                {
                    return;
                }
                else
                {
                    victim = find_victim(enemy_team);
                }
            }
        }
    }
    for (Character *temp : this->team) // continuing the attack with ninjas.
    {
        if (temp->isAlive() == true && dynamic_cast<Ninja *>(temp))
        {
            if (victim->isAlive() == true)
            {
                if (dynamic_cast<OldNinja *>(temp))
                {
                    if (dynamic_cast<OldNinja *>(temp)->distance(victim) <= 1.0)
                    {
                        dynamic_cast<OldNinja *>(temp)->slash(victim);
                    }
                    else
                    {
                        dynamic_cast<OldNinja *>(temp)->move(victim);
                    }
                }
                else if (dynamic_cast<TrainedNinja *>(temp))
                {
                    if (dynamic_cast<TrainedNinja *>(temp)->distance(victim) <= 1.0)
                    {
                        dynamic_cast<TrainedNinja *>(temp)->slash(victim);
                    }
                    else
                    {
                        dynamic_cast<TrainedNinja *>(temp)->move(victim);
                    }
                }
                else if (dynamic_cast<YoungNinja *>(temp))
                {
                    if (dynamic_cast<YoungNinja *>(temp)->distance(victim) <= 1.0)
                    {
                        dynamic_cast<YoungNinja *>(temp)->slash(victim);
                    }
                    else
                    {
                        dynamic_cast<YoungNinja *>(temp)->move(victim);
                    }
                }
            }
            else
            {
                if (enemy_team->stillAlive() == 0)
                {
                    return;
                }
                else
                {
                    victim = find_victim(enemy_team);
                }
            }
        }
    }
}

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

Character *Team::find_new_leader(Team *team)
{
    double dist = DBL_MAX;
    Character *new_leader = nullptr;
    for (Character *temp : team->team)
    {
        if (temp != nullptr && temp->isAlive() == true && temp->distance(team->_leader) < dist)
        {
            dist = temp->distance(team->_leader);
            new_leader = temp;
        }
    }
    return new_leader;
}

Character *Team::find_victim(Team *enemy_team)
{
    double dist = DBL_MAX;
    Character *victim = nullptr;
    for (Character *temp : enemy_team->team)
    {
        if (temp != nullptr && temp->isAlive() == true && temp->distance(this->_leader) < dist)
        {
            dist = temp->distance(this->_leader);
            victim = temp;
        }
    }
    return victim;
}
