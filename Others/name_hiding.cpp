#include <iostream>

class Base {
public:
    void display() {
        std::cout << "Base class display()" << std::endl;
    }
    void display(int a) {
        std::cout << "Base class display(int a)" << std::endl;
    }
};

class Derived : public Base {
public:
    void display() {
        std::cout << "Derived class display()" << std::endl;
    }
};

class Derived2 : public Base {
public:
    using Base::display;
    void display() {
        std::cout << "Derived2 class display()" << std::endl;
    }
};

int main() {
    Derived derived;
    derived.display();       // Calls the display() function in the Derived class
    derived.Base::display(); // Calls the display() function in the Base class
    //derived.display(1);      // error: no matching function for call to 'Derived::display(int)'

    std::cout << std::endl;

    Derived2 derived2;
    derived2.display();      // Calls the display() function in the Derived2 class
    derived2.Base::display(); // Calls the display() function in the Base class
    derived2.display(1);     // Calls the display(int a) function in the Base class

    system("pause");
    return 0;
}