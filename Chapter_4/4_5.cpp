// 实验四：循环结构
// 求S=1+1/2+1/4+1/7+1/11+1/16+1/22+1/29…………
// 第i项的分母为前一项的分母加上i
// 计算到该项小于10^-4

#include <iostream>

using namespace std;

int main() {
    double sum = 0;
    int last = 1;
    for (int i = 0;; i++) {
        sum += 1.0 / (last + i);
        if (1.0 / (last + i) < 0.0001) {
            break;
        }
        last += i;
    }
    cout << sum << endl;
    system("pause");
    return 0;
}