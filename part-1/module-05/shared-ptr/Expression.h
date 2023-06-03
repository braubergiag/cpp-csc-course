//
// Created by igor on 27.05.23.
//

#ifndef SHAREDPTR_EXPRESSION_H
#define SHAREDPTR_EXPRESSION_H
#include <cstdio>
#include <cstring>
#include <iostream>


struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression() {}
};

struct Number : Expression
{
    Number(double value)
            : value(value)
    {}

    double evaluate()const  override  {
        return value;
    }

private:
    double value;
};

struct BinaryOperation : Expression
{
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const * left, char op, Expression const * right)
            : left(left), op(op), right(right)
    { }
    ~BinaryOperation(){
        delete left;
        delete right;
    }
    double evaluate() const override {
        double res{};
        auto left_val = left->evaluate();
        auto right_val = right->evaluate();
        switch (op){
            case '+':
                res = left_val + right_val;
                break;
            case '-':
                res = left_val - right_val;
                break;
            case '*':
                res = left_val * right_val;
                break;
            case '/':
                res = left_val / right_val;
                break;
            default:
                break;
        }
        return res;

    }

private:
    Expression const * left;
    Expression const * right;
    char op;
};
#endif //SHAREDPTR_EXPRESSION_H
