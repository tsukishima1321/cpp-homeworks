/*将从键盘输入的N个学生的学号和成绩存入到文件student.dat中。再从文件中读取学生的信息，求出最高分、最低分和总分。N可通过符号常量自行定义大小。*/
#include <fstream>
#include <iostream>

constexpr int N = 3;
struct Student {
    int id;
    double score;
};

int main() {
    Student students[N];
    for (int i = 0; i < N; ++i) {
        std::cout << "Please input student id and score: ";
        std::cin >> students[i].id >> students[i].score;
    }
    std::ofstream ofs("student.dat", std::ios::binary);
    if (!ofs) {
        std::cerr << "Open file failed." << std::endl;
        return 1;
    }
    for (int i = 0; i < N; ++i) {
        ofs.write(reinterpret_cast<char *>(&students[i]), sizeof(Student));
    }
    ofs.close();
    std::ifstream ifs("student.dat", std::ios::binary);
    if (!ifs) {
        std::cerr << "Open file failed." << std::endl;
        return 1;
    }
    double max = 0, min = 100, sum = 0;
    for (int i = 0; i < N; ++i) {
        ifs.read(reinterpret_cast<char *>(&students[i]), sizeof(Student));
        if (students[i].score > max) {
            max = students[i].score;
        }
        if (students[i].score < min) {
            min = students[i].score;
        }
        sum += students[i].score;
    }
    ifs.close();
    std::cout << "Max: " << max << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    system("pause");
    return 0;
}