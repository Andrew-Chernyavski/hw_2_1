#pragma once

#include "PC.h"
#include "sstream"
#include <string>
#include <QList>

const int numberOfPCs = 5;

using namespace std;
class Web
{
public:
    Web(PC **comp, int *net[], bool isTest);
    int status();
    int nextDay();
    void runAll();
    bool finish();

private:
    PC **PCs;
    int *net_m[numberOfPCs];
    bool test;
    QList<int> list;
};
