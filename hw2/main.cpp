#include <QtCore/QCoreApplication>
#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include <QTime>

using namespace std;
const int density = 30;
const int osWin = 75;
const int osMac = 87;
const int osLin = 95;
const int num = 25;

void printInf(bool* virus)
{
    cout << "Infected: ";
    for (int i = 0; i < num; i++)
        if (virus[i])
            cout << i + 1 << " ";
    cout << "\nUninfected: ";
    for (int i = 0; i < num; i++)
        if (!virus[i])
            cout << i + 1 << " ";
    cout << "\n\n";
}

int main()
{
    QTime  time = QTime ::currentTime();
    qsrand((uint)time.msec());
    cout << num << " computers in the network\n\n";
    bool mas[num][num];
    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++)
            mas[i][j] = false;
    int den[num];
    den[0] = osWin;
    den[1] = osMac;
    den[2] = osLin;
    int i = 3;
    while (i < num)
    {
        den[i] = den[i-3];
        i++;
    }
    bool virus[num];
    for (int i = 0; i < num; i++)
        virus[i] = false;
    i = qrand() % num;
    virus[i] = true;
    int numOfInf = 1;

    for (int i = 0; i < num - 1; i++)
        for (int j = i + 1; j < num; j++)
        {
            int dens = qrand() % 100;
            if (dens < density)
            {
                mas[i][j] = true;
                mas[j][i] = true;
            }
        }

    /*for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (mas[i][j])
                cout << "1";
            else
                cout << "0";
        }
        cout << "\n";
    }*/

    printInf(virus);
    char c;
    while (numOfInf < num)
    {
        cout << "input something to go to the next day: ";
        cin >> &c;
        for (int i = 0; i < num; i++)
        {
            if (virus[i])
            {
                for (int j = 0; j  < num; j++)
                    if ((mas[i][j]) && (!virus[j]))
                    {
                        int ver = qrand() % 100;
                        if (ver >= den[j])
                        {
                            cout << "virus spread from " << i + 1 <<" to " << j + 1 << "\n";
                            virus[j] = true;
                            numOfInf++;
                        }
                    }
            }
        }
        printInf(virus);
    }

    cout << "Congratulations, all computers are infected!:)\n";


    return 0;
}
