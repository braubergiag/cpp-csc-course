#include <cstdio>
#include <cstring>
#include <iostream>





char * getline()
{
    size_t buff_cap_init{1024};
    size_t current_buff_size{0};
    char * buffer = new char[buff_cap_init];
  
    char c = getchar();
    while (c != '\n' || c != EOF){
        if (current_buff_size < buff_cap_init) {
            buffer[current_buff_size++] = c;
        } else {
            char * old_buff = buffer;
            buff_cap_init *= 2;
            buffer = new char[buff_cap_init];
            memcpy(buffer,old_buff,current_buff_size);
            buffer[current_buff_size++] = c;
            delete[] old_buff;
        }
        c = getchar();

    }
    buffer[current_buff_size++] = '\0';
    return buffer;
   

}



int main(){

    char * buffer = getline();
    printf("%s\n",buffer);

    delete[] buffer;


}