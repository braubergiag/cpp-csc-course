
#include <stdlib.h>
#include <stdio.h>

unsigned strlen(const char * s){
    unsigned i{0};
    while (s[i] != '\0') {
        ++i;
    }
    return i;
}