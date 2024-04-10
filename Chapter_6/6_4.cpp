// 实验六：二维数组、字符数组
// 输入一字符串，将该字符串中的大小写字母相互转换。如，假设原字符串的内容为“How are you”，则转换后的内容为“hOW ARE YOU”
#include <iostream>

using std::cin, std::cout, std::endl;

int main_() {
#ifdef _WIN32
    system("chcp 65001");
#endif

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
#ifdef _WIN32
    system("chcp 65001");
#endif

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

// string algorithm lambda
#include <algorithm>
#include <string>

int main_3() {
#ifdef _WIN32
    system("chcp 65001");
#endif

    std::string s;
    getline(cin, s);
    std::for_each(s.begin(), s.end(), [](char &c) {if (c >= 'a' && c <= 'z') {
            c += 'A' - 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c += 'a' - 'A';
        } });
    cout << s << endl;

    system("pause");
    return 0;
}

// range view
#include <ranges>
#include <string>

int main_3() {
#ifdef _WIN32
    system("chcp 65001");
#endif

    std::string s;
    getline(cin, s);
    auto operate = [](const char &c) {if (c >= 'a' && c <= 'z') {
            return c + 'A' - 'a';
        } else if (c >= 'A' && c <= 'Z') {
            return c + 'a' - 'A';
        }; };
    auto operated_s = s | std::views::transform(operate);
    cout << std::string(operated_s.begin(),operated_s.end()) << endl;

    system("pause");
    return 0;
}