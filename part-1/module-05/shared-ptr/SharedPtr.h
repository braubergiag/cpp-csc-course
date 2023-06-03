
#ifndef SHAREDPTR_SHAREDPTR_H
#define SHAREDPTR_SHAREDPTR_H
#include "Expression.h"
struct SharedPtr
{

    explicit SharedPtr(Expression *ptr = nullptr) : ptr_(ptr) {
         if (ptr_) counter_ = new size_t(1);

    }

    SharedPtr(const SharedPtr & ptr)  {

        ptr_ = ptr.get();
        counter_ = ptr.counter_;
        if (ptr_) {
            ++(*counter_);
        }

    }

    SharedPtr& operator=(const SharedPtr & ptr) {
        if (this == &ptr) return *this;

        if (ptr_) {
            --(*counter_);
            if (*counter_ == 0){
                delete ptr_;
                delete counter_;
            }
        }

        if (ptr.get()) ++(*ptr.counter_ );
        ptr_ = ptr.ptr_;
        counter_ = ptr.counter_;
        return *this;



    }
    ~SharedPtr() {
        if (ptr_){
            --(*counter_);
            if (*counter_ == 0){
                delete ptr_;
                delete counter_;
            }
        }


    }
    Expression* get() const {
        return ptr_;
    }


    void reset(Expression *ptr = 0) {
        if (ptr_){
            --(*counter_);
            if (*counter_ == 0){
                delete ptr_;
                delete counter_;
            }
        }

        ptr_ = ptr;
        if (ptr) {
            counter_ = new size_t (1);
        }
    }
    Expression& operator*() const {
        return *ptr_;
    }
    Expression* operator->() const {
        return ptr_;
    }

private:
    Expression *ptr_;
    size_t * counter_{nullptr};
};

#endif //SHAREDPTR_SHAREDPTR_H
