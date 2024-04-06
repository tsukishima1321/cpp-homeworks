// 使用VScode编译多文件项目时，将task.json中的${file}替换为${fileDirname}\\*.cpp
//
#include "LargeNum.h"
#include <iostream>

using namespace std;

int main() {
#ifdef _WIN32
    system("chcp 65001");
#endif
    /*
        LargeNum a = LargeNum::fromString("1145141919810666");
        LargeNum b = LargeNum::fromString("1919810114514");
        LargeNum c;
        int d = 114514;
        cin >> c;
        cout << c * 10 << endl;
        cout << "a+b:" << a + b << endl;
        cout << "a-b:" << a - b << endl;
        cout << "a*b:" << a * b << endl;
        cout << "a/b:" << a / b << endl;
        cout << "a%b:" << a % b << endl;
        c = a + 2 * b + d;
        cout << c << endl;
        c *= 20;
        cout << c << endl;
        cout << (a > b) << (a < b) << (a >= b) << (a <= b) << (a == b) << endl;
        a = 0;
        a = -a;
        b = 0;
        cout << (a > b) << (a < b) << (a >= b) << (a <= b) << (a == b) << endl;
    */
    LargeNum a = 114;
    LargeNum b = -514;
    LargeNum c = a + b;
    cout << c;
    system("pause");
    return 0;
}