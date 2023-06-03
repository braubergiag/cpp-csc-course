#include <iostream>


struct A {

public:
    int c{1124};
private:
    int b{333};
protected:
    int a{111};

};

struct B :  private A {
    void Foo()  {
        std::cout << a;
        std::cout << c;
    }


};
struct C :   B {
    void Foo()  {
        std::cout << a;
        std::cout << c;
    }


};


int main(){
    B b;
    b.Foo();
}