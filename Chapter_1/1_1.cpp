// 实验一：c/c++概述
// 以下程序的功能是借助一个变量交换两个已知数据的值，程序中存在一些错误，修改这些错误并调试程序。
/*
#include "iostream"
using namespace std;

int main( )
{
        int  x,y;
        t=x;
        x=y;
        t=y;
        cin>>x>>y>>endl;
        cout<<"x="<<x<<"y="<<y<<endl;
        system("pause");
        return 0;
‍}
*/

#include <iostream> //两种写法查找位置和优先级的不同，应尽量使用<>

using namespace std;
int main() {
    int x, y;
    cin >> x >> y; // 先输入再进行操作
    int t = x;     // 变量t需要声明
    x = y;
    y = t; // 存在逻辑错误
    cout << "x=" << x << " y=" << y << endl;
    system("pause");
    return 0;
}