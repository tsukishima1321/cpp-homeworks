// 从键盘输入一个字符串，要求将该字符串的内容按输入的相反顺序组织到一个不带表头结点的单链表中
// 假设输入的字符串为"abcdefg"，则组织到链表中的内容为"gfedcba"

#include <cstring>
#include <iostream>

typedef struct node {
    char data;
    struct node *next;
} node_t;

int main() {
    node_t *head, *p, *q;
    char str[100];
    std::cout << "Please input a string: ";
    std::cin >> str;
    head = nullptr;
    for (int i = 0; i < strlen(str); i++) {
        p = new node_t;
        p->data = str[i];
        p->next = head;
        head = p;
    }
    p = head;
    while (p != nullptr) {
        std::cout << p->data;
        p = p->next;
    }
    system("pause");
    return 0;
}