// 实验2：顺序结构
// 输入直角坐标系中点P的坐标(x,y)，若P点落在图中的阴影区域内，输出阴影部分面积，否则输出数据0。

#include <cmath>
#include <iostream>
#define PI 3.14159

using namespace std;

int main() {
    double x, y;
    cout << "请输入坐标：" << endl;
    cin >> x >> y;
    double distance = sqrt(x * x + y * y);
    if (distance >= 2 && distance <= 4) {
        cout << PI * 4 * 4 - PI * 2 * 2 << endl;
    } else {
        cout << 0 << endl;
    }
    system("pause");
    return 0;
}