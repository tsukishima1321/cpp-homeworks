/*用记事本建立一个文本文件f2.txt，在该文件中任意存放一组整数。编写程序统计该文件中正整数、负整数和零的个数。（提示：用fscanf函数读取文件中的数据）*/
#include <cstdio>
#include <cstdlib>

int main() {
    FILE *fp = fopen("f2.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Open file failed.\n");
        return 1;
    }
    int num, positive = 0, negative = 0, zero = 0;
    while (fscanf(fp, "%d", &num) != EOF) {
        if (num > 0) {
            positive++;
        } else if (num < 0) {
            negative++;
        } else {
            zero++;
        }
    }
    printf("Positive: %d\nNegative: %d\nZero: %d\n", positive, negative, zero);
    fclose(fp);
    system("pause");
    return 0;
}