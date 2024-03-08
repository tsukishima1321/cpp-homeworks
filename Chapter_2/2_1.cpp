// 实验2：顺序结构
// 输入直角坐标系中点P的坐标(x,y)，若P点落在图中的阴影区域内，输出阴影部分面积，否则输出数据0。

#include <iostream>
#include <cmath>
#define PI 3.14159

using namespace std;

int main()
{
	double x, y;
	cout << "请输入坐标：" << endl;
	cin >> x >> y;
	double distance = sqrt(x * x + y * y);
	if (distance >= 2 && distance <= 4)
	{
		cout << PI * 4 * 4 - PI * 2 * 2 << endl;
	}
	else
	{
		cout << 0 << endl;
	}
	system("pause");
	return 0;
}

//法二

#define pi 3.1415926535897932384626433
int main_2()
{
  double x, y, area;
  area = pi * 4 * 4 - pi * 2 * 2;
  std::cout << "请输入x和y的值:"
            << "\n";
  std::cin >> x >> y;
  area = ((-2 >= -sqrt(y * y + x * x) && -4 <= -sqrt(y * y + x * x) ||
           4 >= sqrt(y * y + x * x) && 2 <= sqrt(y * y + x * x))) *
         area;
  std::cout << "阴影部分面积是：" << area << std::endl;
  return 0;
}