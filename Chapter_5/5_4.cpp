// 实验5：一维数组
// 按由大到小的顺序输入10个int类型的数据将其存放在一个一维数组中，
// 再输入一个整数到变量x，用二分法查找x是否是数组中的元素，若是，输出其在数组中的位置，否则输出不在数组中的提示。

#include <iostream>

using namespace std;

int getRand(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int a[10] = {};
    cout << "请由大到小输入十个整数:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    cout << "请输入要查找的整数：" << endl;
    int x;
    cin >> x;
    int left = 0, right = 9, middle;
    while (left <= right) {
        middle = (left + right) / 2;
        if (a[middle] < x) {
            right = middle - 1;
        } else if (a[middle] > x) {
            left = middle + 1;
        } else {
            break;
        }
    }
    if (a[middle] == x) {
        cout << middle;
    } else {
        cout << "不存在";
    }

    system("pause");
    return 0;
}