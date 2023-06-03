#include "array_2.h"
#include <gtest/gtest.h>
#include <vector>


TEST(Array, Int){

    Array<int> a1(3,5);
    Array<int> a2;

    a2 = a1;
    ASSERT_EQ(a1,a2);

    Array<int> a3(10,0);
    a3 = a1;
    ASSERT_EQ(a3,a1);

}

TEST(Array, String){
    Array<std::string> s1(10,"Hello");
    Array<std::string> s2(2,"Hi");

    s2 = s1;
    ASSERT_EQ(s1,s2);
}
TEST(Array, VecString){
    Array<std::vector<std::string>> s1(3,{"Hello"});
    Array<std::vector<std::string>> s2;

    s2 = s1;
    ASSERT_EQ(s1.size(),s2.size());
}
