// 实验十：结构
// 使用结构数组输入10本书的名称和单价，调用函数按照书名的字母顺序序进行排序，在主函数输出排序结果。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book {
    char name[100];
    double price;
} book_t;

void sort(book_t *book_list, size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (strcmp(book_list[i].name, book_list[j].name) > 0) {
                book_t temp = book_list[i];
                book_list[i] = book_list[j];
                book_list[j] = temp;
            }
        }
    }
}

int main() {
    book_t book_list[10];

    for(size_t i = 0; i < 10; i++) {
        scanf("%s %lf", book_list[i].name,&book_list[i].price);
    }

    sort(book_list, sizeof(book_list) / sizeof(book_t));

    for (size_t i = 0; i < sizeof(book_list) / sizeof(book_t); i++) {
        printf("Book name: %s, price: %.2f\n", book_list[i].name, book_list[i].price);
    }

    system("pause");
    return 0;
    
}