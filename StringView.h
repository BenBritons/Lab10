//
// Created by Ivan on 27.12.21.
//

#ifndef LAB_10_STRING_STRINGVIEW_H
#define LAB_10_STRING_STRINGVIEW_H
#include <limits>
#include <iostream>
#include <cstring>


class StringView{
public:
    StringView();
    StringView(const char* str, int count = npos);
    int length() const;
    bool empty() const;
    char* data();
    bool ends_with(StringView v) const;
    void remove_prefix(int count);
    void remove_suffix(int count);
    StringView substr(int pos, int count = npos);
    int find(StringView v, int pos = 0) const;
    int find(char c, int pos = 0) const;
    int compare(StringView v) const;
    const char& operator[](int index) const;
    const char& at(int index) const;
    bool starts_with(StringView v) const;

private:
    char* str_;
    int size_;
    const static int npos = std::numeric_limits<int>::max();
};

bool operator>(const StringView& x, const StringView& y);
bool operator<(const StringView& x, const StringView& y);
bool operator>=(const StringView& x, const StringView& y);
bool operator<=(const StringView& x, const StringView& y);
bool operator==(const StringView& x, const StringView& y);


#endif //LAB_10_STRING_STRINGVIEW_H
