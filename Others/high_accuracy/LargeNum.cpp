#include "LargeNum.h"

long long LargeNum::pow10(int a) {
    long long p = 1;
    for (int i = 0; i < a; i++) {
        p *= 10;
    }
    return p;
}

LargeNum::LargeNum() {
    error = NO_ERR;
    sign = false;
    _data = new int[MAX_N]{};
}

LargeNum::LargeNum(long long a) : LargeNum::LargeNum() {
    int i = 0;
    if (a < 0) {
        a = -a;
        sign = true;
    }
    while (a > 0) {
        _data[i] = a % 10;
        a /= 10;
        i++;
    }
}

LargeNum::LargeNum(const LargeNum &from) : LargeNum::LargeNum() {
    error = from.error;
    for (int i = 0; i < MAX_N; i++) {
        _data[i] = from._data[i];
    }
    sign = from.sign;
}

LargeNum::LargeNum(LargeNum &&from) {
    error = from.error;
    _data = from._data;
    sign = from.sign;
    from._data = nullptr;
}

LargeNum::LargeNum(const int a[MAX_N]) : LargeNum::LargeNum() {
    for (int i = 0; i < MAX_N; i++) {
        _data[i] = a[i];
    }
}

LargeNum::LargeNum(const int a[MAX_N], bool sg) : LargeNum::LargeNum() {
    for (int i = 0; i < MAX_N; i++) {
        _data[i] = a[i];
    }
    sign = sg;
}

LargeNum::LargeNum(LargeNum::Error e) {
    error = e;
}

LargeNum::~LargeNum() {
    if (_data != nullptr) {
        delete[] _data;
    }
}

void LargeNum::FromStream(std::istream &in) {
    std::string s;
    in >> s;
    if (s[0] == '-') {
        sign = true;
        s.erase(0, 1);
    } else {
        sign = false;
    }
    for (int i = 0; i < s.length(); i++) {
        _data[i] = s[s.length() - i - 1] - '0';
    }
}

LargeNum &LargeNum::operator=(const LargeNum &from) {
    if (&from == this) {
        return *this;
    }
    for (int i = 0; i < MAX_N; i++) {
        _data[i] = from._data[i];
    }
    error = from.error;
    sign = from.sign;
    return *this;
}

LargeNum &LargeNum::operator=(LargeNum &&from) {
    delete[] _data;
    _data = from._data;
    sign = from.sign;
    error = from.error;
    from._data = nullptr;
    return *this;
}

std::string LargeNum::toString() const {
    std::string res = "";
    if (error != NO_ERR) {
        switch (error) {
        case OVERFLOW:
            res += "OVERFLOW";
            break;
        default:
            res += "UNKNOW_ERROR";
            break;
        }
        return res;
    }
    if (sign) {
        res += "-";
    }
    bool f = false;
    for (int i = MAX_N - 1; i >= 0; i--) {
        if (!f && _data[i] != 0) {
            f = true;
        }
        if (f) {
            res += char(_data[i] + '0');
        }
    }
    if (!f) {
        res = "0";
    }
    return res;
}

std::ostream &operator<<(std::ostream &out, const LargeNum &a) {
    if (a.error != LargeNum::NO_ERR) {
        switch (a.error) {
        case LargeNum::OVERFLOW:
            out << "OVERFLOW";
            break;
        default:
            out << "UNKNOW_ERROR";
            break;
        }
        return out;
    }
    out << a.toString();
    return out;
}

std::istream &operator>>(std::istream &in, LargeNum &a) {
    a.FromStream(in);
    return in;
}

LargeNum LargeNum::operator-() const {
    LargeNum res(*this);
    res.sign ^= true;
    return res;
}

