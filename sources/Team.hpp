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
private:
    vector<Character *> team;
    Character *_leader;

public:
    Team();
    Team(Character *leader);
    virtual ~Team();
    Team(const Team &temp);
    Team &operator=(const Team &other);
    Team(Team &&other) noexcept;
    Team &operator=(Team &&other) noexcept;

    vector<Character *> &getTeam();
    Character &getLeader();
    void setLeader(Character *new_laeder);

    void add(Character *member);
    virtual void attack(Team *enemy_team);
    int stillAlive();
    virtual void print();
    Character *find_new_leader(Team *team);
    Character *find_victim(Team *enemy_team);
};