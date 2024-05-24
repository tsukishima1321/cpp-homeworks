#pragma once

#include <iostream>

class Staff {
public:
    char num[6];
    char name[10];
    double wage;
    Staff();
    static Staff FromStream(std::istream &is = std::cin, std::ostream &os = std::cout);
    void print(std::ostream &os = std::cout) const;
};

class StaffList {
public:
    class Node {
    public:
        Staff data;
        Node *next;
        Node();
        Node(const Staff &staff, Node *next = nullptr);
    };
    Node *head;
    StaffList();
    ~StaffList();
    void insert(const Staff &staff);
    void insert(Staff &&staff);
    Staff deln(int n);
    Staff &findByNum(const char *num);
    void modify(const char *num, double wage);
};