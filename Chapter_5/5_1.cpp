// 实验5：一维数组
// 随机产生10个30~100(包括30，100)的正整数，求它们的最大值、最小值、平均值，并显示整个数组的值和结果。

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
    for (int i = 0; i < 10; i++) {
        a[i] = getRand(30, 100);
    }
    int min = 200, max = 0, sum = 0;
    cout << "数组为：" << endl;
    for (int i = 0; i < 10; i++) {
        if (a[i] > max) {
            max = a[i];
        }
        if (a[i] < min) {
            min = a[i];
        }
        sum += a[i];
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "最大值：" << max << endl
         << "最小值：" << min << endl
         << "平均值：" << sum * 1.0 / 10 << endl;

    system("pause");
    return 0;
}