/* 有bug 有解决bug的思路，但是可能性能糟糕
LargeNum operator+(const LargeNum &a, const LargeNum &b) {
    int result[MAX_N] = {};
    bool sg = false;
    for (int i = 0; i < MAX_N; i++) {
        result[i] += (a.sign ? -1 : 1) * a._data[i] + (b.sign ? -1 : 1) * b._data[i];
        if (result[i] >= 10) {
            if (i < MAX_N - 1) {
                result[i] %= 10;
                result[i + 1] += 1;
            } else {
                return LargeNum(LargeNum::OVERFLOW);
            }
        }
        if (result[i] < 0) {
            if (i < MAX_N - 1) {
                result[i] = result[i] + 10;
                result[i + 1] -= 1;
            } else {
                sg = true;
            }
        }
    }
    if (sg) {
        for (int i = MAX_N - 1; i >= 0; i--) {
            result[i] = 10 - result[i];
            if (result[i] == 11 || result[i] == 0) {
                result[i] = 0;
                result[i - 1] += 1;
            }
        }
    }
    return LargeNum(result, sg);
}

LargeNum operator-(const LargeNum &a, const LargeNum &b) {
    return a + -b;
}
*/
LargeNum LargeNum::unsignPlus(const LargeNum &a, const LargeNum &b) {
    int result[MAX_N] = {};
    for (int i = 0; i < MAX_N; i++) {
        result[i] += a._data[i] + b._data[i];
        if (result[i] >= 10) {
            if (i < MAX_N - 1) {
                result[i] %= 10;
                result[i + 1] += 1;
            } else {
                return LargeNum(LargeNum::OVERFLOW);
            }
        }
    }
    return LargeNum(result);
}

bool LargeNum::unsignCmp(const LargeNum &a, const LargeNum &b) {
    for (int i = MAX_N - 1; i >= 0; i--) {
        if (a._data[i] != b._data[i]) {
            return a._data[i] > b._data[i];
        }
    }
    return false;
}

LargeNum operator+(const LargeNum &a, const LargeNum &b) {
    bool is_aBigger;
    if (a.sign || b.sign) {
        is_aBigger = LargeNum::unsignCmp(a, b);
    }
    if (a.sign && b.sign) { // 都为负数
        return -LargeNum::unsignPlus(a, b);
    }
    if (a.sign && is_aBigger) { // a负b正，a绝对值大
        return -LargeNum::unsignMinus(a, b);
    }
    if (a.sign && !is_aBigger) { // a负b正，a绝对值小
        return LargeNum::unsignMinus(b, a);
    }
    if (b.sign && is_aBigger) { // a正b负，a绝对值大
        return LargeNum::unsignMinus(a, b);
    }
    if (b.sign && !is_aBigger) { // a正b负，a绝对值小
        return -LargeNum::unsignMinus(b, a);
    }
    // 都为正数
    return LargeNum::unsignPlus(a, b);
}

LargeNum LargeNum::unsignMinus(const LargeNum &a, const LargeNum &b) {
    int result[MAX_N] = {};
    for (int i = 0; i < MAX_N; i++) {
        result[i] += a._data[i] - b._data[i];
        if (result[i] < 0) {
            if (i < MAX_N - 1) {
                result[i] = result[i] + 10;
                result[i + 1] -= 1;
            } else {
                return LargeNum(LargeNum::OVERFLOW);
            }
        }
    }
    return LargeNum(result);
}

LargeNum operator-(const LargeNum &a, const LargeNum &b) {
    if (!a.sign && b.sign) {
        return LargeNum::unsignPlus(a, b);
    }
    if (a.sign && !b.sign) {
        return -LargeNum::unsignPlus(a, b);
    }
    bool is_aBigger = LargeNum::unsignCmp(a, b);
    if (!a.sign && !b.sign) {
        if (is_aBigger) {
            return LargeNum::unsignMinus(a, b);
        } else {
            return -LargeNum::unsignMinus(b, a);
        }
    }
    if (a.sign && b.sign) {
        if (is_aBigger) {
            return -LargeNum::unsignMinus(a, b);
        } else {
            return LargeNum::unsignMinus(b, a);
        }
    }
    return LargeNum(LargeNum::WAIT_WHAT);
}

