// 实验八：函数
// 编一判断m是否为素数的函数，并在主函数中利用它输出十对最小的孪生素数。所谓孪生素数是指两个相差为2的素数，如3和5，11和13。程序运行结果见下图。
#include <cmath>
#include <iostream>

using namespace std;

bool isprime(int m) {
    if (m == 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(m); ++i) {
        if (m % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int i = 1;
    int count = 0;
    while (1) {
        if (isprime(i) && isprime(i + 2)) {
            printf("(%d, %d)\n", i, i + 2);
            count++;
        }
        i++;
        if (count == 10) {
            break;
        }
    }
    system("pause");
    return 0;
}