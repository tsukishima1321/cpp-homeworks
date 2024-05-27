/*编写程序，将一存放一行字符串的文本文件中的每一个字符及其所对应的ASCII码输出到屏幕上。例如文件的内容是“I love China”，则输出：
I(73) (32)l(108)o(111)v(118)e(101) (32)C(67)h(104)i(105)n(110)a(97)
注意：空格也是有效字符。
‌*/
#include <iostream>
#include <fstream>

int main() {
    std::ifstream ifs("f3.txt");
    if (!ifs) {
        std::cerr << "Open file failed." << std::endl;
        return 1;
    }
    char ch;
    while (ifs.get(ch)) {
        std::cout << ch << "(" << static_cast<int>(ch) << ")";
    }
    ifs.close();
    system("pause");
    return 0;
}