// 实验三：选择结构
/*
以下程序的功能是求两个非0整数相除的商和余数。程序有几处错误，试找出它们加以修改，并上机验证修改结果。
#include "iostream"
using namespace std;
int main()
{
    int x, y, r1, r2;
    cin >> x >> y;
    if (x = 0 || y = 0)
        cout << "input error" << endl;
    else
    {
        if (x > y)
            r1 = x / y;
        r2 = x % y;
        else
            r1 = y / x;
        r2 = y % x;
    }
    cout << "商 = " << r1 << " 余数 =" << r2 << endl;
    system("pause");
    return 0;
}
*/
#include <iostream>
using namespace std;
int main() {
    int x, y, r1, r2;
    cin >> x >> y;
    if (x == 0 || y == 0)
        cout << "input error" << endl;
    else {
        if (x > y) {
            r1 = x / y;
            r2 = x % y;
        } else {
            r1 = y / x;
            r2 = y % x;
        }
    }
    cout << "商 = " << r1 << " 余数 = " << r2 << endl;
    system("pause");
    return 0;
}