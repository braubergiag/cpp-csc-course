
#include <iostream>


template <typename U, typename T>
void copy_n( T * dst, U * src, size_t n) {

    while (n--)
        *dst++ = (T) *src++;
}

int main(){
    int ints[] = {1, 2, 3, 4};
    double doubles[4] = {};
    copy_n(doubles, ints, 4);

    for (double i : doubles) {
        std::cout << i << " ";
    }


}