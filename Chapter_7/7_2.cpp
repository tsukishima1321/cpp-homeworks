// 实验七：指针和数组
// 利用字符指针将字符串s中从第n个字符开始的内容复制到字符串t中

#include <iostream>

using namespace std;

int main_() {
    char s[100];
    int n;
    cin >> s;
    cin >> n;
    char t[100] = {};
    for (char *c = s + n - 1; *c != '\0'; c++) {
        *(t + (c - s - n + 1)) = *c;
    }
    cout << t;

    system("pause");
    return 0;
}

// cstring
#include <cstring>

int main_2() {
    char s[100];
    int n;
    cin >> s;
    cin >> n;
    char t[100] = {};
    strcpy(t, s + n - 1);
    cout << t;

    system("pause");
    return 0;
}