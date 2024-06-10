// 链表
// 编写函数deln，具有删除链表中第n个结点的功能。
// 再编写主函数，按输入顺序建立不带头结点的职工信息单链表，
// 然后调用del函数删除某个职工的信息，并输出删除后的职工信息表中的职工信息。假设链表结构如下：

// 在上一题目建立的链表中增加一个按工号num修改该职工工资wage的函数。再编写主函数，对某一具体职工的信息进行更改。
#include <cstring>
#include <iostream>

typedef struct staff {
    char num[6];
    char name[10];
    double wage;
    struct staff *next;
} staff_t;


void deln(staff_t **head, int n) {
    // 删除第n个结点
    staff_t *p = *head, *q = nullptr;
    staff_t temp;
    if (n == 1) {
        *head = p->next;
        delete p;
        return;
    }
    for (int i = 1; i < n; i++) {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    delete p;
    return;
}

int main() {
    staff_t *head, *p, *q;
    int n;
    std::cout << "Please input the number of staff: ";
    std::cin >> n;
    head = new staff_t;
    head->next = nullptr;
    p = head;
    std::cout << "Please input the number of staff: ";
    std::cin >> p->num;
    std::cout << "Please input the name of staff: ";
    std::cin >> p->name;
    std::cout << "Please input the wage of staff: ";
    std::cin >> p->wage;
    for (int i = 0; i < n - 1; i++) {
        q = new staff_t;
        std::cout << "Please input the number of staff: ";
        std::cin >> q->num;
        std::cout << "Please input the name of staff: ";
        std::cin >> q->name;
        std::cout << "Please input the wage of staff: ";
        std::cin >> q->wage;
        q->next = nullptr;
        p->next = q;
        p = p->next;
    }
    int m;
    std::cout << "Please input the number of staff you want to delete: ";
    std::cin >> m;
    deln(&head, m);

    //print the list
    std::cout << "The staff list is: " << std::endl;
    p = head;
    while (p != nullptr) {
        std::cout << p->num << " " << p->name << " " << p->wage << std::endl;
        p = p->next;
    }

    system("pause");
    return 0;
}