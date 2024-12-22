// 实验一：c/c++概述
// 编写计算一个学生三门课平均成绩的程序,要求学生成绩从键盘输入。

#include <iostream>
using namespace std;

int main() {
    double s1, s2, s3;
    cout << "请输入成绩：" << endl;
    cin >> s1 >> s2 >> s3;
    cout << "三门课的平均成绩为：" << (s1 + s2 + s3) / 3.0 << endl;
    system("pause");
    return 0;
}