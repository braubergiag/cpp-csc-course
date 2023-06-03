#include <cstddef> // size_t

struct String {
    String(const char *str = "");
    String(size_t n, char c);
    ~String();

    String(const String &other);
    String &operator=(const String &other);

    void append(const String &other);

    size_t size;
    char *str;
};


int main(){

}