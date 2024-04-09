// 实验六：二维数组、字符数组
// 编写程序，将两个已知字符串中第二个字符串连接到第一个字符串的后面，并将连接后的第一个字符串的内容输出。
#include <iostream>

using std::cin, std::cout, std::endl;

int main() {
#ifdef _WIN32
    system("chcp 65001");
#endif

    char a[100];
    char b[100];

    cin >> a;
    cin >> b;
    int i;
    for (i = 0; a[i] != '\0'; i++);
    int j;
    for (j = 0; b[j] != '\0'; j++) {
        a[i + j] = b[j];
    }
    a[i + j] = '\0';
    cout << a << endl;
    system("pause");
    return 0;
}