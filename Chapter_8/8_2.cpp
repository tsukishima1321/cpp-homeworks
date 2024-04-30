// 实验八：函数
// 编一函数，功能为判断一字符串是否为回文，如果是回文则返回1，否则返回0。
// 回文是指顺读和倒读都一样的字符串，如“deed”和“level”是回文。在主函数中对输入的字符串加以调用。

#include <iostream>
#include <cstring>

using namespace std;

int huiwen(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];
    cin >> str;
    if (huiwen(str)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    system("pause");
    return 0;
}