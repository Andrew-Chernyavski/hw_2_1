#include <iostream>
#include "tree.h"
#include "Test.h"
using namespace std;

int main()
{
//    Test test;
//    QTest::qExec(&test);

    Tree<int> *t = new Tree<int>;
    t->add(1);
    t->add(0);
    t->add(9);
    t->add(10);
    t->add(4);
    Tree<int>::Iterator it = Tree<int>::Iterator(t->first());
    Tree<int>::Iterator it2 = Tree<int>::Iterator(t->first());
    while (*it != 4)
        ++it;
    it2 = it;
    ++it2;
    std::cout << *it << "\n";//4
    std::cout << *it2 << "\n";//9
    t->RemoveNode(9);
    std::cout << "after removing\n";
    std::cout << *it << "\n";//4
    ++it;
    std::cout << *it << "\n";//10
    std::cout << *it2 << "\n";//10

    return 0;
}

