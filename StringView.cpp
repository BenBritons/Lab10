//
// Created by Ivan on 27.12.21.
//

#include "StringView.h"


StringView::StringView() {
    str_ = new char[1];
    str_[0] = '\0';
    size_= 0;
}

StringView::StringView(const char* str, int count) {
    for (int i = 0; str[i] != '\0'; ++i) {
        ++size_;
    }
    if (count < size_) { size_ = count; }
    str_ = new char[size_];
    std::strncpy(str_, str, size_);
}

int StringView::length() const {
    return size_;
}

bool StringView::empty() const {
    return size_ == 0;
}

char* StringView::data() {
    return str_;
}

const char& StringView::operator[](int index) const {
    return str_[index];
}

const char& StringView::at(int index) const {
    if (index > size_) {
        throw std::out_of_range("index is out of range");
    }
    return str_[index];
}

bool StringView::starts_with(StringView v) const {
    bool equal = true;
    for (int i = 0; i < v.size_; ++i) {
        if (at(i) != v.at(i)) {
            equal = false;
        }
    }
    return equal;
}

bool StringView::ends_with(StringView v) const {
    bool equal = true;
    for (int i = 1; i <= v.size_; ++i) {
        if (at(size_ - i) != v.at(v.size_ - i)) {
            equal = false;
        }
    }
    return equal;
}

void StringView::remove_prefix(int count) {
    char* tmp = new char[size_ - count];
    for (int i = count; i < size_; ++i) {
        tmp[i - count] = str_[i];
    }
    delete[] str_;
    str_ = tmp;
    size_ -= count;
}

void StringView::remove_suffix(int count) {
    char* tmp = new char[size_ - count];
    for (int i = 0; i < size_ - count; ++i) {
        tmp[i] = str_[i];
    }
    delete[] str_;
    str_ = tmp;
    size_ -= count;
}

StringView StringView::substr(int pos, int count) {
    int n = std::min(count, size_ - pos);
    char* tmp = new char[n];
    for (int i = 0; i < n; ++i) {
        tmp[i] = str_[pos + i];
    }
    return tmp;
}

int StringView::find(StringView v, int pos) const {
    int len = v.length();
    for (int i = pos; i < size_ - len; ++i) {
        for (int j = 0; j < len; ++j) {
            if (v.at(j) != at(i + j)) {
                break;
            }
            return i;
        }
    }
    return npos;
}

int StringView::find(char c, int pos) const {
    for (int i = pos; i < size_; ++i) {
        if (str_[i] == c) {
            return i;
        }
    }
    return npos;
}

int StringView::compare(StringView v) const {
    int i = std::strncmp(str_, v.str_, std::min(size_, v.size_));
    if (i == 0 && size_ != v.size_) {
        ++i;
        i -= 2 * (size_ > v.size_);
    }
    return i;
}

bool operator>(const StringView& x, const StringView& y) {
    return x.compare(y) > 0;
}

bool operator<(const StringView& x, const StringView& y) {
    return x.compare(y) < 0;
}

bool operator>=(const StringView& x, const StringView& y) {
    return x.compare(y) >= 0;
}

bool operator<=(const StringView& x, const StringView& y) {
    return x.compare(y) <= 0;
}

bool operator==(const StringView& x, const StringView& y) {
    return x.compare(y) == 0;
}
