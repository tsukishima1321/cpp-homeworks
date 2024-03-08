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

//法二：使用函数
void Encode(char *source, int length)
{
    for (int i = 0; i < length; i++)
    {
        char &c = source[i];
        if (c >= 'x' && c <= 'z')
        {
            c -= 23;
        }
        else
        {
            c += 3;
        }
    }
}

int main_2()
{
    char s[4] = "fly";
    Encode(s, 3);
    cout << s;
    return 0;
}