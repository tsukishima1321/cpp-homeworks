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
    _data = new int[MAX_N]{};
}

LargeNum::LargeNum(unsigned long long a) : LargeNum::LargeNum() {
    int i = 0;
    while (a > 0) {
        _data[i] = a % 10;
        a /= 10;
        i++;
    }
}

LargeNum::LargeNum(const LargeNum &from) : LargeNum::LargeNum() {
    for (int i = 0; i < MAX_N; i++) {
        this->_data[i] = from._data[i];
    }
}

LargeNum::LargeNum(const int a[MAX_N]) : LargeNum::LargeNum() {
    for (int i = 0; i < MAX_N; i++) {
        _data[i] = a[i];
    }
}

LargeNum::LargeNum(LargeNum::Error e) {
    error = e;
}

LargeNum::~LargeNum() {
    delete[] _data;
}

void LargeNum::FromStream(std::istream &in) {
    std::string s;
    in >> s;
    for (int i = 0; i < s.length(); i++) {
        _data[i] = s[s.length() - i - 1] - '0';
    }
}

std::string LargeNum::toString() const {
    std::string res = "";
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
    out << a.toString();
    return out;
}

std::istream &operator>>(std::istream &in, LargeNum &a) {
    a.FromStream(in);
    return in;
}

LargeNum operator+(const LargeNum &a, const LargeNum &b) {
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

LargeNum operator*(const LargeNum &a, const LargeNum &b) {
    int result[MAX_N] = {};
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
    return LargeNum(result);
}

LargeNum operator/(const LargeNum &a, int b) {
    int result[MAX_N] = {};
    int l = 0;
    int b_ = b;
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
    return LargeNum(result);
}

unsigned int operator%(const LargeNum &a, int b) {
    int result[MAX_N] = {};
    int l = 0;
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
    return remain;
}