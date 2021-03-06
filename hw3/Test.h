#pragma once

#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "Tree.h"
#include "iostream"

class Test:public QObject
{
    Q_OBJECT

public:
    explicit Test(QObject *parent = 0):QObject(parent){}

private slots:
    void init()
    {
        t = new Tree<int>;
    }

    void cleanup()
    {
        delete t;
    }

    void TestLength()
    {
        QCOMPARE(t->length(), 0);
    }

    void TestAdd()
    {
        t->add(5);
        t->add(6);
        QVERIFY(t->search(6) && t->search(6));
    }

    void TestAddCounter()
    {
        t->add(5);
        t->add(7);
        t->add(6);
        QCOMPARE(t->length(), 3);
    }

    void TestRemoveNodeFirst()
    {
        t->add(6);
        t->add(6);
        t->RemoveNode(6);
        QVERIFY(t->search(6));
        QCOMPARE(t->length(), 1);
        t->RemoveNode(6);
        QVERIFY(!t->search(6));
        QCOMPARE(t->length(), 0);
    }

    void TestRemoveNodeSecond()
    {
        t->add(6);
        t->RemoveNode(6);
        QVERIFY(!t->search(6));
        QCOMPARE(t->length(), 0);
    }

    void TestRemoveNodeThird()
    {
        t->add(6);
        t->add(7);
        t->RemoveNode(6);
        QVERIFY(!t->search(6) && t->search(7));
        QCOMPARE(t->length(), 1);
    }

    void TestRemoveNodeFourth()
    {
        t->add(6);
        t->add(5);
        t->RemoveNode(6);
        QVERIFY(!t->search(6) && t->search(5));
        QCOMPARE(t->length(), 1);
    }

    void TestRemoveNodeFifth()
    {
        t->add(6);
        t->add(5);
        t->add(7);
        t->RemoveNode(6);
        QVERIFY(!t->search(6) && t->search(5) && t->search(7));
        QCOMPARE(t->length(), 2);
    }

    void TestHeight()
    {
        t->add(4);
        t->add(2);
        t->add(0);
        t->add(1);
        t->add(3);
        t->add(9);
        t->add(6);
        t->add(5);
        t->add(8);
        t->add(7);
        t->add(5);
        QCOMPARE(t->height(), 4);
    }

    void TestPrint()
    {
        t->add(0);
        t->add(1);
        t->add(2);
        t->add(3);
        t->add(4);
        t->add(5);
        t->add(6);
        t->add(7);
        t->add(8);
        t->add(8);
        t->add(9);
        string str = "0 1 2 3 4 5 6 7 8 8 9 ";
        QCOMPARE(t->print(), str);
    }

    void TestValueIterator()
    {
        t->add(5);
        t->add(7);
        t->add(4);
        Tree<int>::Iterator it = Tree<int>::Iterator(t->first());
        QCOMPARE(*it, 4);
    }

       void TestIteratorEqually()
       {
           t->add(0);
           t->add(1);
           Tree<int>::Iterator it = Tree<int>::Iterator(t->first());
           Tree<int>::Iterator it2 = Tree<int>::Iterator(t->first());
           QVERIFY(it == it2);
       }

       void TestIteratorNotEqually()
       {
           t->add(0);
           t->add(1);
           Tree<int>::Iterator it = Tree<int>::Iterator(t->first());
           Tree<int>::Iterator it2 = Tree<int>::Iterator(t->last());
           QVERIFY(it != it2);
       }

private:
    Tree<int> *t;
};
