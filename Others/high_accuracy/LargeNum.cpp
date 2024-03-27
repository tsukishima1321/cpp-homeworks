#include "LargeNum.h"
#include <iostream>

int LargeNum::pow10(int a){
    int p = 1;
    for (int i = 0; i < a; i++) {
        p *= 10;
    }
    return p;
}

LargeNum::LargeNum(){
    error = 0;
    _data = new int[N]{};
}

LargeNum::LargeNum(const LargeNum& from){
    error = 0;
    _data = new int[N]{};
    for(int i=0;i<N;i++){
        this->_data[i] = from._data[i];
    }
}

LargeNum::LargeNum(const int a[N]){
    error = 0;
    _data = new int[N]{};
    for(int i=0;i<N;i++){
        this->_data[i] = a[i];
    }
}

LargeNum::LargeNum(int e){
    error = e;
}

void LargeNum::FromKeyboard(){
    std::string s;
    std::cin >> s;
    for (int i = 0; i < s.length(); i++) {
        _data[i] = s[s.length() - i - 1] - '0';
    }
}

std::string LargeNum::toString() const{
    std::string res = "";
    bool f = false;
    for (int i = N-1; i >= 0; i--) {
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

std::ostream& operator<<(std::ostream& out,const LargeNum& a){
    out<<a.toString();
    return out;
}

LargeNum operator+(const LargeNum& a,const LargeNum& b){
    int target[N] = {};
    for (int i = 0; i < N; i++) {
        target[i] += a._data[i] + b._data[i];
        if (target[i] > 10) {
            if (i < N - 1) {
                target[i] %= 10;
                target[i + 1] += 1;
            } else {
                return LargeNum(-1);
            }
        }
    }
    return LargeNum(target);
}

LargeNum operator*(const LargeNum& a,const LargeNum& b){
    int target[N] = {};
    for (int i = 0; i < N; i++) {
        int n = 0;
        for (int j = 0; j < N; j++) {
            if (i + j > N - 1 ) {
                if (a._data[i] * b._data[j] + n > 0) {
                    return LargeNum(-1); //结果溢出
                } else {
                    continue;
                }
            }
            target[i + j] += a._data[i] * b._data[j] + n;
            n = target[i + j] / 10;
            target[i + j] %= 10;
        }
    }
    return LargeNum(target);
}

LargeNum operator/(const LargeNum& a,int b){
    int target[N] = {};
    int l = 0;
    int b_ = b;
    while (b_) { //获取除数的位数，存入l
        b_ /= 10;
        l++;
    }
    int i;
    for (i = N - 1; i >= 0; i--) { //跳过所有前导零，此后i即为a的最高位的位数
        if (a._data[i] != 0) {
            break;
        }
    }
    if (i + 1 < l) { //被除数位数小于除数，直接将被除数作为余数输出
        return LargeNum();
    }
    int n; //每次除法余数中最高位的部分
    long long a_front = 0;
    for (int j = 0; j < l; j++) {  //在高位截取被除数与除数位数相同的一段，存入a_front
        a_front += LargeNum::pow10(l - j - 1) * a._data[i - j];
    }
    target[i - l + 1] = a_front / b;
    for (int j = i - l; j >= 0; j--) {
        a_front %= b;
        n = a_front / LargeNum::pow10(l - 1);
        a_front = a_front % LargeNum::pow10(l - 1) * 10 + a._data[j] + LargeNum::pow10(l) * n;
        target[j] = a_front / b;
    }
    return LargeNum(target);
}

unsigned int operator%(const LargeNum& a,int b){
    int target[N] = {};
    int l = 0;
    int b_ = b;
    int remain = 0;
    while (b_) {
        b_ /= 10;
        l++;
    }
    int i;
    for (i = N - 1; i >= 0; i--) {
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
    target[i - l + 1] = a_front / b;
    for (int j = i - l; j >= 0; j--) {
        a_front %= b;
        n = a_front / LargeNum::pow10(l - 1);
        a_front = a_front % LargeNum::pow10(l - 1) * 10 + a._data[j] + LargeNum::pow10(l) * n;
        target[j] = a_front / b;
    }
    remain = a_front % b;
    return remain;
}