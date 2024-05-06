// 实验九：函数（续）
// 编写递归函数int  sum(int a[],int n)，其功能是求长度为n的数组的累加和，在主函数中随机产生10个两位数，调用sum函数，求这10个数的和。

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int sum(int a[],int n) {
    if(n == 1){
        return a[0];
    }
    return a[0] + sum(a + 1,n - 1);
}

int main() {
    srand((unsigned)time(0));
    int a[10];
    for(int i = 0;i < 10;i++){
        a[i] = 10 + rand() % 90;
        cout << a[i] << endl;
    }
    cout<< sum(a,10) << endl;
    system("pause");
    return 0;
}