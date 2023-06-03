#include <iostream>
struct Dummy { };
typedef int type;
template <typename U,typename V>
struct SameType {
public:
    static const bool value{false};
};
template <typename U>
struct SameType<U,U> {
public:
    static const bool value{true};
};


int main(){
    std::cout << SameType<int, int>::value << std::endl; // выведет 1, т. е. true
    std::cout << SameType<int, type>::value << std::endl; // 1, type == int
    std::cout << SameType<int, int&>::value << std::endl; // 0, int и ссылка на int - различные типы
    std::cout << SameType<int&, int>::value << std::endl; // 0, int и ссылка на int - различные типы
    std::cout << SameType<int&, int&>::value << std::endl; // 0, int и ссылка на int - различные типы
    std::cout << SameType<Dummy, Dummy>::value << std::endl; // 1
    std::cout << SameType<int, const int>::value << std::endl; // 0, const - часть типа
    std::cout << SameType<const int, int>::value << std::endl; // 0, const - часть типа
}