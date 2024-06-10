#include "MyStr.h"
#include <iostream>

#include <algorithm>

int main() {
    Mystring s1;
    s1 = "Hello";
    Mystring s2("World");
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << "Length of s1: " << s1.length() << std::endl;
    std::cout << "Length of s2: " << s2.length() << std::endl;
    s1 = s1 + " " + s2;
    std::cout << s1 << std::endl;
    for(auto c: s1){
        std::cout << c << " ";
    }
    Mystring::Iterator it = s1.begin();
    std::cout << *it << std::endl;
    std::sort(s1.begin(), s1.end());
    std::cout << s1 << std::endl;
    system("pause");
    return 0;
}