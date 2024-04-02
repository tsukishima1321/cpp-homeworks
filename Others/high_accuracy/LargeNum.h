#include <iostream>
#include <string>

#define MAX_N 2000

class LargeNum {
public:
    enum Error {
        NO_ERR,
        OVERFLOW
    };

    LargeNum();
    LargeNum(unsigned long long a);
    LargeNum(const int a[MAX_N]);
    LargeNum(const LargeNum &from);
    LargeNum(LargeNum &&from);
    explicit LargeNum(Error e);
    ~LargeNum();

    LargeNum &operator=(const LargeNum &from);
    LargeNum &operator=(LargeNum &&from);

    void FromStream(std::istream &in);
    friend std::istream &operator>>(std::istream &in, LargeNum &a);

    std::string toString() const;
    friend std::ostream &operator<<(std::ostream &out, const LargeNum &a);

    friend LargeNum operator+(const LargeNum &a, const LargeNum &b);
    friend LargeNum operator*(const LargeNum &a, const LargeNum &b);
    friend LargeNum operator/(const LargeNum &a, int b);
    friend unsigned int operator%(const LargeNum &a, int b);

    static long long pow10(int a);

    Error error;

private:
    int *_data;
};