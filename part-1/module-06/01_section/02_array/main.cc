
#include <iostream>
#include "array_2.h"
#include "test_runner.h"
#include <vector>
using namespace std;

struct Foo {
    int data_;
    Foo() = delete;
    explicit Foo(int i) : data_(i) {
        // cout << "Foo ctr \n";
    }
    Foo(const Foo & f) : data_(f.data_) {
        // cout << "Foo cctr \n";
    }

    void Hello(){
        cout << "Hello " << data_ << "\n"; 
    }
    ~Foo(){
        // cout << "~Foo \n";
    }
    Foo & operator=(const Foo & f) = default;


};
using std::string;




void TestString(){

    Array<string> a1(3,"Hello");
    Array<string> a2(5,"Hi");

    a1 = a2;
    cout << a1;

}



void TestInt(){

    Array<int> a1(3,0);
    Array<int> a2(55,1);
    Array<int> a3;

    a1 = a2;
    std::cout << a1 << std::endl;

}



int main(){


    int * pi = new int(2);
    int * pi2 = new int[3] {1,2,3};

    vector<int> v(0,100);

    string s1{"Hello"};
    string s2{"W"};

    cout << sizeof(s1) << " " << sizeof(s2) << endl;


    int n = 10;
    Foo ** ar = new Foo * [n];


    TestString();


    #if 0


    cout << "sizeof(Foo) = " << sizeof(Foo) << endl;
    cout << "sizeof(Foo *) = " << sizeof(Foo *) << endl;

    cout << "&ar = " << &ar << endl;
    for (size_t i = 0; i < n; i++)
    {
        cout << "&ar[" << i << "] = " << &(ar[i]) << " ==" << 
        " &(*(ar + sizeof(Foo*) * " << i <<")) " << &(*(ar + i))<< endl;
    }
    
    cout << &(ar[1])<< " " <<  &(*(ar + sizeof(Foo*)));
    
#endif



}