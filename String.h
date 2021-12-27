//
// Created by Ivan on 27.12.21.
//

#ifndef LAB_10_STRING_STRING_H
#define LAB_10_STRING_STRING_H


class String {
public:
    String();
    explicit String(const char* c);
    String(int count, char ch);
    String(const String& s);
    String(String&& s) noexcept ;
    String& operator=(const String& s);
    String& operator=(const String&& s) noexcept ;
    int length() const;
    bool empty() const;
    const char* c_str() const;
    char operator[](int i);
    char operator[](int i) const;
    char front();
    char front() const;
    char back();
    char back() const;
    void reserve(int capacity);
    void push_back(char c);
    void pop_back();
    void clear();
    void insert(int index, const String& str);
    void insert(int index, const char* str, int count);
    void erase(int index, int count = 1);
    int compare(const String& str) const;
    int compare(const char* str) const;

    ~String();
private:
    char* str_;
    int size_ = 0;
    int capacity_;

};

String::~String() {
    delete[] str_;
    delete &size_;
    delete &capacity_;
}

String operator+(const String& x, const String& y);
String& operator+=(String& x, const String& y);

bool operator>(const String& x, const String& y);
bool operator<(const String& x, const String& y);
bool operator>=(const String& x, const String& y);
bool operator<=(const String& x, const String& y);
bool operator==(const String& x, const String& y);


#endif //LAB_10_STRING_STRING_H
