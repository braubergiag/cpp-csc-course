
#ifndef TEMPLATES_ARRAY_2_H
#define TEMPLATES_ARRAY_2_H
#include <cstddef>
#include <algorithm>
#include <ostream>
template <typename T>
class Array
{

    size_t size_;
    T ** data_;
    char * buffer_;

public:

    explicit Array(size_t size, const T& value = T()) : 
        size_(size),
        buffer_(new char[sizeof(T) * size]),
        data_(new T * [size_]) {

        for (size_t i = 0; i < size_; ++i) {
            data_[i] = new (buffer_ + sizeof(T) * i) T(value);
        }

    }

    Array() : size_(0), data_(nullptr),buffer_(nullptr) {

    }

    Array(const Array & other) : 
        size_(other.size_), 
        buffer_(new char[sizeof(T) * size_]),
        data_(new T * [size_])
        {
            for (int i = 0; i < size_; ++i) {
                data_[i] = new (buffer_ + sizeof(T) * i) T(*other.data_[i]);
            }
        }

    ~Array(){
        for (size_t i = 0; i < size_; i++)
        {
            data_[i]->~T();
        }
        
        delete [] data_;
        delete [] buffer_;
    }
    Array& operator=(const Array & rhs){
        if (this != &rhs) {
            Array(rhs).swap(*this);
        }
        return *this;
    }

    void swap( Array & rhs) {
        std::swap(size_, rhs.size_);
        std::swap(data_, rhs.data_);
        std::swap(buffer_, rhs.buffer_);
    }

    size_t size() const {   return size_; }
    T& operator[](size_t i ) {return *data_[i];}
    const T& operator[](size_t i) const {return *data_[i];}


};

template <typename T>
std::ostream & operator<<(std::ostream& os, const Array<T> & a){
    bool first{true};
    for (size_t i = 0; i < a.size(); i++)
    {
        if (!first) os << " ";
        first = false;
        os << a[i];
    }
    return os;
    
}

template <typename T>
bool operator==(const Array<T> & lhs, const Array<T> & rhs){
    if (lhs.size() != rhs.size()) return false;
    for (size_t i = 0; i < lhs.size(); i++)
    {
        if (lhs[i] != rhs[i]) return false;

    }

    return true;
    
}





#endif //TEMPLATES_ARRAY_2_H
