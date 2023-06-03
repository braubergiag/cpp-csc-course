
#include <gtest/gtest.h>
#include "../rational.h"

TEST(Rational,Addition){
    Rational r1(1,2), r2(1,2);

    r1 +=r2;
    ASSERT_EQ(r1.get_numerator(),1);
    ASSERT_EQ(r1.get_denominator(),1);


}
TEST(Rational,Subtraction){
    Rational r1(3,4), r2(1,4);

    r1 -=r2;
    ASSERT_EQ(r1.get_numerator(),1);
    ASSERT_EQ(r1.get_denominator(),2);


}
TEST(Rational,Division){
    Rational r1(2,4), r2(1,2);

    r1 /=r2;
    ASSERT_EQ(r1.get_numerator(),1);
    ASSERT_EQ(r1.get_denominator(),1);


}
TEST(Rational,Mult){
    Rational r1(1,2), r2(1,2);

    r1 *=r2;
    ASSERT_EQ(r1.get_numerator(),1);
    ASSERT_EQ(r1.get_denominator(),4);




}
TEST(Rational,MultNumber){
    Rational r1(1,2);

    r1 *=2;
    ASSERT_EQ(r1.get_numerator(),1);
    ASSERT_EQ(r1.get_denominator(),1);

}
TEST(Rational,Neg){
    Rational r1(1,2);

    r1 = -r1;
    ASSERT_EQ(r1.get_numerator(),-1);
    ASSERT_EQ(r1.get_denominator(),2);


}

TEST(Rational,MultInt){
    Rational r1(-1,2);

    Rational r = 2 * r1;
    ASSERT_EQ(r.get_numerator(),-2);
    ASSERT_EQ(r.get_denominator(),2);


}
TEST(Rational,AddInt){
    Rational r1(-1,2);

    Rational r = 2 + r1;
    ASSERT_EQ(r.get_numerator(),-2);
    ASSERT_EQ(r.get_denominator(),2);


}
TEST(Rational,DivInt){
    Rational r1(-1,2);

    Rational r = r1 / 2;
    ASSERT_EQ(r.get_numerator(),-1);
    ASSERT_EQ(r.get_denominator(),4);


}