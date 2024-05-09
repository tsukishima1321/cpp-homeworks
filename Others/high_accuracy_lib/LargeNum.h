#include <iostream>
#include <string>

#define MAX_N 2000

class LargeNum {
public:
    enum Error {
        NO_ERR,
        OVERFLOW,
        WAIT_WHAT,
    };

    LargeNum();
    LargeNum(long long a);
    LargeNum(const LargeNum &from);
    LargeNum(LargeNum &&from);
    explicit LargeNum(Error e);
    explicit LargeNum(const char a[MAX_N]);
    explicit LargeNum(const char a[MAX_N], bool sg);
    ~LargeNum();

    LargeNum &operator=(const LargeNum &from);
    LargeNum &operator=(LargeNum &&from);
    //friend LargeNum &operator=(LargeNum &&a, LargeNum &b) = delete;

    void FromStream(std::istream &in);
    static LargeNum fromString(std::string str);
    friend std::istream &operator>>(std::istream &in, LargeNum &a);

    std::string toString() const;
    friend std::ostream &operator<<(std::ostream &out, const LargeNum &a);
    bool isInt() const;
    bool isLongLong() const;
    int toInt() const;
    long long toLongLong() const;

    LargeNum operator-() const;
    friend LargeNum operator+(const LargeNum &a, const LargeNum &b);
    friend LargeNum operator-(const LargeNum &a, const LargeNum &b);
    friend LargeNum operator*(const LargeNum &a, const LargeNum &b);
    friend LargeNum operator/(const LargeNum &a, int b);
    friend int operator%(const LargeNum &a, int b);
    friend LargeNum operator/(const LargeNum &a, const LargeNum &b);
    friend LargeNum operator%(const LargeNum &a, const LargeNum &b);

    LargeNum &operator+=(const LargeNum &a);
    LargeNum &operator-=(const LargeNum &a);
    LargeNum &operator*=(const LargeNum &a);
    LargeNum &operator/=(int a);
    LargeNum &operator%=(int a);
    LargeNum &operator/=(const LargeNum &a);
    LargeNum &operator%=(const LargeNum &a);

    explicit operator bool();
    friend bool operator==(const LargeNum &a, const LargeNum &b);
    friend bool operator!=(const LargeNum &a, const LargeNum &b);
    friend bool operator>(const LargeNum &a, const LargeNum &b);
    friend bool operator<(const LargeNum &a, const LargeNum &b);
    friend bool operator>=(const LargeNum &a, const LargeNum &b);
    friend bool operator<=(const LargeNum &a, const LargeNum &b);

    Error error;

private:
    char *_data;
    bool _sign;

    explicit LargeNum(char *a);
    explicit LargeNum(char *a, bool sg);

    static long long pow10(int a);

    static LargeNum unsignPlus(const LargeNum &a, const LargeNum &b);
    static LargeNum unsignMinus(const LargeNum &a, const LargeNum &b);
    static bool unsignCmp(const LargeNum &a, const LargeNum &b);
};