LargeNum operator*(const LargeNum &a, const LargeNum &b) {
    int result[MAX_N] = {};
    bool sg = a.sign ^ b.sign;
    for (int i = 0; i < MAX_N; i++) {
        int n = 0;
        for (int j = 0; j < MAX_N; j++) {
            if (i + j > MAX_N - 1) {
                if (a._data[i] * b._data[j] + n > 0) {
                    return LargeNum(LargeNum::OVERFLOW);
                } else {
                    continue;
                }
            }
            result[i + j] += a._data[i] * b._data[j] + n;
            n = result[i + j] / 10;
            result[i + j] %= 10;
        }
    }
    return LargeNum(result, sg);
}

LargeNum operator/(const LargeNum &a, int b) {
    int result[MAX_N] = {};
    int l = 0;
    bool sg;
    bool sign_b = b < 0;
    if (sign_b) {
        b = -b;
    }
    sg = a.sign ^ sign_b;
    int b_ = b;
    while (b_ > 0) {
        b_ /= 10;
        l++;
    }
    int i;
    for (i = MAX_N - 1; i >= 0; i--) {
        if (a._data[i] != 0) {
            break;
        }
    }
    if (i + 1 < l) {
        return LargeNum();
    }
    int n;
    long long a_front = 0;
    for (int j = 0; j < l; j++) {
        a_front += LargeNum::pow10(l - j - 1) * a._data[i - j];
    }
    result[i - l + 1] = a_front / b;
    for (int j = i - l; j >= 0; j--) {
        a_front %= b;
        n = a_front / LargeNum::pow10(l - 1);
        a_front = a_front % LargeNum::pow10(l - 1) * 10 + a._data[j] + LargeNum::pow10(l) * n;
        result[j] = a_front / b;
    }
    return LargeNum(result, sg);
}

LargeNum operator/(const LargeNum &a, const LargeNum &b) {
    int result[MAX_N] = {};
    int l; // b的位数
    bool sg;
    sg = a.sign ^ b.sign;
    for (l = MAX_N - 1; l >= 0; l--) {
        if (b._data[l] != 0) {
            break;
        }
    }
    l++;
    int i;
    for (i = MAX_N - 1; i >= 0; i--) {
        if (a._data[i] != 0) {
            break;
        }
    }
    if (i + 1 < l) {
        return LargeNum();
    }
    LargeNum a_front;
    for (int j = 0; j < l; j++) {
        a_front._data[l - j - 1] = a._data[i - j];
    }
    LargeNum c = a_front;
    int n = 0;
    while (1) {
        if (LargeNum::unsignCmp(b, c)) {
            break;
        } else {
            n++;
        }
        c = LargeNum::unsignMinus(a_front, b);
    }
    result[i - l + 1] = n;
    for (int j = i - l; j >= 0; j--) {
        a_front = c;
        if (a_front._data[MAX_N - 1] > 0) {
            return LargeNum(LargeNum::OVERFLOW);
        }
        for (int k = MAX_N - 2; k >= 0; k--) {
            a_front._data[k + 1] = a_front._data[k];
        }
        a_front._data[0] = a._data[j];
        n = 0;
        c = a_front;
        while (1) {
            if (LargeNum::unsignCmp(b, c)) {
                break;
            } else {
                n++;
            }
            c = LargeNum::unsignMinus(c, b);
        }
        result[j] = n;
    }
    return LargeNum(result, sg);
}

