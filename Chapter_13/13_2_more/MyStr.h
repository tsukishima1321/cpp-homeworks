#include <iostream>

class Mystring {
private:
    char *str;
    int capacity;

public:
    Mystring();
    Mystring(const char *s);
    ~Mystring();

    Mystring(const Mystring &a);
    Mystring &operator=(const Mystring &a);
    Mystring(Mystring &&a);
    Mystring &operator=(Mystring &&a);

    void setString(const char *s);

    friend std::ostream &operator<<(std::ostream &out, const Mystring &a);

    int length() const;

    friend bool operator==(const Mystring &a, const Mystring &b);
    friend Mystring operator+(const Mystring &a, const Mystring &b);

    const char &operator[](int index) const;
    char &operator[](int index);

    class Iterator {
        friend class Mystring;

    private:
        char *now;
        const Mystring *parent;
        Iterator() = delete;
        Iterator(char *now, const Mystring *parent);

    public:
        // 随机访问迭代器
        using iterator_category = std::random_access_iterator_tag;
        using value_type = char;
        using difference_type = int;
        using pointer = char *;
        using reference = char &;
        Iterator &operator++();
        Iterator operator++(int);
        Iterator &operator--();
        Iterator operator--(int);
        Iterator &operator+=(int n);
        Iterator &operator-=(int n);
        Iterator operator+(int n) const;
        Iterator operator-(int n) const;
        int operator-(const Iterator &a) const;
        char &operator[](int n);
        char &operator*();
        bool operator==(const Iterator &a) const;
        bool operator!=(const Iterator &a) const;
        bool operator<(const Iterator &a) const;
        bool operator>(const Iterator &a) const;
        bool operator<=(const Iterator &a) const;
        bool operator>=(const Iterator &a) const;
    };

    Iterator begin() const;
    Iterator end() const;
};