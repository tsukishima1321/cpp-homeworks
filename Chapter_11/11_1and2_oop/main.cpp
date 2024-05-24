#include <iostream>
#include "StaffList.h"

int main(){
    StaffList staffList;
    Staff staff;
    int n;
    std::cout << "Please input the number of staff: ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cout << "Please input the number of staff: ";
        std::cin >> staff.num;
        std::cout << "Please input the name of staff: ";
        std::cin >> staff.name;
        std::cout << "Please input the wage of staff: ";
        std::cin >> staff.wage;
        staffList.insert(staff);
    }
    std::cout << "Please input the number of staff to delete: ";
    std::cin >> n;
    staff = staffList.deln(n);
    std::cout << "The staff deleted is: " << staff.num << " " << staff.name << " " << staff.wage << std::endl;
    std::cout << "Please input the number of staff to modify: ";
    std::cin >> n;
    double wage;
    std::cout << "Please input the new wage: ";
    std::cin >> wage;
    staffList.modify(staff.num, wage);
    
    system("pause");
    return 0;
}