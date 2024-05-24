#include "StaffList.h"
#include <iostream>

int main() {
    StaffList staffList;
    Staff staff;
    int n;
    std::cout << "Please input the number of staffs: ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        staffList.insert(Staff::FromStream());
    }
    std::cout << "Please input the number of staff to delete: ";
    std::cin >> n;
    staff = staffList.deln(n);
    std::cout << "The staff deleted is: ";
    staff.print();
    std::cout << "Please input the number of staff to modify: ";
    char num[6];
    std::cin >> num;
    double wage;
    std::cout << "Please input the new wage: ";
    std::cin >> wage;
    staffList.modify(num, wage);
    staffList.findByNum(num).print();

    system("pause");
    return 0;
}