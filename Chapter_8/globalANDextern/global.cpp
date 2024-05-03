#include <iostream>

// 声明一个全局变量，全局变量对之后该文件中的所有函数都可见
// 全局变量可以在声明的同时初始化，如果没有初始化，全局变量会被默认初始化为0
int global_var = 10;

void f() {
    // 函数可以使用已经声明和初始化的全局变量
    std::cout << global_var << std::endl;
    int global_var = 20;
    // 函数中声明同名的局部变量会覆盖全局变量
    std::cout << global_var << std::endl;
    // 如果想在函数中明确表示使用全局变量而不是同名的局部变量，可以使用::作用域解析符
    std::cout << ::global_var << std::endl;
}

int main() {
    f();
    std::cout << global_var << std::endl;
    system("pause");
    return 0;
}