#pragma once
#include <iostream>

struct String {
    struct ProxyString {
        ProxyString(const char * str,size_t start_index ) :
        size_(strlen(str)),
        str_(new char[strlen(str) + 1]),
        start_index_(start_index){
            strcpy(str_,str);
        }
        String  operator[](int end_index) const{

            return String(str_, end_index - start_index_);
        }
        ~ProxyString() {
            delete[] str_;
        }

        size_t size_;
        char * str_;
        size_t start_index_;
    };
    String(const char *str = "") : size_(strlen(str)), str_(new char[strlen(str) + 1]){
        strcpy(str_,str);
    }
    String(const char *str, size_t size) : size_(size), str_(new char[size + 1]){
        strncpy(str_,str,size);
        str_[size_] = '\0';
    }
    String(size_t n, char c) : size_(n), str_(new char[n + 1]) {

    };
    ~String(){
        delete[] str_;
    };

    String(const String &other) : String(other.data()){}
    const char * data() const {
        return str_;
    }
    String &operator=(const String &other){
        if (this == &other){
            return *this;
        }
        delete[] str_;
        str_ = new char[other.size_ + 1];
        strcpy(str_, other.str_);
        return *this;
    }

    ProxyString operator[](int start_index) const {
        return ProxyString(str_ + start_index, start_index);
    }


    void append(const String &other){

    }
    size_t size() const {
        return size_;
    }


private:
    size_t size_;
    char *str_;
};
std::ostream  & operator <<(std::ostream& os, const String & s){

}
bool operator==(const String & lhs,const String & rhs){
    return strcmp(lhs.data(),rhs.data()) == 0;
}
