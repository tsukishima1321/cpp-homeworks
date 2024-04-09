// 实验六：二维数组、字符数组
/*输入一个小于10的正整数n，显示具有如下形式的n行杨辉三角形。图中n=6。

提示：解该题有两个关键：

① 形成满足杨辉三角形各项值的数组。首先定义二维数组a[10][10]，杨辉三角形的形成特点是第1列（下标为0）和主对角线均为1，其余各项有如下关系：

   a[i][j]= a[i-1][j-1]+ a[i-1][j]    i=2,3…,n-1    j=1,2…,i-1

②在输出每一行元素前，利用如下语句确定每行的起始位：

cout<<setw((n-i)*3)<<' ';    */
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
#ifdef _WIN32
    system("chcp 65001");
#endif

    int n;
    cin >> n;
    int a[10][10] = {};
    for (int i = 0; i < n; i++) {
        cout << setw((n - i) * 3) << ' ';
        for (int j = 0; j < i + 1; j++) {
            if (j == 0) {
                a[i][j] = 1;
            } else if (i == j) {
                a[i][j] = 1;
            } else {
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            }
            cout << a[i][j] <<"     ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}