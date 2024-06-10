#include "MyStr.h"
#include <cstring>

Mystring::Mystring() : str(nullptr), capacity(0) {
    str = new char[1];
    str[0] = '\0';
}

Mystring::Mystring(const char *s) {
    // capacity = strlen(s);
    for (capacity = 0; s[capacity] != '\0'; capacity++)
        ;
    str = new char[capacity + 1];
    strcpy(str, s);
}

Mystring::~Mystring() {
    if (str != nullptr) {
        delete[] str;
    }
}

Mystring::Mystring(const Mystring &a) {
    capacity = a.length();
    str = new char[capacity + 1];
    strcpy(str, a.str);
}

Mystring &Mystring::operator=(const Mystring &a) {
    if (this == &a) {
        return *this;
    }
    delete[] str;
    capacity = a.length();
    str = new char[capacity + 1];
    strcpy(str, a.str);
    return *this;
}

Mystring::Mystring(Mystring &&a) {
    capacity = a.capacity;
    str = a.str;
    a.str = nullptr;
}

Mystring &Mystring::operator=(Mystring &&a) {
    if (this == &a) {
        return *this;
    }
    delete[] str;
    capacity = a.capacity;
    str = a.str;
    a.str = nullptr;
    return *this;
}

void Mystring::setString(const char *s) {
    int length;
    for (length = 0; s[length] != '\0'; length++)
        ;
    if (length > capacity) {
        delete[] str;
        capacity = length;
        str = new char[capacity + 1];
    }
    strcpy(str, s);
}

std::ostream &operator<<(std::ostream &out, const Mystring &a) {
    out << a.str;
    return out;
}

int Mystring::length() const {
    int length;
    for (length = 0; str[length] != '\0'; length++)
        ;
    return length;
}

bool operator==(const Mystring &a, const Mystring &b) {
    if (a.length() != b.length()) {
        return false;
    }
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

Mystring operator+(const Mystring &a, const Mystring &b) {
    Mystring temp;
    temp.capacity = a.length() + b.length();
    temp.str = new char[temp.capacity + 1];
    strcpy(temp.str, a.str);
    strcpy(temp.str + a.length(), b.str);
    return temp;
}

const char &Mystring::operator[](int index) const {
    return str[index];
}

char &Mystring::operator[](int index) {
    return str[index];
}

Mystring::Iterator Mystring::begin() const {
    return Iterator(str, this);
}

Mystring::Iterator Mystring::end() const {
    return Iterator(str + length(), this);
}

Mystring::Iterator::Iterator(char *now, const Mystring *parent) : now(now), parent(parent) {}

Mystring::Iterator &Mystring::Iterator::operator++() {
    now++;
    return *this;
}

Mystring::Iterator Mystring::Iterator::operator++(int) {
    Iterator temp = *this;
    now++;
    return temp;
}

Mystring::Iterator &Mystring::Iterator::operator--() {
    now--;
    return *this;
}

Mystring::Iterator Mystring::Iterator::operator--(int) {
    Iterator temp = *this;
    now--;
    return temp;
}

Mystring::Iterator &Mystring::Iterator::operator+=(int n) {
    now += n;
    return *this;
}

Mystring::Iterator &Mystring::Iterator::operator-=(int n) {
    now -= n;
    return *this;
}

Mystring::Iterator Mystring::Iterator::operator+(int n) const {
    return Iterator(now + n, parent);
}

Mystring::Iterator Mystring::Iterator::operator-(int n) const {
    return Iterator(now - n, parent);
}

int Mystring::Iterator::operator-(const Iterator &a) const {
    if (a.parent != parent) {
        throw "Different parent";
    }
    return now - a.now;
}

char &Mystring::Iterator::operator[](int n) {
    return *(now + n);
}

char &Mystring::Iterator::operator*() {
    return *now;
}

bool Mystring::Iterator::operator==(const Iterator &a) const {
    if (a.parent != parent) {
        throw "Different parent";
    }
    return now == a.now;
}

bool Mystring::Iterator::operator!=(const Iterator &a) const {
    if (a.parent != parent) {
        throw "Different parent";
    }
    return now != a.now;
}

bool Mystring::Iterator::operator<(const Iterator &a) const {
    if (a.parent != parent) {
        throw "Different parent";
    }
    return now < a.now;
}

bool Mystring::Iterator::operator>(const Iterator &a) const {
    if (a.parent != parent) {
        throw "Different parent";
    }
    return now > a.now;
}

bool Mystring::Iterator::operator<=(const Iterator &a) const {
    if (a.parent != parent) {
        throw "Different parent";
    }
    return now <= a.now;
}

bool Mystring::Iterator::operator>=(const Iterator &a) const {
    if (a.parent != parent) {
        throw "Different parent";
    }
    return now >= a.now;
}