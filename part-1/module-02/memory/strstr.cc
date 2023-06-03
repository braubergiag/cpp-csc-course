#include <stdlib.h>
#include <stdio.h>
#include "test_runner.h"
unsigned strlen(const char * s){
    unsigned i{0};
    while (s[i] != '\0') {
        ++i;
    }
    return i;
}


int strstr(const char *text, const char *pattern)
{
    size_t sz_text{strlen(text)};
    size_t sz_pattern{strlen(pattern)};
    if (sz_pattern > sz_text) return -1;
    for (size_t i = 0; i < sz_text - sz_pattern + 1; i++)
    {
        bool found{true};
        for (size_t j = 0; j < sz_pattern; j++)
        {
            if (text[i + j] != pattern[j]) found = false;
        }
        if (found) return i;
    }
    
    return -1;

}



void test_1(){

    ASSERT_EQUAL(strstr("Hello","H"),0);
    ASSERT_EQUAL(strstr("Hello","He"),0);
    ASSERT_EQUAL(strstr("Hello Hello","He"),0);
    ASSERT_EQUAL(strstr("Hello","Hello"),0);
    ASSERT_EQUAL(strstr("Hello","el"),1);
    ASSERT_EQUAL(strstr("Hello","ell"),1);
    ASSERT_EQUAL(strstr("Hello","ello"),1);
    ASSERT_EQUAL(strstr("Hello","llo"),2);
    ASSERT_EQUAL(strstr("Hello","ll"),2);
    ASSERT_EQUAL(strstr("Hello","lo"),3);
    ASSERT_EQUAL(strstr("Hello","o"),4);
    ASSERT_EQUAL(strstr("one two three","two"),4);
    ASSERT_EQUAL(strstr("one two three"," t"),3);
    ASSERT_EQUAL(strstr("one two three","one"),0);
    ASSERT_EQUAL(strstr("one two three","three"),8);
    ASSERT_EQUAL(strstr("one two three","ree"),10);
    ASSERT_EQUAL(strstr("one two three","ee"),11);
    ASSERT_EQUAL(strstr("one two three","e"),2);
    ASSERT_EQUAL(strstr("one two three","n"),1);
    ASSERT_EQUAL(strstr("one two three",""),0);
    ASSERT_EQUAL(strstr(" Hello"," "),0);
    ASSERT_EQUAL(strstr("Hello "," "),5);

    ASSERT_EQUAL(strstr("a","a"),0);
    ASSERT_EQUAL(strstr("ab","a"),0);
    ASSERT_EQUAL(strstr("ab","b"),1);
    ASSERT_EQUAL(strstr("abab","aba"),0);
    ASSERT_EQUAL(strstr("abab","bab"),1);
    ASSERT_EQUAL(strstr("ababc","ab"),0);
    ASSERT_EQUAL(strstr("ababc","abc"),2);
    ASSERT_EQUAL(strstr("ababc","bc"),3);
    ASSERT_EQUAL(strstr("ababc","c"),4);
    ASSERT_EQUAL(strstr("ababc","a"),0);
    ASSERT_EQUAL(strstr("ababcababc","ababc"),0);
    ASSERT_EQUAL(strstr("ababcababc","abc"),2);


}
void test_2(){

    ASSERT_EQUAL(strstr("Hello","aba"),-1);
    ASSERT_EQUAL(strstr("Hello","elloo"),-1);
    ASSERT_EQUAL(strstr("Hello","Heh"),-1);
    ASSERT_EQUAL(strstr("Hello","hello"),-1);
    ASSERT_EQUAL(strstr("Hello","Hello "),-1);
    ASSERT_EQUAL(strstr("ab","abba"),-1);
    ASSERT_EQUAL(strstr("ab","ba"),-1);
    ASSERT_EQUAL(strstr("ab","bb"),-1);
    ASSERT_EQUAL(strstr("ab","B"),-1);
    ASSERT_EQUAL(strstr("ab","aB"),-1);
    ASSERT_EQUAL(strstr("a","aa"),-1);
    ASSERT_EQUAL(strstr("aab","aaa"),-1);
    ASSERT_EQUAL(strstr("","aa"),-1);
    ASSERT_EQUAL(strstr("ab","abb"),-1);


}
void test_empty(){
    ASSERT_EQUAL(strstr("Hello",""),0);
    ASSERT_EQUAL(strstr("",""),0);
    ASSERT_EQUAL(strstr(" ",""),0);
    ASSERT_EQUAL(strstr("a",""),0);


    const char * s = "Hello";
}

int main(){


    TestRunner tr;
    RUN_TEST(tr,test_1);
    RUN_TEST(tr,test_2);
    RUN_TEST(tr,test_empty);


}