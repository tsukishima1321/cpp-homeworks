// 实验七：指针和数组
// 利用字符指针将输入的一个字符串中的大小写字母相互转换，并输出转换后的字符串的内容。如，假设输入的字符串的内容为“How are you”，则转换后的内容为“hOW ARE YOU”

#include <iostream>

using namespace std;

int main() {
#ifdef _WIN32
    system("chcp 65001");
#endif

    char s[100];
    cin.getline(s, 100);
    for (char *c = s; *c != '\0'; c++) {
        if (*c >= 'a' && *c <= 'z') {
            *c += 'A' - 'a';
        } else if (*c >= 'A' && *c <= 'Z') {
            *c += 'a' - 'A';
        }
    }
    cout << s << endl;

    system("pause");
    return 0;
}