#include <iostream>

struct ICloneable
{
    virtual ICloneable* clone() const = 0;
    virtual ~ICloneable() { }
};

template <typename T>
struct ValueHolder : ICloneable {
public:
    T data_;

public:
    ValueHolder(const T & data) : data_(data) {}
    ValueHolder* clone() const {
        return new ValueHolder(data_);
    };
    ~ValueHolder() {}
};


int main(){

    ValueHolder<int> vh(2);
    ICloneable* first = new ValueHolder<int>(1313);
    ValueHolder<int> * vh_clone = vh.clone();
    std::cout << vh_clone->data_ << " ";

}