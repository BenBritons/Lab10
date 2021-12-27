//
// Created by Ivan on 27.12.21.
//

#include "String.h"
#include <cstring>
#include <algorithm>


String::String() {
    capacity_ = 10;
    str_ = new char[capacity_];
    str_[0] = '\0';
}

String::String(const char *c) {
    for (int i = 0; c[i] != '\0'; ++i) {
        ++size_;
    }
    capacity_ = 2 * (size_ + 1);


    str_ = new char[capacity_];
    std::strncpy(str_, c, size_ + 1);
}

String::String(int count, char ch) {
    capacity_ = 2 * (count + 1);

    str_ = new char[capacity_];
    for (int i = 0; i < count; ++i) {
        str_[i] = ch;
    }

    str_[count] = '\0';
    size_ = count;
}

int String::length() const {
    return size_;
}

bool String::empty() const {
    return size_ == 0;
}

const char *String::c_str() const {
    return str_;
}

char String::operator[](int i) {
    return str_[i];
}

char String::operator[](int i) const {
    return str_[i];
}

String& String::operator=(const String& s) {
    delete[] str_;
    size_ = s.size_;
    capacity_ = s.capacity_;
    str_ = new char[capacity_];
    std::strncpy(str_, s.str_, size_ + 1);
}
char String::front() {
    return str_[0];
}

char String::front() const {
    return str_[0];
}

char String::back() {
    return str_[size_ - 1];
}

char String::back()const {
    return str_[size_ - 1];
}
void String::reserve(int capacity) {
    if (capacity_ >= capacity) {
        return;
    }
    capacity_ += capacity - capacity_;
}


void String::push_back(char c) {
    if (size_ == capacity_) {
        capacity_ *= 2;
    }

    str_[size_] = c;
    str_[size_ + 1] = '\0';

    ++size_;
}

void String::pop_back() {
    --size_;
    str_[size_] = '\0';
}

void String::clear() {
    delete[] str_;
    capacity_ = 10;
    size_ = 0;
    str_ = new char[1];
    str_[0] = '\0';
}


void String::insert(int index, const String& str) {
    if (capacity_ < size_ + str.size_ + 1) {
        capacity_ = 2 * (size_ + str.size_ + 1);
    }
    char* tmp = new char[capacity_];
    for (int i = 0; i < index; ++i) {
        tmp[i] = str_[i];
    }
    for (int i = 0; i < str.size_; ++i) {
        tmp[index + i] = str[i];
    }
    for (int i = index; i <= size_; ++i) {
        tmp[str.size_ + i] = str_[i];
    }
    delete str_;
    str_ = tmp;
    size_ += str.size_;
}



void String::erase(int index, int count) {
    int to_erase = std::min(count, size_ - index);
    char c[size_ - index - count];
    for (int i = 0; i < size_ - index - to_erase; ++i) {
        c[i] = str_[index + to_erase + i];
    }
    for (int i = index; i < size_; ++i) {
        str_[i] = '\0';
    }
    for (int i = 0; i < size_ - index - count; ++i) {
        str_[index + i] = c[i];
    }
    size_ -= to_erase;
}

String operator+(const String& x, const String& y) {
    String s(x);
    s.insert(s.length(), y);
    return s;
}

String& operator+=(String& x, const String& y) {
    x = x + y;
    return x;
}

int String::compare(const String& str) const {
    int i = std::strncmp(str_, str.str_, std::min(size_, str.size_));
    if (i == 0 && size_ != str.size_) {
        ++i;
        i -= 2 * (size_ > str.size_);
    }
    return i;
}

int String::compare(const char* str) const {
    int len = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        ++len;
    }
    int i = std::strncmp(str_, str, std::min(size_, len));
    if (i == 0 && size_ != len) {
        ++i;
        i -= 2 * (size_ > len);
    }
    return i;
}


bool operator>(const String& x, const String& y) {

    return x.compare(y) > 0;
}



bool operator<(const String& x, const String& y) {
    return x.compare(y) < 0;
}

bool operator>=(const String& x, const String& y) {
    return x.compare(y) >= 0;
}

bool operator<=(const String& x, const String& y) {
    return x.compare(y) <= 0;
}

bool operator==(const String& x, const String& y) {
    return x.compare(y) == 0;
}

void String::insert(int index, const char* str, int count) {
    if (capacity_ < size_ + count + 1) {
        capacity_ = 2 * (size_ + count + 1);
    }
    char* tmp = new char[capacity_];
    for (int i = 0; i < index; ++i) {
        tmp[i] = str_[i];
    }
    for (int i = 0; i < count; ++i) {
        tmp[index + i] = str[i];
    }
    for (int i = index; i <= size_; ++i) {
        tmp[count + i] = str_[i];
    }
    delete str_;
    str_ = tmp;
    size_ += count;
}

String::String(const String &s) {

    size_ = s.size_;
    capacity_ = s.capacity_;
    str_ = new char[capacity_];
    std::strncpy(str_, s.str_, size_ + 1);
}
String::String(String&& s) noexcept {
    capacity_ = s.capacity_;
    size_ = s.size_;
    str_ = s.str_;
}

String& String::operator=(const String &&s) noexcept{
    capacity_ = s.capacity_;
    size_ = s.size_;
    str_ = s.str_;
}

