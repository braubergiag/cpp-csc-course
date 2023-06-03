//
// Created by igor on 28.05.23.
//

#ifndef VALUEHOLDER_ANY_H
#define VALUEHOLDER_ANY_H

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

class Any
{
private:
    ICloneable * data_;

public:
    Any() : data_(nullptr){}
    // В классе Any должен быть шаблонный
    // конструктор от одного параметра, чтобы
    // можно было создавать объекты типа Any,
    // например, следующим образом:
    //    Any i(10); // i хранит значение 10
    template <typename T>
    Any(const T & data): data_(new ValueHolder<T>(data)) {

    }

    // Не забудьте про деструктор. Все выделенные
    // ресурсы нужно освободить.
    ~Any(){
        delete data_;
    }
    Any(const Any & any) {
        if (any.data_)
            data_ = any.data_->clone();
        else
            data_ = nullptr;

    }

    Any& operator=(const Any & rhs) {
        if (this == &rhs){
            return *this;
        }
        delete data_;

        if (rhs.data_){
            data_ = rhs.data_->clone();
        } else {
            data_ = nullptr;
        }
        return *this;

    }
    template <typename T>
    T * cast(){
        auto * ptr = dynamic_cast<ValueHolder<T> *>(data_);
        if (ptr) return &ptr->data_;
        return nullptr;
    }
};

#endif //VALUEHOLDER_ANY_H
