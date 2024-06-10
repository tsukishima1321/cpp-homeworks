// 设计一个分数类Fraction。该类的数据成员包括分子fz和分母fm；类中还包括如下成员函数：
// ‍（1）构造函数，用于初始化分子和分母。
// ‍（2）成员函数print，将分数以 "fz/fm" 的形式输出。
// ‍（3）成员函数Reduction，用于对分数的分子和分母进行约分。
// ‍再编写主函数对该类进行测试。
//

#include <iostream>

class Fraction {
private:
    int fz;
    int fm;

public:
    Fraction(int fz = 0, int fm = 1) : fz(fz), fm(fm) {
        Resuction();
    };
    Fraction(int fz) : fz(fz), fm(1){};

    void print(std::ostream &os = std::cout) {
        os << fz << "/" << fm;
    }

    void Resuction() {
        int a = fz, b = fm;
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        fz /= a;
        fm /= a;
    }
    friend std::ostream &operator<<(std::ostream &os, Fraction &f) {
        f.print(os);
        return os;
    }

    friend std::ostream &operator<<(std::ostream &os, Fraction &&f) {
        f.print(os);
        return os;
    }

    friend Fraction operator+(const Fraction &f1, const Fraction &f2) {
        Fraction f;
        f.fz = f1.fz * f2.fm + f2.fz * f1.fm;
        f.fm = f1.fm * f2.fm;
        f.Resuction();
        return f;
    }

    Fraction operator-() const {
        Fraction f;
        f.fz = -fz;
        f.fm = fm;
        return f;
    }

    friend Fraction operator-(const Fraction &f1, const Fraction &f2) {
        return f1 + (-f2);
    }

    friend Fraction operator*(const Fraction &f1, const Fraction &f2) {
        Fraction f;
        f.fz = f1.fz * f2.fz;
        f.fm = f1.fm * f2.fm;
        f.Resuction();
        return f;
    }

    friend Fraction operator/(const Fraction &f1, const Fraction &f2) {
        Fraction f;
        f.fz = f1.fz * f2.fm;
        f.fm = f1.fm * f2.fz;
        f.Resuction();
        return f;
    }

    explicit operator bool() {
        return fz != 0;
    }

    friend bool operator==(const Fraction &a, const Fraction &b) {
        return a.fz == b.fz && a.fm == b.fm;
    }
    friend bool operator!=(const Fraction &a, const Fraction &b) {
        return !(a == b);
    }
    friend bool operator>(const Fraction &a, const Fraction &b) {
        return a.fz * b.fm > b.fz * a.fm;
    }
    friend bool operator<(const Fraction &a, const Fraction &b) {
        return a.fz * b.fm < b.fz * a.fm;
    }
    friend bool operator>=(const Fraction &a, const Fraction &b) {
        return a.fz * b.fm >= b.fz * a.fm;
    }
    friend bool operator<=(const Fraction &a, const Fraction &b) {
        return a.fz * b.fm <= b.fz * a.fm;
    }

    operator double() {
        return (double)fz / fm;
    }
};

int main() {
    Fraction f1(1, 2), f2(1, 3);
    std::cout << f1 << " + " << f2 << " = " << f1 + f2 << std::endl;
    std::cout << f1 << " - " << f2 << " = " << f1 - f2 << std::endl;
    std::cout << f1 << " * " << f2 << " = " << f1 * f2 << std::endl;
    std::cout << f1 << " / " << f2 << " = " << f1 / f2 << std::endl;
    std::cout << f1 << " > " << f2 << " = " << (f1 > f2) << std::endl;

    system("pause");
    return 0;
}