LargeNum operator%(const LargeNum &a, const LargeNum &b){
        int result[MAX_N] = {};
    int l; // b的位数
    bool sg;
    sg = a.sign ^ b.sign;
    for (l = MAX_N - 1; l >= 0; l--) {
        if (b._data[l] != 0) {
            break;
        }
    }
    l++;
    int i;
    for (i = MAX_N - 1; i >= 0; i--) {
        if (a._data[i] != 0) {
            break;
        }
    }
    if (i + 1 < l) {
        return LargeNum();
    }
    LargeNum a_front;
    for (int j = 0; j < l; j++) {
        a_front._data[l - j - 1] = a._data[i - j];
    }
    LargeNum c = a_front;
    int n = 0;
    while (1) {
        if (LargeNum::unsignCmp(b, c)) {
            break;
        } else {
            n++;
        }
        c = LargeNum::unsignMinus(a_front, b);
    }
    result[i - l + 1] = n;
    for (int j = i - l; j >= 0; j--) {
        a_front = c;
        if (a_front._data[MAX_N - 1] > 0) {
            return LargeNum(LargeNum::OVERFLOW);
        }
        for (int k = MAX_N - 2; k >= 0; k--) {
            a_front._data[k + 1] = a_front._data[k];
        }
        a_front._data[0] = a._data[j];
        n = 0;
        c = a_front;
        while (1) {
            if (LargeNum::unsignCmp(b, c)) {
                break;
            } else {
                n++;
            }
            c = LargeNum::unsignMinus(c, b);
        }
        result[j] = n;
    }
    return c;
}

int operator%(const LargeNum &a, int b) {
    int result[MAX_N] = {};
    int l = 0;
    bool sign_b = b < 0;
    if (sign_b) {
        b = -b;
    }
    int b_ = b;
    int remain = 0;
    while (b_) {
        b_ /= 10;
        l++;
    }
    int i;
    for (i = MAX_N - 1; i >= 0; i--) {
        if (a._data[i] != 0) {
            break;
        }
    }
    if (i + 1 < l) {
        for (int j = 0; j <= i; j++) {
            remain += LargeNum::pow10(i - j) * a._data[i - j];
        }
        return remain;
    }
    int n;
    long long a_front = 0;
    for (int j = 0; j < l; j++) {
        a_front += LargeNum::pow10(l - j - 1) * a._data[i - j];
    }
    result[i - l + 1] = a_front / b;
    for (int j = i - l; j >= 0; j--) {
        a_front %= b;
        n = a_front / LargeNum::pow10(l - 1);
        a_front = a_front % LargeNum::pow10(l - 1) * 10 + a._data[j] + LargeNum::pow10(l) * n;
        result[j] = a_front / b;
    }
    remain = a_front % b;
    if (a.sign) {
        remain = b - remain;
    }
    if (sign_b) {
        remain = b - remain;
        remain = -remain;
    }
    return remain;
}

LargeNum LargeNum::operator+=(const LargeNum &a) {
    return *this = *this + a;
}

LargeNum LargeNum::operator-=(const LargeNum &a) {
    return *this = *this - a;
}

LargeNum LargeNum::operator*=(const LargeNum &a) {
    return *this = *this * a;
}

LargeNum LargeNum::operator/=(int a) {
    return *this = *this / a;
}

LargeNum LargeNum::operator%=(int a) {
    return *this = LargeNum(*this % a);
}

bool operator==(const LargeNum &a, const LargeNum &b) {
    if (a.sign != b.sign) {
        return false;
    }
    for (int i = 0; i < MAX_N; i++) {
        if (a._data[i] != b._data[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const LargeNum &a, const LargeNum &b) {
    return !(a == b);
}

bool operator>(const LargeNum &a, const LargeNum &b) {
    if (!a.sign && b.sign) {
        return true;
    }
    if (a.sign && !b.sign) {
        return false;
    }
    for (int i = MAX_N - 1; i >= 0; i--) {
        if (a._data[i] != b._data[i]) {
            if (a.sign) {
                return a._data[i] < b._data[i];
            } else {
                return a._data[i] > b._data[i];
            }
        }
    }
    return false;
}

bool operator>=(const LargeNum &a, const LargeNum &b) {
    if (!a.sign && b.sign) {
        return true;
    }
    if (a.sign && !b.sign) {
        return false;
    }
    for (int i = MAX_N - 1; i >= 0; i--) {
        if (a._data[i] != b._data[i]) {
            if (a.sign) {
                return a._data[i] < b._data[i];
            } else {
                return a._data[i] > b._data[i];
            }
        }
    }
    return true;
}

bool operator<=(const LargeNum &a, const LargeNum &b) {
    return !(a > b);
}

bool operator<(const LargeNum &a, const LargeNum &b) {
    return !(a >= b);
}