#include <iostream>
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Team.hpp"
#include "Team2.hpp"
#include "vector"
using namespace std;

Team2::Team2(Character *leader) : Team(leader) {}
Team2::~Team2() {}
Team2::Team2(const Team2 &temp) {}
Team2 &Team2::operator=(const Team2 &other) { return *this; }
Team2::Team2(Team2 &&other) noexcept {}
Team2 &Team2::operator=(Team2 &&other) noexcept { return *this; }

void Team2::attack(Team *enemy_team)
{
    if (enemy_team == nullptr)
    {
        throw invalid_argument("");
    }
    if (this->stillAlive() == 0)
    {
        return;
    }
    if (enemy_team->stillAlive() == 0)
    {
        throw runtime_error("");
    }
    if (this->getLeader().isAlive() == false)
    {
        this->setLeader(find_new_leader(this)); // finding new leader for the attacking team
    }
    Character *victim = find_victim(enemy_team); // finding a victim in the enmy team
    for (Character *temp : this->getTeam())      // starting the attack with cowboys.
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

void Team2::print()
{
    for (Character *character : this->getTeam())
    {
        if (dynamic_cast<Cowboy *>(character))
        {
            dynamic_cast<Cowboy *>(character)->print();
        }
        if (dynamic_cast<Ninja *>(character))
        {
            dynamic_cast<Ninja *>(character)->print();
        }
    }
}