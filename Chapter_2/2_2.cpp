// 实验2：顺序结构
// 任意输入3个整数数据，输出它们中最小的一个数。

#include <iostream>
using namespace std;

// 法一：
int main() {
    double x, y, z;
    cout << "请输入三个数：" << endl;
    cin >> x >> y >> z;
    if (x < y) {
        if (x < z) {
            cout << x << endl;
        } else {
            cout << z << endl;
        }
    } else {
        if (y < z) {
            cout << y << endl;
        } else {
            cout << z << endl;
        }
    }
    system("pause");
    return 0;
}

// 法二：
int main_2() {
    double x, y, z;
    cout << "请输入三个数：" << endl;
    cin >> x >> y >> z;
    double min = x;
    if (y < min) {
        min = y;
    }
    if (z < min) {
        min = z;
    }
    cout << min << endl;
    system("pause");
    return 0;
}

// 法3：
int main_3() {
    double x, y, z;
    cout << "请输入三个数：" << endl;
    cin >> x >> y >> z;
    cout << ((((x < y) ? x : y) < z) ? ((x < y) ? x : y) : z);
    system("pause");
    return 0;
}