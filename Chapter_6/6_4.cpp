// 实验六：二维数组、字符数组
// 输入一字符串，将该字符串中的大小写字母相互转换。如，假设原字符串的内容为“How are you”，则转换后的内容为“hOW ARE YOU”
#include <iostream>

using std::cin, std::cout, std::endl;

int main_() {
    char s[100];
    cin.getline(s, 100);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] += 'A' - 'a';
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 'a' - 'A';
        }
    }
    cout << s << endl;

    system("pause");
    return 0;
}

// string
#include <string>

int main() {
    std::string s;
    getline(cin, s);
    for (char &c : s) {
        if (c >= 'a' && c <= 'z') {
            c += 'A' - 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c += 'a' - 'A';
        }
    }
    cout << s << endl;

    system("pause");
    return 0;
}