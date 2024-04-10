// 实验六：二维数组、字符数组
// 编写程序，将某一指定字符从一个已知的字符串中删除。假设已知字符串为“aaaasdfga”，将其中出现的'a'字母删除，删除后的字符串为“sdfg”。
#include <iostream>

using std::cin, std::cout, std::endl, std::string;

int main_() {
#ifdef _WIN32
    system("chcp 65001");
#endif

    char s[100];
    cout << "要处理的字符串：" << endl;
    cin >> s;
    cout << "要删除的字符：" << endl;
    char c;
    cin >> c;
    int i, j;
    for (i = 0, j = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            s[j] = s[i];
            j++;
        }
    }
    for (i = j; i < 100; i++) {
        s[i] = '\0';
    }
    cout << s;
    system("pause");
    return 0;
}

// 使用string:
#include <string>

int main_2() {
#ifdef _WIN32
    system("chcp 65001");
#endif

    string s;
    cout << "要处理的字符串：" << endl;
    cin >> s;
    cout << "要删除的字符：" << endl;
    char c;
    cin >> c;
    for (int i = 0; i < s.length() /*每次都会重新计算s.length()*/; i++) {
        if (s[i] == c) {
            s.erase(i, 1);
            i--;
        }
    }
    cout << s;
    system("pause");
    return 0;
}

// 使用string iterator:
#include <string>

int main_3() {
#ifdef _WIN32
    system("chcp 65001");
#endif

    string s;
    cout << "要处理的字符串：" << endl;
    cin >> s;
    cout << "要删除的字符：" << endl;
    char c;
    cin >> c;
    for (string::iterator i = s.begin(); i != s.end(); i++) {
        if (*i == c) {
            s.erase(i);
            i--;
        }
    }
    cout << s;
    system("pause");
    return 0;
}

// 使用algorithm std::remove:
#include <algorithm>
#include <string>

int main_4() {
#ifdef _WIN32
    system("chcp 65001");
#endif

    string s;
    cout << "要处理的字符串：" << endl;
    cin >> s;
    cout << "要删除的字符：" << endl;
    char c;
    cin >> c;
    string::iterator new_end = remove(s.begin(), s.end(), c);
    s.erase(new_end, s.end());
    cout << s;
    system("pause");
    return 0;
}

// algorithm std::remove_if
// 几种构造callable对象的方法：（泛型）仿函数，（泛型）lambda表达式
#include <algorithm>
#include <string>

// c++20
#include <concepts>

class equal_to_char {
public:
    equal_to_char(char c) {
        this->c = c;
    }
    bool operator()(char t) {
        return t == c;
    }

private:
    char c;
};

/*
c++20
使用concept简化报错信息和内联提示
template <std::regular T>
*/
template <typename T>
class equal_to {
public:
    equal_to(const T &c) {
        this->c = c;
    }
    bool operator()(const T &t) {
        return t == c;
    }

private:
    T c;
};

int main_5() {
#ifdef _WIN32
    system("chcp 65001");
#endif

    string s;
    cout << "要处理的字符串：" << endl;
    cin >> s;
    cout << "要删除的字符：" << endl;
    char c;
    cin >> c;
    // 等价的写法：
    string::iterator new_end = remove_if(s.begin(), s.end(), [c](char t) { return t == c; });
    // string::iterator new_end = remove_if(s.begin(), s.end(), equal_to_char(c));
    // string::iterator new_end = remove_if(s.begin(), s.end(), equal_to(c));
    // string::iterator new_end = remove_if(s.begin(), s.end(), [c]<std::regular T>(T t) { return t == c; });
    // string::iterator new_end = remove_if(s.begin(), s.end(), [c](std::regular auto t) { return t == c; });
    s.erase(new_end, s.end());
    cout << s;
    system("pause");
    return 0;
}

// c++20
// 使用std::range std::view:
#include <ranges>
#include <string>

int main() {
#ifdef _WIN32
    system("chcp 65001");
#endif

    string s;
    cout << "要处理的字符串：" << endl;
    cin >> s;
    cout << "要删除的字符：" << endl;
    char c;
    cin >> c;
    auto filtered_s = s | std::views::filter([c](char t) { return t != c; });
    for (char ch : filtered_s) {
        cout << ch;
    }
    system("pause");
    return 0;
}