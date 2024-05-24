#include "StaffList.h"
#include <cstring>

StaffList::StaffList() {
    head = new Node;
    head->next = nullptr;
}

StaffList::~StaffList() {
    Node *p = head, *q;
    while (p != nullptr) {
        q = p->next;
        delete p;
        p = q;
    }
}

void StaffList::insert(const Staff &staff) {
    Node *p = head;
    while (p->next != nullptr) {
        p = p->next;
    }
    Node *q = new Node;
    q->data = staff;
    q->next = nullptr;
    p->next = q;
}

Staff StaffList::deln(int n) {
    Staff temp;
    Node *p = head;
    for (int i = 0; i < n - 1; i++) {
        p = p->next;
    }
    temp = p->next->data;
    p->next = p->next->next;
    return temp;
}

void StaffList::modify(const char *num, double wage) {
    Node *p = head;
    while (p != nullptr) {
        if (strcmp(p->data.num, num) == 0) {
            p->data.wage = wage;
            break;
        }
        p = p->next;
    }
}