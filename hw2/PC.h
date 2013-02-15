#pragma once

#include "cstdlib"
#include "time.h"
const int MAX_CHANCE = 10;
class PC
{
public:
    PC(int chance, bool status);
    void attack(int test);
    bool checkInf();
    int getChance();

private:
    int chanceOfInfection;
    bool isInfected;
};
