// 实验2：顺序结构
// 任意输入3个整数数据，输出它们中最小的一个数。

#include <iostream>
using namespace std;

// 法一：
int main()
{
    double x, y, z;
    cout << "请输入三个数：" << endl;
    cin >> x >> y >> z;
    if (x < y)
    {
        if (x < z)
        {
            cout << x << endl;
        }
        else
        {
            cout << z << endl;
        }
    }
    else
    {
        if (y < z)
        {
            cout << y << endl;
        }
        else
        {
            cout << z << endl;
        }
    }
    system("pause");
    return 0;
}

// 法二：
int main_2()
{
    double x, y, z;
    cout << "请输入三个数：" << endl;
    cin >> x >> y >> z;
    if (y < x)
    {
        x = y;
    }
    if (z < x)
    {
        x = z;
    }
    cout << x << endl;
    system("pause");
}
