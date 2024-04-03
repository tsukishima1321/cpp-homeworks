// 实验5：一维数组
// 随机产生10个数，输入1~10之间的正整数m，使数组元素右移m位，移出的元素再从左移入。
// 如，假设原来的数组元素依次为：1  2  3  4  5  6  7  8  9  10，
// 假设m为2，则右移2位后的数组元素依次为：9  10  1  2  3  4  5  6  7  8

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int getRand(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
#ifdef _WIN32
    system("chcp 65001");
#endif

    srand(time(0));
    int a[10] = {};
    cout << "原：" << endl;
    for (int i = 0; i < 10; i++) {
        a[i] = getRand(0, 100);
        cout << a[i] << " ";
    }
    cout << endl;
    int offset;
    cout << "请输入偏移的位数：" << endl;
    cin >> offset;
    int b[10] = {};
    for (int i = 0; i < 10; i++) {
        b[i] = a[(i - offset + 10) % 10];
        cout << b[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}