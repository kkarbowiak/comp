#include "catch/catch.hpp"

#include "compSequentialEqual.h"

#include <string>


TEST_CASE("sequentialEqual", "[comp][sequentialEqual")
{
    int const i1 = 1;
    int const i2 = 2;
    double const d1 = 3.415;
    double const d2 = 7.111;
    std::string const s1 = "Foo";
    std::string const s2 = "Bar";

    SECTION("one pair")
    {
        REQUIRE(comp::sequentialEqual(i1, i1));
        REQUIRE(!comp::sequentialEqual(i1, i2));
        REQUIRE(comp::sequentialEqual(d1, d1));
        REQUIRE(!comp::sequentialEqual(d1, d2));
        REQUIRE(comp::sequentialEqual(s1, s1));
        REQUIRE(!comp::sequentialEqual(s1, s2));
    }
}

