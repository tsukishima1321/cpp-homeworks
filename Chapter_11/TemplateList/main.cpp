//
//
#include "List.hpp"
#include <iostream>

int main() {
    MyList::List<int> list{1,2,3,4,5};
    /*
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
    }*/
    for (auto &v : list) {
        v += 1;
        std::cout << v << " ";
    }
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    MyList::List<int> list2(a, a+10);
    for (auto &v : list2) {
        v += 1;
        std::cout << v << " ";
    }
    system("pause");
    return 0;
}