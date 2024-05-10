#include <iostream>

class Base {
public:
    virtual void foo() const {
        std::cout << "Base::foo()" << std::endl;
    }
};

class Derived : public Base {
public:
    void foo() { // 由于函数签名不同，不是虚函数的覆盖，而是新的函数
        std::cout << "Derived::foo()" << std::endl;
    }
};

class Derived2 : public Base {
public:
    void foo() override { // error: 'void Derived2::foo()' marked 'override', but does not override
                          // 编译时会检查标记为override的函数是否真的覆盖了基类的虚函数
        std::cout << "Derived::foo()" << std::endl;
    }
};

class Derived3 : public Base {
public:
    void foo() const override {
        std::cout << "Derived::foo()" << std::endl;
    }
};

int main() {
    Derived *derivedPtr = new Derived();
    derivedPtr->foo(); // 调用Derived::foo()，实际上对基类的foo函数进行了命名遮蔽
    Base *basePtr = new Derived();
    basePtr->foo(); // 没有构成虚函数的覆盖，调用Base::foo()

    Base *basePtr2 = new Derived3();
    basePtr->foo(); // 构成虚函数的覆盖，调用Derived3::foo()

    delete basePtr;
    delete derivedPtr;
    delete basePtr2;

    system("pause");
    return 0;
}