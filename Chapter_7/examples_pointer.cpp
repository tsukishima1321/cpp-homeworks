// examples for explaining relationship between pointer and array in C++
//
#include <iostream>

// 用传指针的方式让函数处理数组
// 传递首指针和数组的大小
void print_array_1(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
// 传递首指针和尾指针
void print_array_2(int *begin, int *end) {
    while (begin != end) {
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << std::endl;
}
//由于本质是传递指针，所以函数中修改数组的值会影响原数组

int main() {

    int a[5] = {1, 2, 3, 4, 5};

    // p points to the first element of a
    // 相当于p = &a[0]
    int *p = a;

    // 因为数组中的元素在内存中是连续存储的，所以p + 1指向的就是a[1]
    // p + 1 == &a[1]
    // p[i] == *(p + i) == *(a + i) == a[i] == i[a] == i[p]
    // 在这样的运算中，数组名a会隐式转换为指向数组首元素的指针
    std::cout << *p << std::endl;       // 1
    std::cout << *(p + 1) << std::endl; // 2
    std::cout << p[2] << std::endl;     // 3
    std::cout << 2 [p] << std::endl;    // 3
    std::cout << p[3] << std::endl;     // 4
    std::cout << 3 [p] << std::endl;    // 4
    std::cout << p[4] << std::endl;     // 5
    std::cout << 4 [p] << std::endl;    // 5

    //在循环中使用指针对数组进行操作
    //reverse array
    for (int *i = a, *j = a + 4; i < j; i++, j--) {
        int t = *i;
        *i = *j;
        *j = t;
    }

    // 传递数组名作为参数
    // 数组名会隐式转换为指向数组首元素的指针
    print_array_1(a, 5);
    print_array_2(a, a + 5);

    system("pause");
    return 0;
}