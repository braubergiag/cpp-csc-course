
#include <stdlib.h>
#include <stdio.h>

// Вам требуется реализовать функцию конкатенации (склейки) двух C-style строк. 
// Функция конкатенации принимает на вход две C-style строки и дописывает вторую в конец первой так,
//  чтобы первая строка представляла из себя одну C-style строку равную конкатенации двух исходных.
// Не забудьте, что в результирующей строке должен быть только один нулевой символ — тот, что является маркером конца строки.
// Гарантируется, что в первой строке достаточно памяти (т.е. она располагается в массиве достаточной длины),
//  чтобы разместить конкатенацию обеих строк, но не больше.


unsigned strlen(const char * s){
    unsigned i{0};
    while (s[i] != '\0') {
        ++i;
    }
    return i;
}

void strcat(char *to, const char *from)
{

    size_t old_len_to = strlen(to);
    size_t len_from = strlen(from);
    for (size_t i = 0; i < len_from; i++)
    {
        to[old_len_to + i] = from[i];
    }
    to[old_len_to + len_from] = '\n';
}




int main(){

    char amessage[] = "Hello";
    const char * pmessage = "Hello";
    printf("%p\n",&amessage);
    printf("%p\n",pmessage);



    return 0;
}