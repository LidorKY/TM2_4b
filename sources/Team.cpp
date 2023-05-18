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
    if (leader->getAssigned() == true)
    {
        throw runtime_error("");
    }
    this->team.push_back(leader);
    this->_leader = leader;
    this->_leader->setAssigned(true);
}

Team::~Team()
{
    for (Character *character : this->team)
    {
        if (character != nullptr)
        {
            delete character;
        }
    }
}
Team::Team(const Team &temp) {}
Team &Team::operator=(const Team &other) { return *this; }
Team::Team(Team &&other) noexcept {}
Team &Team::operator=(Team &&other) noexcept { return *this; }

vector<Character *> Team::getTeam()
{
    return (this->team);
}

Character &Team::getLeader()
{
    return *(this->_leader);
}

void Team::setLeader(Character *new_laeder)
{
    this->_leader = new_laeder;
}

void Team::setTeam(Character *new_member)
{
    this->team.push_back(new_member);
}

void Team::add(Character *member)
{
    if (member == nullptr)
    {
        return;
    }
    else if (this->getTeam().size() == 10)
    {
        throw runtime_error("");
    }
    else if (member->getAssigned() == true)
    {
        throw runtime_error("");
    }
    else
    {
        this->setTeam(member);
        member->setAssigned(true);
    }
}
void Team::attack(Team *enemy_team)
{
    if (enemy_team == nullptr)
    {
        throw invalid_argument("");
    }
    if (this->stillAlive() == 0)
    {
        throw runtime_error("");
    }
    if (enemy_team->stillAlive() == 0)
    {
        throw runtime_error("");
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
                    if (dynamic_cast<OldNinja *>(temp)->distance(victim) < 1.0)
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
    for (Character *temp : this->team)
    {
        if (temp != nullptr)
        {
            if (temp->isAlive() == true)
            {
                counter_alive++;
            }
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
