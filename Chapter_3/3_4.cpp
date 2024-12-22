// 实验三：选择结构
// 计算一元二次方程
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    double a, b, c;
    cout << "请输入三个参数" << endl;
    cin >> a >> b >> c;
    double delta = b * b - 4 * a * c;
    if (delta < 0) {
        cout << "方程无实根" << endl;
        system("pause");
        return 0;
    }
    double x1, x2;
    x1 = (-b + sqrt(delta)) / (2 * a);
    x2 = (-b - sqrt(delta)) / (2 * a);
    cout << "x_1=" << x1 << ",x_2=" << x2 << endl;
    system("pause");
    return 0;
}