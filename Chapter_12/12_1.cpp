/*编写程序，从键盘输入一串字符，要求将该串字符的倒序串先写入到文件f1.txt中，然后再将原字符串的内容接到该文件的末尾。
例如，假设从键盘输入的字符串为“How do you do?”，则文件f1.txt的内容为：
?od uoy od woHHow do you do?
*/
#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ofstream ofs("f1.txt");
    if (!ofs) {
        std::cerr << "Open file failed." << std::endl;
        return 1;
    }
    std::string str;
    std::getline(std::cin, str);
    for (auto it = str.rbegin(); it != str.rend(); ++it) {
        ofs << *it;
    }
    ofs << str;
    ofs.close();
    system("pause");
    return 0;
}