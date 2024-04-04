// 高精度运算
// 计算正整数加、乘、除的结果，其中除数为int范围，其余数据范围为0<=a<1e1000
// 知识点：数组、字符串

// 使用VScode编译多文件项目时，将task.json中的${file}替换为${fileDirname}\\*.cpp

#include <iostream>
#include <string>

#define N 2000 // 所有高精度数的最大位数

using namespace std;

int pow10(int a) {
    int p = 1;
    for (int i = 0; i < a; i++) {
        p *= 10;
    }
    return p;
}

void init(int a[N]) {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        a[i] = s[s.length() - i - 1] - '0';
    }
}

string render(const int a[N]) {
    string res = "";
    bool f = false;
    for (int i = N - 1; i >= 0; i--) {
        if (!f && a[i] != 0) {
            f = true;
        }
        if (f) {
            res += char(a[i] + '0');
        }
    }
    if (!f) {
        res = "0";
    }
    return res;
}

int add(const int a[N], const int b[N], int target[N]) {
    for (int i = 0; i < N; i++) {
        target[i] += a[i] + b[i];
        if (target[i] >= 10) {
            if (i < N - 1) {
                target[i] %= 10;
                target[i + 1] += 1;
            } else {
                // 结果溢出
                return -1;
            }
        }
    }
    return 0;
}

int time(const int a[N], const int b[N], int target[N]) {
    for (int i = 0; i < N; i++) {
        int n = 0;
        for (int j = 0; j < N; j++) {
            if (i + j > N - 1) {
                if (a[i] * b[j] + n > 0) {
                    return -1; // 结果溢出
                } else {
                    continue;
                }
            }
            target[i + j] += a[i] * b[j] + n;
            n = target[i + j] / 10;
            target[i + j] %= 10;
        }
    }
    return 0;
}

int devide(const int a[N], int b, int target[N], int *remain) {
    int l = 0;
    int b_ = b;
    while (b_) { // 获取除数的位数，存入l
        b_ /= 10;
        l++;
    }
    int i;
    for (i = N - 1; i >= 0; i--) { // 跳过所有前导零，此后i即为a的最高位的位数
        if (a[i] != 0) {
            break;
        }
    }
    if (i + 1 < l) { // 被除数位数小于除数，直接将被除数作为余数输出
        *remain = 0;
        for (int j = 0; j <= i; j++) {
            *remain += pow10(i - j) * a[i - j];
        }
        return 0;
    }
    int n; // 每次除法余数中最高位的部分
    long long a_front = 0;
    for (int j = 0; j < l; j++) { // 在高位截取被除数与除数位数相同的一段，存入a_front
        a_front += pow10(l - j - 1) * a[i - j];
    }
    target[i - l + 1] = a_front / b;
    for (int j = i - l; j >= 0; j--) {
        a_front %= b;
        n = a_front / pow10(l - 1);
        a_front = a_front % pow10(l - 1) * 10 + a[j] + pow10(l) * n;
        target[j] = a_front / b;
    }
    *remain = a_front % b;
    return 0;
}

// 面向对象的写法：
#include "LargeNum.h"

int main() {
#ifdef _WIN32
    system("chcp 65001");
#endif
    /*int a[N] = {};
    //int b[N] = {};
    init(a);
    //init(b);
    int d;
    cin >> d;
    int c[N] = {};
    int r;
    devide(a, d, c, &r);
    cout << "商：" << render(c) << "  余数:" << r << endl;*/
    LargeNum a;
    LargeNum b;
    int c;
    cin >> a >> b;
    cout << "a+b:" << a + b << endl;
    cout << "a-b:" << a - b << endl;
    cout << "a*b:" << a * b << endl;
    cout << "a/b:" << a / b << endl;
    cout << "a%b:" << a % b << endl;
    cout << (a > b) << (a < b) << (a >= b) << (a <= b) << (a == b);
    system("pause");
    return 0;
}
