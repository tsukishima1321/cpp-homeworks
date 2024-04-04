//
//
#include <iostream>
#include "LargeNum.h"

using namespace std;

int main()
{
    #ifdef _WIN32
    system("chcp 65001");
    #endif
    LargeNum a = LargeNum::fromString("1145141919810666");
    LargeNum b = LargeNum::fromString("1919810114514");;
    int c;
    cout << "a+b:" << a + b << endl;
    cout << "a-b:" << a - b << endl;
    cout << "a*b:" << a * b << endl;
    cout << "a/b:" << a / b << endl;
    cout << "a%b:" << a % b << endl;
    cout << (a > b) << (a < b) << (a >= b) << (a <= b) << (a == b);
    a = 0;
    a = -a;
    b = 0;
    cout << (a > b) << (a < b) << (a >= b) << (a <= b) << (a == b);
    system("pause");
    return 0;
}