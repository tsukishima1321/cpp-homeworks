// 实验三：选择结构
// 简易计算器
#include <iostream>

using namespace std;

int main() {
    double x, y;
    char op;
    cout << "请输入操作数1 操作符op 操作数2" << endl;
    cin >> x >> op >> y;
    double res;
    switch (op) {
    case '+':
        res = x + y;
        break;
    case '-':
        res = x - y;
        break;
    case '*':
        res = x * y;
        break;
    case '/':
        res = x / y;
        break;
    default:
        cout << "请输入有效的操作符" << endl;
        system("pause");
        return 0;
    }
    cout << x << op << y << "=" << res << endl;
    system("pause");
    return 0;
}