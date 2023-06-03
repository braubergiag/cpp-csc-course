#include <cstdio>
#include <cstring>
#include <iostream>

struct Number;
struct BinaryOperation;


struct Visitor {
    virtual void visitNumber(Number const * number) = 0;
    virtual void visitBinaryOperation(BinaryOperation const * operation) = 0;
    virtual ~Visitor() { }
};


struct Expression
{
    virtual double evaluate() const = 0;
        virtual void visit(Visitor * vistitor) const = 0;
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
    double get_value() const { return value; }

    void visit(Visitor * visitor) const { visitor->visitNumber(this); }
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
        Expression const * get_left() const { return left; }
    Expression const * get_right() const { return right; }
    char get_op() const { return op; }

    void visit(Visitor * visitor) const { visitor->visitBinaryOperation(this); }

private:
    Expression const * left;
    Expression const * right;
    char op;
};

/* Этот класс вам нужно реализовать */
struct PrintVisitor : Visitor {
    void visitNumber(Number const * number)
    {
        std::cout << number->get_value();
    }

    void visitBinaryOperation(BinaryOperation const * bop)
    {
        char op = bop->get_op();

        std::cout << "(";
        bop->get_left()->visit(this);
        std::cout << ")";


        std::cout << " " <<  op << " ";
        std::cout << "(";
        bop->get_right()->visit(this);
        std::cout << ")";

        
        // else {
        //     bop->get_left()->visit(this);
        //     std::cout << " " <<  op << " ";
        //     bop->get_right()->visit(this);
        // }
        

    }
};


bool check_equals(Expression const *left, Expression const *right)

{
 
    return *(int **)left == *(int **) right; 
}


int main(){


    // сначала создаём объекты для подвыражения 4.5 * 5
    Expression * s1 = new BinaryOperation(new Number(4.5),'+',new Number(2));
    Expression * s2 = new BinaryOperation(s1,'*',new Number(2));
    Expression * s3 = new BinaryOperation(s2,'+',new Number(3));
    Expression * s4 = new BinaryOperation(s3,'*',new Number(3));


    // потом используем его в выражении для +
    // Expression * expr = new BinaryOperation(new Number(3), '+', sube);

        // Expression const * expr = new BinaryOperation(new Number(3), '/', sube);;
        PrintVisitor visitor;
        s4->visit(&visitor);
    // delete expr;
}