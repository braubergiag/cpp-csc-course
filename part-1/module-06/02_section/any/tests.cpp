#include "any.h"
#include "array.h"
#include <gtest/gtest.h>



TEST(Any,Ctr){
    Any any;
    Any i(10);
    Any s(std::string("Hello"));
    Any d(2.43);

    any = d;
    i = s;

}
TEST(Any,Assig){


}
TEST(Any,CastInt){
    Any i(10);
    int *iptr = i.cast<int>();
    ASSERT_EQ(*iptr,10);

}
TEST(Any,CastChar){
    Any ch('c');
    char *cptr = ch.cast<char>();
    ASSERT_EQ(*cptr, 'c');
}
TEST(Any,CastToString){
    Any s(std::string("Hello"));
    auto * ps = s.cast<std::string>();
    ASSERT_EQ(*ps,"Hello");
}
TEST(Any,CastToVector){
    Any i(10);
    auto * pi = i.cast<std::vector<int>>();
    ASSERT_EQ(pi,nullptr);
}
TEST(Any,CastNullptr){
        Any i;
        auto *pi = i.cast<int>();
        ASSERT_EQ(pi, nullptr);

}
TEST(Any,IntAssignedNullptr){
    Any i(10), null;
    i = null;
    ASSERT_EQ(i.cast<int>(), nullptr);
}
TEST(Any,NullptrAssignedInt){
    Any i, j(10);
    i = j;
    ASSERT_EQ(*(i.cast<int>()), 10);
}

TEST(Any,IntAssignedString){
    Any i(10), str(std::string("Hello"));
    i = str;
    auto ps = i.cast<std::string>();
    ASSERT_EQ(*ps, "Hello");


}

TEST(Any,ChainAssignment){
    Any i(10),j,k;
    j = k = i;
    auto pj = j.cast<int>();
    ASSERT_EQ(*pj,10);
}
TEST(Any,CopyAssignment){
    Any i(10);
    Any j(i);
    auto pj = j.cast<int>();
    ASSERT_EQ(*pj,10);

}
TEST(Any,CopyNulptrAssignment){
    Any i;
    Any j(i);
    auto pj = j.cast<int>();
    ASSERT_EQ(pj,nullptr);

}