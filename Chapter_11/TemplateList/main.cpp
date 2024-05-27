//
//
#include "LargeNum.h"
#include "List.hpp"
#include <iostream>

int main() {
    MyList::List<int> list{1, 2, 3, 4, 5};
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);
    list.push_front(-1);
    list.push_front(-2);
    for (auto p = list.begin(); p != list.end(); p++) {
        *p += 1;
    }
    for (auto &v : list) {
        v += 1;
        std::cout << v << " ";
    }
    getchar();
    MyList::List<LargeNum> list2;
    LargeNum a(1);
    list2.push_back(a);
    list2.push_back(LargeNum(2));
    list2.push_back(a + 5);
    for (auto &v : list2) {
        v += 1;
        std::cout << v << " ";
    }
    system("pause");
    return 0;
}