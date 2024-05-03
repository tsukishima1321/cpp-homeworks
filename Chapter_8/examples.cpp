// Some examples for learning basic function in C++
//
#include <iostream>

// 函数的声明和定义同时进行
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// 函数的声明和定义分开进行
int min(int a, int b);

void printMax(int a, int b) {
    // 函数中可以使用全局对象：std::cout
    std::cout << "The max number is: " << max(a, b) << std::endl;
}

// 以指针作为参数的函数
void swap_int_pointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 以引用作为参数的函数
void swap_int_ref(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// 通过传递指针或引用，实现函数“返回”多个结果
void devide_ref(int a, int b, int &quotient, int &remainder) {
    quotient = a / b;
    remainder = a % b;
}

void devide_pointer(int a, int b, int *quotient, int *remainder) {
    *quotient = a / b;
    *remainder = a % b;
}

// 用const修饰指针或引用参数
//  1. 传递指针参数时，如果不希望函数修改指针所指向的内容，可以使用const修饰指针参数
//  2. 传递引用参数时，如果不希望函数修改引用所引用的内容，可以使用const修饰引用参数
void print_array(const int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// 返回指针的函数
// 从数组中查找指定的值，如果找到返回指向该值的指针，否则返回指向数组尾部的指针
int *find(int *begin, int *end, int value) {
    while (begin != end) {
        if (*begin == value) {
            return begin;
        }
        ++begin;
    }
    return end;
}

// 在函数中动态分配内存并返回指针
int *create_array(int size) {
    return new int[size];
}
int *new_int() {
    return new int(0);
}

// 返回引用的函数
int &get(int *arr, int index) {
    return arr[index];
}

// 在函数中使用static修饰局部变量
// static修饰局部变量，使得局部变量在函数调用结束后不会被销毁，而是保留其值
// static修饰的局部变量，其初始化会在第一次调用时进行
int count_calls() {
    static int count = 0;
    return ++count;
}

int main() {
    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a = 10;
    int b = 20;
    printMax(a, b);

    // 函数的声明必须在调用之前，函数的定义可以在调用之后
    // 无论函数的定义是否可见，只要函数经过声明，对函数的调用就是合法的
    std::cout << "The min number is: " << min(a, b) << std::endl;

    // 以指针作为参数的函数
    swap_int_pointer(&a, &b);
    std::cout << "After swap_int_pointer: a = " << a << ", b = " << b << std::endl;

    // 以引用作为参数的函数
    swap_int_ref(a, b);
    std::cout << "After swap_int_ref: a = " << a << ", b = " << b << std::endl;

    // 通过传递指针或引用，实现函数“返回”多个结果
    int quotient, remainder;
    devide_ref(a, b, quotient, remainder);
    std::cout << "Quotient: " << quotient << ", Remainder: " << remainder << std::endl;

    // 用const修饰指针或引用参数
    print_array(data, 10);

    // 返回指针的函数
    int *p = find(data, data + 10, 5);
    if (p != data + 10) {
        std::cout << "Found value: " << *p << " at index: " << p - data << std::endl;
    } else {
        std::cout << "Not found!" << std::endl;
    }

    // 在函数中动态分配内存并返回指针
    int *arr = create_array(10);
    for (int i = 0; i < 10; ++i) {
        arr[i] = i;
    }
    print_array(arr, 10);
    // 释放动态分配的内存
    delete[] arr;

    int *p_int = new_int();
    std::cout << "The value of p_int is: " << *p_int << std::endl;
    delete p_int;

    // 返回引用的函数
    int value = get(data, 5);
    std::cout << "The value is: " << value << std::endl;
    // 修改value并不会修改数组中的值，因为value是int类型的变量，而不是数组元素的引用
    value = 50;
    // 通过引用修改数组中的值
    int &ref = get(data, 5);
    ref = 100;
    std::cout << "After modify, the values is: " << std::endl;
    print_array(data, 10);

    // 在函数中使用static修饰局部变量
    for (int i = 0; i < 10; ++i) {
        std::cout << count_calls() << " ";
    }

    system("pause");
    return 0;
}

int min(int a, int b) {
    return a < b ? a : b;
}