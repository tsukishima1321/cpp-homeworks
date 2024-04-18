// 实验七：指针和数组
// 利用指针将一个包含10个整数的数组中的最大最小元素进行交换，并输出交换后的内容。10个整数为随机产生的0~100之间的数。
// （若最大最小元素不唯一，则交换任意两个都算正确，即可以不用特殊考虑不唯一的情况）

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int getRand(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand((unsigned)time(0));
    int a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = getRand(0, 100);
        cout << a[i] << " ";
    }
    cout << endl;
    int *max = a, *min = a;
    for (int *i = a; i < a + 10; i++) {
        if (*max < *i) {
            max = i;
        }
        if (*min > *i) {
            min = i;
        }
    }

    // 或者：
    /*
    for (int i = 0; i < 10; i++) {
        if (*max < a[i]) {
            max = &a[i];
            // 或者：
            // max = a + i;
        }
        if (*min > a[i]) {
            min = &a[i];
        }
    }*/

    int t = *max;
    *max = *min;
    *min = t;
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}