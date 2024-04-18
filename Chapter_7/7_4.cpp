// 实验七：指针和数组
// 利用字符指针将一串字符倒序存放后输出。例如原数组a的内容为“VISUAL C++PROGRAM”，倒序后数组a中的内容为“MAGORP++C LASUIV”。
#include <iostream>

using namespace std;

int main() {
    char s[100];
    cin >> s;
    int length;
    for (length = 0; s[length] != '\0'; length++);
    for (char *i = s; i < s + length / 2; i++) {
        char temp = *i;
        *i = *(s + length - (i - s) - 1);
        *(s + length - (i - s) - 1) = temp;
    }
    cout << s;

    system("pause");
    return 0;
}