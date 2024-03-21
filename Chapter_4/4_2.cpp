// 实验四：循环结构
// 编写程序将一个十进制整数按倒序形式输出。即若输入156，则输出651。

#include <iostream>

using namespace std;

int main()
{
    int a;
    cout << "请输入一个整数：" << endl;
    cin >> a;
    while (a > 0)
    {
        cout << a % 10;
        a = a / 10;
    }
    system("pause");
    return 0;
}