#include <iostream>
// 如果使用VSCode，修改task.json的args中的"${file}"为"${fileDirname}/*.cpp"，以同时编译链接该文件夹下的所有.cpp文件

int main() {
    // 在main函数中作extern声明，表示变量global_var的定义在当前不可见的地方
    // 这个例子中global_var定义在同时编译的util.cpp中
    extern int global_var;
    std::cout << global_var << std::endl;
    system("pause");
    return 0;
}