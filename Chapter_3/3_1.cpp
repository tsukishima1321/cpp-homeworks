// 实验三：选择结构
// 购物折扣
#include <iostream>

using namespace std;

int main()
{
    int x;
    float y = 0;
    cin >> x;
    if (x > 0)
    {
        switch (x / 1000)
        {
        case 0:
            y = x;
            break;
        case 1:
            y = 0.9 * x;
            break;
        case 2:
            y = 0.8 * x;
            break;
        default:
            y = 0.7 * x;
        }
    }
    cout << y << endl;
    return 0;
}