#include <gtest/gtest.h>
#include "string.h"


TEST(String,EmptyStrCtr){
    String s;
    ASSERT_EQ(s.size(),0);
}


TEST(String,CharPointerCtr){
    const char * hello = "Hello";
    String s(hello);
    ASSERT_EQ(strcmp(s.data(),"Hello"),0);
    ASSERT_EQ(s.size(),strlen(hello));
}

TEST(String,CopyCtr){
    const char * hello = "Hello";
    String s(hello);
    String s_copy(s);
    ASSERT_EQ(s.size(),s_copy.size());
    ASSERT_EQ(strcmp(s.data(),s_copy.data()),0);
}

TEST(String,Assignment){
    const char * hello = "Hello";
    const char * hi = "Hi";
    String s(hello), m(hi);
    s = m;
    ASSERT_EQ(s,m);

}

TEST(String,GetString){
    const char * hello = "Hello";
    String s(hello);


    String ss1 = s[0][4];
    ASSERT_EQ(ss1, String("Hell"));

    String ss2 = s[1][4];
    ASSERT_EQ(ss2, String("ell"));

    String ss3 = s[0][0];
    ASSERT_EQ(ss3,String());

    String ss4 = s[2][4];
    ASSERT_EQ(ss4,String("ll"));


    String ss5 = s[3][4];
    ASSERT_EQ(ss5,String("l"));

    String ss6 = s[4][4];
    ASSERT_EQ(ss6,String());


}