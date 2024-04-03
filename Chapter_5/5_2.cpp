// 实验5：一维数组
// 随机产生20个学生的计算机课程的成绩（0～100），按照从大到小的顺序排序，分别显示排序前和排序后的结果。
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
    int a[20] = {};
    cout << "排序前：" << endl;
    for (int i = 0; i < 20; i++) {
        a[i] = getRand(0, 100);
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 20; i++) {//冒泡排序
        for (int j = 0; j < 20 - 1 - i; j++) {
            if (a[j] < a[j + 1]) {
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }

    cout << "排序后：" << endl;
    for (int i = 0; i < 20; i++) {
        cout << a[i] << " ";
    }

    system("pause");
    return 0;
}