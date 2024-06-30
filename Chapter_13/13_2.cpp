// 设计一个字符串类(Mystring)，除具有一般的输入输出字符串的功能外，还要求具有计算字符串长度、连接两个字符串等功能，
//  其中求字符串长度和连接字符串功能不能直接调用字符串处理函数。再编写主函数对该类进行测试。

#include <cstring>
#include <iostream>

// 不太清楚这道题要求到什么程度，就写多一点了（）

class Mystring {
private:
    char *str;
    int capacity;

public:
    Mystring() : str(nullptr), capacity(0) {}

    Mystring(const char *s) {
        // capacity = strlen(s);
        for (capacity = 0; s[capacity] != '\0'; capacity++)
            ;
        str = new char[capacity + 1];
        strcpy(str, s);
    }

    ~Mystring() {
        if (str != nullptr) {
            delete[] str;
        }
    }

    Mystring(const Mystring &a) {
        capacity = a.length();
        str = new char[capacity + 1];
        strcpy(str, a.str);
    }

    Mystring &operator=(const Mystring &a) {
        if (this == &a) {
            return *this;
        }
        delete[] str;
        capacity = a.length();
        str = new char[capacity + 1];
        strcpy(str, a.str);
        return *this;
    }

    Mystring(Mystring &&a) {
        capacity = a.capacity;
        str = a.str;
        a.str = nullptr;
    }

    Mystring &operator=(Mystring &&a) {
        if (this == &a) {
            return *this;
        }
        delete[] str;
        capacity = a.capacity;
        str = a.str;
        a.str = nullptr;
        return *this;
    }

    void setString(const char *s) {
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
    
    friend std::ostream &operator<<(std::ostream &out, const Mystring &a) {
        out << a.str;
        return out;
    }

    int length() const {
        int length;
        for (length = 0; str[length] != '\0'; length++)
            ;
        return length;
    }

    void cat(const Mystring &s) {
        int length = this->length() + s.length();
        if (length > capacity) {
            capacity = length;
            char *temp = new char[capacity + s.capacity + 1];
            strcpy(temp, str);
            strcpy(temp + this->length(), s.str);
            delete[] str;
            str = temp;
            capacity = length;
        } else {
            strcpy(str + this->length(), s.str);
        }
    }

    friend Mystring operator+(const Mystring &a, const Mystring &b) {
        Mystring temp;
        temp.capacity = a.length() + b.length();
        temp.str = new char[temp.capacity + 1];
        strcpy(temp.str, a.str);
        strcpy(temp.str + a.length(), b.str);
        return temp;
    }
};

int main() {
    Mystring s1("Hello");
    Mystring s2("World");
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << "Length of s1: " << s1.length() << std::endl;
    std::cout << "Length of s2: " << s2.length() << std::endl;
    s1 = s1 + " " + s2;
    std::cout << s1 << std::endl;

    system("pause");
    return 0;
}