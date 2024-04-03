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