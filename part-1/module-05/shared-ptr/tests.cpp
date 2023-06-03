#include <gtest/gtest.h>
#include "SharedPtr.h"


TEST(SharedPtr, Ctr){
    Expression * expr = new BinaryOperation(new Number(4.5), '*', new Number(5));
    SharedPtr ptr(expr);

}
TEST(SharedPtr, CopyCtr){
    Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression * expr = new BinaryOperation(new Number(3), '+', sube);


    SharedPtr ptr(expr);
    SharedPtr ptr2 = ptr;
    SharedPtr ptr3 = ptr2;
    SharedPtr ptr4 = ptr;

}
TEST(SharedPtr, Assignment){
    Expression * expr1 = new BinaryOperation(new Number(2), '*', new Number(2));
    Expression * expr2 = new BinaryOperation(new Number(1), '+', new Number(1));


    SharedPtr ptr_1(expr1),ptr_2(expr2), ptr_3,ptr_4;

    ptr_3 = ptr_1;
    ASSERT_EQ(ptr_3->evaluate(),ptr_1->evaluate());

    ptr_4 = ptr_2;
    ASSERT_EQ(ptr_4->evaluate(),ptr_2->evaluate());

}

TEST(SharedPtr, Reset){
    Expression * expr1 = new BinaryOperation(new Number(2), '*', new Number(2));
    Expression * expr2 = new BinaryOperation(new Number(1), '+', new Number(1));


    SharedPtr ptr_1(expr1);

    ptr_1.reset(expr2);

}