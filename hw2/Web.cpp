#include "Web.h"
#include <ctime>
#include "iostream"

Web::Web(PC **comp, int *net[], bool isTest)
{
    if (!isTest)
        srand(time(0));
    else
    {
        //day 1: 5
        list.push_back(0);//5->3
        //day 2: 3,5
        list.push_back(10);//3->! 1
        list.push_back(10);//3->! 4
        //day 3: 3,5
        list.push_back(0);//3->1
        list.push_back(10);//3->! 4
        //day 4: 1,3,5
        list.push_back(0);//1->2
        list.push_back(0);//3->4
        //mafia wins

    }
    PCs = comp;
    for (int i = 0; i < numberOfPCs; i++)
        net_m[i] = net[i];
    test = isTest;
}

int Web::status()
{
    int out = 0;
    for (int i = 0; i < numberOfPCs; ++i)
    {
        out *= 10;
        if (PCs[i]->checkInf())
            out += i + 1;
    }
    return out;
}

int Web::nextDay()
{
    int out = status();

    for (int i = 0; i < numberOfPCs; i++)
        for (int j = 0; j < numberOfPCs; j++)
            if ((net_m[i][j] == 1) && (PCs[i]->checkInf()) && (!PCs[j]->checkInf()))
                if (test)
                    PCs[j]->attack(list.takeFirst());
                else
                    PCs[j]->attack(-1);
    return out;
}

void Web::runAll()
{
    while (!finish())
        std::cout << nextDay() << "\n";
    std::cout << status();
}

bool Web::finish()
{
    int k = 0;
    for (int i = 0; i < numberOfPCs; i++)
        if (PCs[i]->checkInf())
            k++;
    return k > numberOfPCs - 1;
}
