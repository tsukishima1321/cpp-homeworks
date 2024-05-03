// examples for cstring
//

#include <cstring>
#include <iostream>
// 使用c库函数时，如果#include<string.h>，则函数会引入到全局命名空间中，调用时不需要加std::前缀
// 如果#include<cstring>，则函数会同时引入到std命名空间和全局命名空间中，可以使用std::也可以直接调用
// 如果你（在全局命名空间中）定义了和cstring中相同名字的函数，那么不加std::前缀的话，会调用你定义的函数，加上std::前缀则会调用cstring中的函数
// 其他继承自C的C++标准库头文件也同理，如cstdio、cstdlib等

int main() {

    char str1[] = "Hello";
    // str1的类型为char[6]，值是{'H', 'e', 'l', 'l', 'o', '\0'}

    char str2[6] = {'W', 'o', 'r', 'l', 'd', '\0'};

    char *str3 = "abc";
    // 与str1的初始化不同，这里是把指向常量字符串abc的指针赋值给str3
    // 尽管str3的类型是char*，但是它指向的是一个常量字符串，不能修改
    // str3[0] = 'd'; // error

    // 应当使用下面的方式初始化，这样str3指向的是一个可修改的字符串
    // char* str3 = new char[4]; // 为str3分配大小可容纳4个字符的内存空间
    // strcpy(str3, "abc"); // 将"abc"的值复制到str3所指向的空间

    // 输入cstring的方法
    char str5[100];
    std::cin >> str5; // 以空格为分隔符，输入字符串
    std::cout << str5 << std::endl;
    // 输入包含空格的字符串
    getchar();                   // 上一次输入的回车仍然在输入缓冲区中，需要清除
    std::cin.getline(str5, 100); // 以回车为分隔符，输入字符串相当于gets(str5);
    std::cout << str5 << std::endl;
    // 自定义分隔符
    std::cin.getline(str5, 100, ','); // 以逗号为分隔符，输入字符串
    std::cout << str5 << std::endl;

    // 所有cstring函数都以\0作为字符串的结束标志，而不是数组的长度(还有cout等输入输出函数)
    // 使用双引号初始化字符串或使用标准输入输入字符串时，\0会自动添加到字符串的末尾
    // 使用一般数组方式构造字符串时，需要手动添加\0，来使cstring函数和输入输出函数正常工作

    // strlen()返回字符串的长度，不包括\0
    std::cout << strlen(str1) << std::endl; // 5

    // strcpy()将字符串复制到另一个字符串
    char str4[10] = {};
    strcpy(str4, str1);
    std::cout << str4 << std::endl; // Hello
    // str4的值是{'H', 'e', 'l', 'l', 'o', '\0', '\0', '\0', '\0', '\0'}
    strcpy(str2, str3);
    std::cout << str2 << std::endl; // abc
    // str2的值是{'a', 'b', 'c', '\0', 'd', '\0'}
    strlen(str2); // 3

    // strcat()将字符串连接到另一个字符串
    strcat(str4, str2);
    std::cout << str4 << std::endl; // Helloabc
    // str4的值是{'H', 'e', 'l', 'l', 'o', 'a', 'b', 'c', '\0', '\0'}

    // strcmp()比较两个字符串
    std::cout << strcmp(str1, str2) << std::endl; // 1
    std::cout << strcmp(str1, str4) << std::endl; // -1
    std::cout << strcmp(str1, str1) << std::endl; // 0

    system("pause");
    return 0;
}