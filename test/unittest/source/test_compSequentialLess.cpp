#include "catch/catch.hpp"

#include "compSequentialLess.h"

#include <string>


TEST_CASE("sequentialLess", "[comp][sequentialLess]")
{
    int const i1 = 1;
    int const i2 = 2;
    double const d1 = 3.415;
    double const d2 = 7.111;
    std::string const s1 = "Bar";
    std::string const s2 = "Foo";

    SECTION("one pair")
    {
        REQUIRE(comp::sequentialLess(i1, i2));
        REQUIRE(!comp::sequentialLess(i1, i1));
        REQUIRE(!comp::sequentialLess(i2, i1));
        REQUIRE(comp::sequentialLess(d1, d2));
        REQUIRE(!comp::sequentialLess(d1, d1));
        REQUIRE(!comp::sequentialLess(d2, d1));
        REQUIRE(comp::sequentialLess(s1, s2));
        REQUIRE(!comp::sequentialLess(s1, s1));
        REQUIRE(!comp::sequentialLess(s2, s1));
    }
}

