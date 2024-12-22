// 实验四：循环结构
// 编一程序，显示出所有的水仙花数。所谓水仙花数，是指一个3位数，其各位数字立方和等于该数字本身。

#include <iostream>

using namespace std;

// 法1：
int main_() {
    for (int i = 100; i < 1000; i++) {
        int a, b, c;
        a = i % 10;
        b = i / 10 % 10;
        c = i / 100;
        if (i == a * a * a + b * b * b + c * c * c) {
            cout << i << endl;
        }
    }
    system("pause");
    return 0;
}

// 法2：位数可拓展
int main() {
    for (int i = 100; i < 1000; i++) {
        int a[3];
        int i_t = i;
        for (int j = 0; j < 3; j++) {
            a[j] = i_t % 10;
            i_t = i_t / 10;
        }
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += a[j] * a[j] * a[j];
        }
        if (i == sum) {
            cout << i << endl;
        }
    }
    system("pause");
    return 0;
}