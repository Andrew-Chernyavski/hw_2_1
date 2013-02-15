#include "Test.h"
#include "Web.h"
#include "PC.h"
#include "iostream"

int main()
{
    Test test;
    QTest::qExec(&test);

//    PC *PCs[numberOfPCs];
//    PCs[0] = new PC(8, 0);
//    PCs[1] = new PC(4, 0);
//    PCs[2] = new PC(2, 0);
//    PCs[3] = new PC(8, 0);
//    PCs[4] = new PC(8, 1);
//    int array[numberOfPCs][numberOfPCs] =
//    {
//        {0, 1, 1, 0, 0},
//        {1, 0, 0, 1, 0},
//        {1, 0, 0, 1, 1},
//        {0, 1, 1, 0, 0},
//        {0, 0, 1, 0, 0}
//    };
//    int *network[numberOfPCs];
//    for (int i = 0; i < numberOfPCs; i++)
//        network[i] = array[i];
//    Web *obj;
//    obj = new Web(PCs, network, true);

//    std::cout << obj->nextDay() << "\n";
//    std::cout << obj->nextDay() << "\n";
//    std::cout << obj->nextDay() << "\n";
//    std::cout << obj->nextDay() << "\n";
//    std::cout << obj->nextDay() << "\n";
    return 0;
}
