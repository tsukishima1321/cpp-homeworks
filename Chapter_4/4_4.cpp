// 实验四：循环结构
// 求S_n=a+aa+aaa+aaaa+……+aaaaa(n个a)

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int getRand(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

int main()
{
    srand(time(0));
    int a = getRand(1, 9);
    int n = getRand(5, 9);
    cout << "随机到的a为：" << a << " 随机到的n为：" << n << endl;
    int t = a;
    int sum = a;
    for (int i = 1; i < n; i++)
    {
        t = t * 10 + a;
        sum += t;
    }
    cout << sum << endl;
    system("pause");
    return 0;
}