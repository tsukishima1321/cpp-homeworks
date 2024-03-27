#include <ostream>
#include <string>

#define N 2000

class LargeNum{
public:
    LargeNum();
    LargeNum(const int a[N]);
    LargeNum(const LargeNum& from);
    LargeNum(int e);
    void FromKeyboard();
    friend LargeNum operator+(const LargeNum& a,const LargeNum& b);
    friend LargeNum operator*(const LargeNum& a,const LargeNum& b);
    friend LargeNum operator/(const LargeNum& a,int b);
    friend unsigned int operator%(const LargeNum& a,int b);
    friend std::ostream & operator<< (std::ostream &out,const LargeNum& a);
    std::string toString() const;
    static int pow10(int a);

    int error;
private:
    int *_data;
};