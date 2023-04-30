#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"
using namespace ariel;
#include "doctest.h"
using namespace doctest;
TEST_CASE("reduced fraction")
{
    Fraction a(540,40),b(27,2);
    Fraction c = a.reduceFraction(a);
    CHECK(c==b);
}
TEST_CASE("+ test")
{
    Fraction a(1,3), b(1,2) ,c(5,6);
    CHECK(a+b == c);
}
TEST_CASE("- test")
{
    Fraction a(1,3), b(1,2) ,c(1,-6);
    CHECK(a-b == c);
}
TEST_CASE("* test")
{
    Fraction a(1,3), b(1,2) ,c(1,6);
    CHECK(a*b == c);
}
TEST_CASE("/ test")
{
    Fraction a(1,3), b(1,2) ,c(2,3);
    CHECK(a/b == c);
}
TEST_CASE("++ test")
{
    Fraction a(1,3), b(4,3);
    CHECK(a++ == b);
}
TEST_CASE("-- test")
{
    Fraction a(1,3), b(2,-3);
    CHECK(a-- == b);
}
TEST_CASE("> test")
{
    Fraction a(1,3), b(1,2);
    CHECK_FALSE(a>b);
}
TEST_CASE("< test")
{
    Fraction a(1,3), b(1,2);
    CHECK(a<b);
}
TEST_CASE("== test false")
{
    Fraction a(1,3), b(1,2);
    CHECK(a!=b);
}
TEST_CASE("== test true")
{
    Fraction a(1,3), b(1,3);
    CHECK(a==b);
}
TEST_CASE("reduced fraction + check")
{
    Fraction a(5,3), b(14,21) ,c(7,3);
    CHECK(a+b==c);
}
TEST_CASE("reduced fraction - check")
{
    Fraction a(5,3), b(14,21) ,c(1,1);
    CHECK(a-b==c);
}
TEST_CASE("reduced fraction * check")
{
    Fraction a(5,3), b(14,21) ,c(10,9);
    CHECK(a*b==c);
}
TEST_CASE("reduced fraction / check")
{
    Fraction a(5,3), b(14,21) ,c(5,2);
    CHECK(a/b==c);
}
TEST_CASE("multipule operators 1")
{
    Fraction a(5,3), b(14,21) ,c(5,2) ,d(25,4);
    CHECK(a/b*c==d);
}
TEST_CASE("multipule operators 2")
{
    Fraction a(5,3), b(14,21) ,c(5,2) ,d(1,-6);
    CHECK(a+b-c==d);
}
TEST_CASE("multipule operators 3")
{
    Fraction a(5,3), b(14,21) ,c(5,2) ,d(10,3);
    CHECK(a+(b*c)==d);
}
TEST_CASE("multipule operators 4")
{
    Fraction a(5,3), b(14,21) ,c(5,2) ,d(29,15);
    CHECK(a+(b/c)==d);
}
TEST_CASE("multipule operators 5")
{
    Fraction a(5,3), b(14,21) ,c(5,2) ,d(7,5);
    CHECK(a-(b/c)==d);
}