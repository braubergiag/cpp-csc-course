#include <iostream>

template <typename T, size_t N>
size_t array_size(const T(&arr)[N]){
    return N;
}



int main(){
    int ints[] = {1, 2, 3, 4};
    int *iptr = ints;
    double doubles[] = {3.14};
    std::cout << array_size(ints); // вернет 4
    std::cout << array_size(doubles); // вернет 1
//    array_size(iptr); // тут должна произойти ошибка компиляции
}