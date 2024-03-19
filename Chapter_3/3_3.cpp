// 实验三：选择结构
// 三个数排序输出
#include <iostream>

using namespace std;

void swap(int &x, int &y)
{
    int t = x;
    x = y;
    y = t;
}

// 法一：
int main_()
{
    int a, b, c;
    cout << "请输入三个数" << endl;
    cin >> a >> b >> c;
    if (a > b)
        swap(a, b);
    if (b > c)
        swap(b, c);
    if (a > b)
        swap(a, b);
    cout << a << "≤" << b << "≤" << c << endl;
    system("pause");
    return 0;
}

// 法二：
int main_2()
{
    int a, b, c;
    cout << "请输入三个数" << endl;
    cin >> a >> b >> c;
    while (a > b || b > c)
    {
        if (a > b)
        {
            swap(a, b);
        }
        swap(b, c);
    }
    cout << a << "≤" << b << "≤" << c << endl;
    system("pause");
    return 0;
}

//法三：
#include <algorithm>
int main(){
    int a[3];
    cout << "请输入三个数" << endl;
    cin >> a[0] >> a[1] >> a[2];
    sort(a,a+3);
    cout << a[0] << "≤" << a[1] << "≤" << a[2] << endl;
    system("pause");
    return 0;
}

//某愚蠢的法四：
#include <iostream>

int main_4()
{
    using std::cin, std::cout, std::endl;
    double x, y, z, smallest, medium, largest, exchange;
    cout << "请输入x，y，z的值：" << endl;
    cin >> x >> y >> z;
    if (x >= y)
    {
        largest = x;
        medium = y;
        if (z >= x)
        {
            smallest = medium;
            medium = largest;
            largest = z;
        }
        else if (y <= z && z < x)
        {
            smallest = medium;
            medium = z;
        }
        else
        {
            smallest = z;
        }
    }
    else
    {
        largest = y;
        medium = x;
        if (z >= y)
        {
            smallest = medium;
            medium = largest;
            largest = z;
        }
        else if (x <= z && z < y)
        {
            smallest = medium;
            medium = z;
        }
        else
        {
            smallest = z;
        }
    }
    cout << smallest << "<=" << medium << "<=" << largest << endl;
    return 0;
}