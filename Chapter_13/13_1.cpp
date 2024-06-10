// 设计一个点类(Point)，具有数据成员x,y（点的坐标），以及设置、输出数据成员及求两点之间距离的功能。再编写主函数对该类进行测试。
//
#include <cmath>
#include <iostream>

class Point {
public:
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
    void setPoint(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void printPoint() {
        std::cout << "Point(" << x << ", " << y << ")" << std::endl;
    }
    double distance(const Point &p) {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }

private:
    int x, y;
};

int main() {
    Point p1, p2(3, 4);
    p1.setPoint(1, 2);
    p1.printPoint();
    p2.printPoint();
    std::cout << "Distance between p1 and p2: " << p1.distance(p2) << std::endl;
    system("pause");
    return 0;
}