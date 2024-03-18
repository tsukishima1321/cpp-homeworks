// 实验2：顺序结构
// 将"fly"译成密码"iob"。编码规律：将字母a变成字母d，即变成其后的第3个字母，x变成a，y变成b, z变成c。

#include <iostream>
using namespace std;

// 法一：
int main()
{
    char s[4] = "fly";
    for (int i = 0; i < 3; i++)
    {
        if (s[i] >= 'x' && s[i] <= 'z')
        {
            s[i] -= 23;
        }
        else
        {
            s[i] += 3;
        }
    }
    cout << s << endl;
    system("pause");
    return 0;
}

// 法二：使用函数
void Encode(char *source)
{
    for (int i = 0; source[++i] != '\0';)
    {
        char &c = source[i];
        if (c >= 'a' && c <= 'z')
        {
            c = (c - 'a' + 3) % 26 + 'a';
        }
    }
}

int main_2()
{
    char s[4] = "fly";
    Encode(s);
    cout << s;
    system("pause");
    return 0;
}

// 法3：
#include <string>

int main_3()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::getline;
    using std::string;

    string plain_text, cipher_text;
    char offset;
    cout << "请输入明文：";
    getline(cin, plain_text);
    for (char c : plain_text)
    {
        if (c >= 'a' && c <= 'z')
        {
            offset = (c - 'a' + 3) % 26 + 'a';
            cipher_text += offset;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            offset = (c - 'A' + 3) % 26 + 'A';
            cipher_text += offset;
        }
        else
        {
            cipher_text += c;
        }
    }
    cout << "加密后的文字是：" << cipher_text << endl;
    return 0;
}