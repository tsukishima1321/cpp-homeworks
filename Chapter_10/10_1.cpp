// 实验十：结构
// 有一组关于学生成绩的信息，编写函数max，该函数返回值为分数最高的学生的信息（包括学号和分数）。
// 再编写主函数对其进行调用并输出最高分者的信息。假设结构类型定义为：
/*struct student
{
  char  *num;
  int   score;
};
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char *num;
    int score;
} student_t;

student_t max(student_t *student_list, size_t n) {
    int max_i = 0;
    for (size_t i = 0; i < n; i++) {
        if (student_list[i].score > student_list[max_i].score) {
            max_i = i;
        }
    }
    return student_list[max_i];
}

int main() {
    student_t student_list[] = {
        {(char *)malloc(100), 90},
        {(char *)malloc(100), 80},
        {(char *)malloc(100), 70},
        {(char *)malloc(100), 60},
        {(char *)malloc(100), 50},
    };
    strcpy(student_list[0].num, "001");
    strcpy(student_list[1].num, "002");
    strcpy(student_list[2].num, "003");
    strcpy(student_list[3].num, "004");
    strcpy(student_list[4].num, "005");

    student_t max_student = max(student_list, sizeof(student_list) / sizeof(student_t));
    printf("The student with the highest score is %s, with a score of %d.\n", max_student.num, max_student.score);
    system("pause");
}