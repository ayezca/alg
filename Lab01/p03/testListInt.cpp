// g++ -std=c++17 -DAU_DEBUG testListInt.cpp ListInt.cpp

#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"


#include "ListInt.h"

TEST_CASE("Default constructor")
{
    ListInt lst;
    
    REQUIRE(lst.size() == 0);
}

TEST_CASE("Copy constructor")
{
    ListInt lst;
    
    SECTION("Empty")
    {
        ListInt x = lst;
        REQUIRE(x.toStr()== "{}");
        lst.pushBack(1);
        REQUIRE(x.toStr()== "{}");
        REQUIRE(lst.toStr()== "{ 1}");
    }
    
    SECTION("Not empty")
    {
        lst.pushBack(1);
        lst.pushBack(2);
        lst.pushBack(3);
        
        ListInt x = lst;
        REQUIRE(x.toStr() == "{ 1, 2, 3}");
        
        lst.pushBack(4);
        REQUIRE(x.toStr() == "{ 1, 2, 3}");
        REQUIRE(lst.toStr() == "{ 1, 2, 3, 4}");
    }
}

TEST_CASE("Assignment operator")
{
    ListInt x;
    x.pushBack(1);
    x.pushBack(2);
    x.pushBack(3);
    
    ListInt y;
    y.pushBack(10);
    y.pushBack(20);
    
    y = x;
    
    REQUIRE(y.toStr() == "{ 1, 2, 3}");
    x.pushBack(4);
    REQUIRE(x.toStr() == "{ 1, 2, 3, 4}");
    REQUIRE(y.toStr() == "{ 1, 2, 3}");
}

#ifdef AU_DEBUG

TEST_CASE("destructor")
{
    {
        ListInt lst;
    }
    REQUIRE(ListInt::deleteCount == 2);
    
    {
        ListInt lst;
        lst.pushBack(1);
        lst.pushBack(2);
        lst.pushBack(3);
    }
    REQUIRE(ListInt::deleteCount == 5);
}

#endif


TEST_CASE("pushBack")
{
    ListInt lst;
    
    lst.pushBack(1);
    lst.pushBack(2);
    lst.pushBack(3);
    
    REQUIRE(lst.size() == 3);
    REQUIRE(lst.toStr() == "{ 1, 2, 3}");
}


TEST_CASE("Iter")
{
    ListInt lst;
    lst.pushBack(1);
    lst.pushBack(2);
    lst.pushBack(3);

    ListInt::Iter p = lst.begin();
    REQUIRE(*p == 1);
    ++p;
    REQUIRE(*p == 2);
    ++p;
    REQUIRE(*p == 3);
    ++p;
    REQUIRE(p == lst.end());
    --p;
    REQUIRE(*p == 3);
    --p;
    REQUIRE(*p == 2);
    --p;
    REQUIRE(*p == 1);
}

TEST_CASE("RIter")
{
    ListInt lst;
    lst.pushBack(1);
    lst.pushBack(2);
    lst.pushBack(3);

    ListInt::RIter p = lst.rbegin();
    REQUIRE(*p == 3);
    ++p;
    REQUIRE(*p == 2);
    ++p;
    REQUIRE(*p == 1);
    ++p;
    REQUIRE(p == lst.rend());
    --p;
    REQUIRE(*p == 1);
    --p;
    REQUIRE(*p == 2);
    --p;
    REQUIRE(*p == 3);
}

TEST_CASE("Erase")
{
    ListInt lst;
    lst.pushBack(1);
    lst.pushBack(2);
    lst.pushBack(3);
    
    auto p = lst.begin();
    ++p;
    p = lst.erase(p);
    REQUIRE(*p == 3);
    REQUIRE(lst.toStr() == "{ 1, 3}");
    p = lst.erase(p);
    REQUIRE(p == lst.end());
    REQUIRE(lst.toStr() == "{ 1}");
    --p;
    p = lst.erase(p);
    REQUIRE(p == lst.end());
    REQUIRE(p == lst.begin());
    REQUIRE(lst.toStr() == "{}");
}

TEST_CASE("Insert")
{
    ListInt lst;
    lst.pushBack(1);
    lst.pushBack(2);
    lst.pushBack(3);
    
    auto p = lst.begin();
    ++p;
    p = lst.insert(p, 0);
    REQUIRE(*p == 0);
    REQUIRE(lst.toStr() == "{ 1, 0, 2, 3}");
    --p;
    p = lst.insert(p, 10);
    REQUIRE(p == lst.begin());
    REQUIRE(lst.toStr() == "{ 10, 1, 0, 2, 3}");
}
