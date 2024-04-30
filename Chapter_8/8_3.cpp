// 实验八：函数
/*函数的功能是将学生成绩从高分到低分排序，并统计优秀与不及格的人数。用下面两种方法实现：
（1）函数形式为：int fun1(int s[],int n,int *x)
要求优秀人数通过return返回，不及格人数通过指针参数返回结果。
（2）函数形式为：void fun2(int s[],int n,int &x,int &y)
要求优秀与不及格的人数通过引用参数返回结果。
分别编二个函数，学生人数从键盘输入
‍*/
#include <iostream>

using namespace std;

void ScoreSort(int s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (s[j] < s[j + 1]) {
                int temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int fun1(int s[], int n, int *x) {
    int a = 0;
    int b = 0;
    ScoreSort(s, n);
    for (int i = 0; i < n; i++) {
        if (s[i] >= 90) {
            a++;
        } else if (s[i] < 60) {
            b++;
        }
    }
    *x = b;
    return a;
}

void fun2(int s[], int n, int &x, int &y) {
    x = 0;
    y = 0;
    ScoreSort(s, n);
    for (int i = 0; i < n; i++) {
        if (s[i] >= 90) {
            x++;
        } else if (s[i] < 60) {
            y++;
        }
    }
}

int main() {
    int n;
    int scores[100] = {};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    int a, b;
    // a = fun1(scores, n, &b);
    fun2(scores, n, a, b);
    for (int i = 0; i < n; i++) {
        cout << scores[i] << endl;
    }
    cout << a << "\n"
         << b << endl;
    system("pause");
    return 0;
}