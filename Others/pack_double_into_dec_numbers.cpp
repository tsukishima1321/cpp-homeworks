//
//
#include <iostream>

using namespace std;

int main()
{
#ifdef _WIN32
    system("chcp 65001");
#endif
    double a;
    // cin>>a;
    a = 9826599999.78;
    cout << (int)(a / 1e+09) % 10 << endl;
    cout << (int)(a / 1e+08) % 10 << endl;
    cout << (int)(a / 1e+07) % 10 << endl;
    cout << (int)(a / 1e+06) % 10 << endl;
    cout << (int)(a / 1e+05) % 10 << endl;
    cout << (int)(a / 1e+04) % 10 << endl;
    cout << (int)(a / 1e+03) % 10 << endl;
    cout << (int)(a / 1e+02) % 10 << endl;
    cout << (int)(a / 10) % 10 << endl;
    cout << (int)(a - ((int)(a / 10) / (int)(1e+08)) * (1e+09)) % 10 << endl;

    double a_ = a - ((int)(a / 10) / (int)(1e+08)) * (1e+09);
    double b = a_ - (int)(a_);
    cout << (int)(b * 100 + 0.5) / 10 << endl;
    cout << (int)(b * 100 + 0.5) % 10 << endl;
    system("pause");
    return 0;
}