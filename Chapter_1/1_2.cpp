// 实验一：c/c++概述
// 编写一个计算梯形面积的程序。要求梯形的上底、下底和高在定义变量时直接赋值。

#include <iostream>
using namespace std;

int main()
{
    double l1, l2, h;
    l1 = 2;
    l2 = 3;
    h = 4;
    double s = (l1 + l2) * h * 0.5;
    cout << s << endl;
    system("pause");
    return 0;
}