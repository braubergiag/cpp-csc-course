#include <cstddef>
#include <algorithm>

template <typename T>
class Array
{

    size_t size_;
    T * data_;

public:

    explicit Array(size_t size = 0, const T& value = T()) : size_(size), data_(new T[size]) {
        for (size_t i = 0; i < size; ++i) {
            data_[i] = value;
        }

    }
    
     Array(const Array & other) : size_(other.size_), data_(new T[size_]){
         for (int i = 0; i < size_; ++i) {
             data_[i] = other.data_[i];
         }
    }

     ~Array(){
        delete [] data_;
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
    }

     size_t size() const {   return size_; }
     T& operator[](size_t i ) {return data_[i];}
     const T& operator[](size_t i) const {return data_[i];}
};