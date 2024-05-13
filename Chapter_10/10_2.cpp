// 实验十：结构
// 编写程序，定义一个日期结构变量，计算某日期是本年度的第几天。提示：为简单起见，可定义一个存放12个月中每个月总天数的数组。

#include <stdio.h>
#include <stdlib.h>

typedef struct date {
    int year;
    int month;
    int day;
} date_t;

int g_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int day_of_year(date_t date) {
    int result = 0;
    for (int i = 0; i < date.month - 1; i++) {
        result += g_days[i];
    }
    result += date.day;
    return result;
}

int main() {
    date_t date = {2024, 5, 10};
    printf("The date is the %dth day of the year.\n", day_of_year(date));
    system("pause"); 
    return 0;
}