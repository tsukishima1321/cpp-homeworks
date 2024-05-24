#include "StaffList.h"
#include <cstring>

Staff::Staff() {
    num[0] = '\0';
    name[0] = '\0';
    wage = 0;
}

Staff Staff::FromStream(std::istream &is, std::ostream &os) {
    Staff staff;
    os << "Please input the number of staff: ";
    is >> staff.num;
    os << "Please input the name of staff: ";
    is >> staff.name;
    os << "Please input the wage of staff: ";
    is >> staff.wage;
    return staff;
}

void Staff::print(std::ostream &os) const {
    os << num << " " << name << " " << wage << std::endl;
}

StaffList::Node::Node() : next(nullptr) {}

StaffList::Node::Node(const Staff &staff, Node *next) : data(staff), next(next) {}

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
    Node *q = new Node(staff);
    p->next = q;
}

void StaffList::insert(Staff &&staff) {
    Node *p = head;
    while (p->next != nullptr) {
        p = p->next;
    }
    Node *q = new Node(staff);
    p->next = q;
}

Staff StaffList::deln(int n) {
    Staff temp;
    Node *p = head;
    for (int i = 0; i < n - 1; i++) {
        p = p->next;
    }
    temp = p->next->data;
    Node *tempNode = p->next;
    p->next = p->next->next;
    if (tempNode == head) {
        head = head->next;
    }
    if (tempNode != nullptr) {
        delete tempNode;
    }
    return temp;
}

Staff &StaffList::findByNum(const char *num) {
    Node *p = head;
    while (p != nullptr) {
        if (strcmp(p->data.num, num) == 0) {
            return p->data;
        }
        p = p->next;
    }
    return head->data;
}

void StaffList::modify(const char *num, double wage) {
    findByNum(num).wage = wage;
}