//
//
#include "List.hpp"
#include <iostream>

int main() {
    MyList::List<int> list;
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
    system("pause");
    return 0;
}