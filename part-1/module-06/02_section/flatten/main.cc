
#include <iostream>
#include "array.h"
#include <vector>
using namespace std;

template <typename T>
std::ostream & operator<<(std::ostream  & os,const Array<T> & ar){
    for (int i = 0; i < ar.size(); ++i) {
        os << ar[i] << " ";
    }
    os << " ";
    return os;
}



template <typename T>
void flatten(const Array<T> & ar,std::ostream  & os){
    for (int i = 0; i < ar.size(); ++i) {
        os << ar[i] << " ";
    }
    os << "\n";
}

int main(){

    Array<int> ints(2, 0);
    ints[0] = 10;
    ints[1] = 20;
    flatten(ints, std::cout); // выводит на экран строку "10 20"


    Array< Array<int> > array_of_ints(2, ints);


    flatten(array_of_ints, std::cout); // выводит на экран строку "10 20 10 20"

    Array<Array<Array<int>>> array_of_array_of_ints(3,array_of_ints);
    flatten(array_of_array_of_ints,std::cout);
}