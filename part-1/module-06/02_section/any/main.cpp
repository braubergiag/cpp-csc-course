#include <iostream>
#include "any.h"
#include "array.h"




int main(){

    Array<Any> arr(10);

    arr[0] = 20;
    arr[1] = 'c';
    arr[2] = std::string("str");


}