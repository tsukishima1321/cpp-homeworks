// 实验六：二维数组、字符数组
/*编一个程序，输入一个字符串，将其倒序存放后输出。例如，假设原数组a的内容为“VISUAL C++PROGRAM”，倒序后数组a中的内容为“MAGORP++C LASUIV”。
要求：不能借助另外一个数组实现倒序存放。
*/
#include <iostream>

using namespace std;

int main() {
    char s[100];
    cin >> s;
    int length;
    for (length = 0; s[length] != '\0'; length++);
    for (int i = 0; i < length / 2; i++) {
        char temp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = temp;
    }
    cout << s;

    system("pause");
    return 0;
}