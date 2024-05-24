#pragma once

class Staff {
public:
    char num[6];
    char name[10];
    double wage;
};

class StaffList {
public:
    struct Node {
        Staff data;
        Node *next;
    };
    Node *head;
    StaffList();
    ~StaffList();
    void insert(const Staff &staff);
    Staff deln(int n);
    void modify(const char *num, double wage);
};