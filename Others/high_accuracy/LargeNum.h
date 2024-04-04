#include <iostream>
#include <string>

#define MAX_N 2000

class LargeNum {
public:
    enum Error {
        NO_ERR,
        OVERFLOW,
        UNKNOWN,
    };

    LargeNum();
    LargeNum(long long a);
    LargeNum(const int a[MAX_N]);
    LargeNum(const int a[MAX_N], bool sg);
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

    LargeNum operator-() const;
    friend LargeNum operator+(const LargeNum &a, const LargeNum &b);
    friend LargeNum operator-(const LargeNum &a, const LargeNum &b);
    friend LargeNum operator*(const LargeNum &a, const LargeNum &b);
    friend LargeNum operator/(const LargeNum &a, int b);
    friend int operator%(const LargeNum &a, int b);

    LargeNum operator+=(const LargeNum &a);
    LargeNum operator-=(const LargeNum &a);
    LargeNum operator*=(const LargeNum &a);
    LargeNum operator/=(int a);
    LargeNum operator%=(int a);

    friend bool operator==(const LargeNum &a, const LargeNum &b);
    friend bool operator!=(const LargeNum &a, const LargeNum &b);
    friend bool operator>(const LargeNum &a, const LargeNum &b);
    friend bool operator<(const LargeNum &a, const LargeNum &b);
    friend bool operator>=(const LargeNum &a, const LargeNum &b);
    friend bool operator<=(const LargeNum &a, const LargeNum &b);

    static long long pow10(int a);

    Error error;

private:
    int *_data;
    bool sign;
    static LargeNum unsignPlus(const LargeNum &a,const LargeNum &b);
    static LargeNum unsignMinus(const LargeNum &a,const LargeNum &b);
    static bool unsignCmp(const LargeNum &a,const LargeNum &b);
};