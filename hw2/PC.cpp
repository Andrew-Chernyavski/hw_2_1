#pragma once

#include "PC.h"
#include "iostream"
#include "sstream"
#include <string>

PC::PC(int chanse, bool status) : chanceOfInfection(chanse), isInfected(status)
{}

void PC::attack(int test)
{
    int risk = 0;
    if (test == -1)
        risk = rand() % MAX_CHANCE + 1;
    else
        risk = test;
    if (risk <= this->getChance())
        isInfected = true;
}

bool PC::checkInf()
{
    return isInfected;
}

int PC::getChance()
{
    return chanceOfInfection;
}
