#ifndef TEST_H
#define TEST_H

#endif // TEST_H
#pragma once

#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "Web.h"
#include "iostream"

class Test:public QObject
{
    Q_OBJECT

public:
    explicit Test(QObject *parent = 0):QObject(parent){}

private slots:
    void init()
    {
        PCs[0] = new PC(8, 0);
        PCs[1] = new PC(4, 0);
        PCs[2] = new PC(2, 0);
        PCs[3] = new PC(8, 0);
        PCs[4] = new PC(8, 1);
        int array[numberOfPCs][numberOfPCs] =
        {
            {0, 1, 1, 0, 0},
            {1, 0, 0, 1, 0},
            {1, 0, 0, 1, 1},
            {0, 1, 1, 0, 0},
            {0, 0, 1, 0, 0}
        };
        int *network[numberOfPCs];
        for (int i = 0; i < numberOfPCs; ++i)
            network[i] = array[i];
        obj = new Web(PCs, network, true);
        PCs2[0] = new PC(2, 1);
        PCs2[1] = new PC(4, 1);
        PCs2[2] = new PC(8, 1);
        PCs2[3] = new PC(2, 1);
        PCs2[4] = new PC(8, 1);
        obj2 = new Web(PCs2, network, true);

    }

    void cleanup()
    {
        for (int i = 0; i < numberOfPCs; i++)
        {
            delete PCs[i];
            delete PCs2[i];
        }
        delete obj;
        delete obj2;
    }

    void TestFinish()
    {
        QVERIFY(!obj->finish() && obj2->finish());
    }

    void TestStatus()
    {
        int a = 5;//00005
        QVERIFY(a == obj->status());


    }

    void TestStepByStep()
    {
        QVERIFY(5 == obj->nextDay());
        QVERIFY(305 == obj->nextDay());
        QVERIFY(305 == obj->nextDay());
        QVERIFY(305 == obj->nextDay());
        QVERIFY(10305 == obj->nextDay());
    }

private:
    PC *PCs[numberOfPCs];
    PC *PCs2[numberOfPCs];
    Web *obj;
    Web *obj2;
};
