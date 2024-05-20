// 链表
// 编写函数deln，具有删除链表中第n个结点的功能。
// 再编写主函数，按输入顺序建立不带头结点的职工信息单链表，
// 然后调用del函数删除某个职工的信息，并输出删除后的职工信息表中的职工信息。假设链表结构如下：

// 在上一题目建立的链表中增加一个按工号num修改该职工工资wage的函数。再编写主函数，对某一具体职工的信息进行更改。
#include <iostream>
#include <cstring>

typedef struct {
    char num[6];
    char name[10];
    double wage;
} staff_t;

typedef struct node {
    staff_t data;
    struct node *next;
} node_t;

staff_t deln(node_t *head, int n) {
    staff_t temp;
    node_t *p = head;
    for (int i = 0; i < n - 1; i++) {
        p = p->next;
    }
    temp = p->next->data;
    p->next = p->next->next;
    return temp;
}

void modify(node_t *head, const char *num, double wage) {
    node_t *p = head;
    while (p != nullptr) {
        if (strcmp(p->data.num, num) == 0) {
            p->data.wage = wage;
            break;
        }
        p = p->next;
    }
}

int main() {
    node_t *head, *p, *q;
    int n;
    std::cout << "Please input the number of staff: ";
    std::cin >> n;
    head = new node_t;
    head->next = nullptr;
    p = head;
    for (int i = 0; i < n; i++) {
        q = new node_t;
        std::cout << "Please input the number of staff: ";
        std::cin >> q->data.num;
        std::cout << "Please input the name of staff: ";
        std::cin >> q->data.name;
        std::cout << "Please input the wage of staff: ";
        std::cin >> q->data.wage;
        q->next = nullptr;
        p->next = q;
        p = p->next;
    }
    int m;
    std::cout << "Please input the number of staff you want to delete: ";
    std::cin >> m;
    staff_t temp = deln(head, m);
    std::cout << "The staff you delete is: " << temp.num << " " << temp.name << " " << temp.wage << std::endl;

    char num[6];
    double wage;
    std::cout << "Please input the number of staff you want to modify: ";
    std::cin >> num;
    std::cout << "Please input the wage of staff: ";
    std::cin >> wage;
    modify(head, num, wage);
    

    system("pause");
    return 0;
}