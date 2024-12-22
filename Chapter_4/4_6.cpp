// 实验四：循环结构
// 用迭代法求a的三次方根
// 迭代公式：x[i+1]=2/3 x[i] + a/(3 x[i]^2)

#include <cmath>
#include <iostream>

using namespace std;

int main() {
    double a;
    cout << "请输入a:" << endl;
    cin >> a;
    double x1, x0;
    x0 = a;
    while (1) {
        x1 = (2 * x0 + a / (x0 * x0)) / 3;
        if (abs(x1 - x0) < 0.00001) {
            break;
        }
        x0 = x1;
    }
    cout << x1 << endl;
    system("pause");
    return 0;
}