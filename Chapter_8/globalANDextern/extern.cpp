#include <iostream>

void f() {
    // 声明一个int变量，extern关键字表示该变量的定义在当前不可见的地方
    // 这个例子中，全局变量global_var的定义在f函数之后，如果不使用extern关键字，f函数会报错，必须将f函数的定义放在全局变量的定义之后
    extern int global_var;
    // 与一般变量声明一样，extern声明也有作用域，这里extern声明在函数f内部，所以只在函数f内部有效
    std::cout << global_var << std::endl;
}

// 函数ff会报错，因为标识符global_var未声明(前面的extern声明已经超出作用域)
/*
void ff() {
    std::cout << global_var << std::endl;
}
*/

// 在全局作用域中为global_var作extern声明
extern int global_var;
// 接下来的函数中都可以使用global_var
void fff() {
    std::cout << global_var << std::endl;
}

int global_var = 10;

int main() {
    f();
    fff();
    system("pause");
    return 0;
}