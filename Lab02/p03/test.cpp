#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"

#include "BSTreeInt.h"

TEST_CASE("Constructor")
{
    BSTreeInt tree;
    
    REQUIRE(tree.size() == 0);
}

TEST_CASE("Insert")
{
    BSTreeInt tree;
    
    tree.insert(50);
    REQUIRE(tree.size() == 1);
    REQUIRE(tree.path == "");
    
    tree.insert(23);
    REQUIRE(tree.size() == 2);
    REQUIRE(tree.path == "L");
    
    tree.insert(74);
    REQUIRE(tree.size() == 3);
    REQUIRE(tree.path == "R");
    
    tree.insert(80);
    REQUIRE(tree.size() == 4);
    REQUIRE(tree.path == "RR");
    
    
    REQUIRE_FALSE(tree.insert(50));
}

TEST_CASE("Find")
{
    BSTreeInt tree;
    tree.insert(50);
    tree.insert(25);
    tree.insert(70);
    tree.insert(15);
    tree.insert(40);
    tree.insert(60);
    tree.insert(90);
    
    REQUIRE(tree.find(50));
    REQUIRE(tree.find(25));
    REQUIRE(tree.find(15));
    REQUIRE(tree.find(40));
    REQUIRE(tree.find(70));
    REQUIRE(tree.find(60));
    REQUIRE(tree.find(90));
    REQUIRE_FALSE(tree.find(100));
    REQUIRE_FALSE(tree.find(1));
    REQUIRE_FALSE(tree.find(0));
    REQUIRE_FALSE(tree.find(65));
}

TEST_CASE("Erase")
{
    BSTreeInt tree;
    
    SECTION("Erase only existing element")
    {
        tree.insert(50);
        REQUIRE(tree.erase(50));
    }
    
    SECTION("Erase leaf")
    {
        tree.insert(50);
        tree.insert(25);
        tree.insert(70);
        tree.insert(15);
        tree.insert(40);
        tree.insert(60);
        tree.insert(90);
        REQUIRE(tree.erase(15));
    }
    
    SECTION("Erase node with one child")
    {
        SECTION("Erase root 1")
        {
            tree.insert(50);
            tree.insert(70);
            tree.insert(90);
            
            REQUIRE(tree.erase(50));
            REQUIRE(tree.find(70));
            REQUIRE(tree.path == "");
            REQUIRE(tree.find(90));
            REQUIRE(tree.path == "R");
        }
        
        SECTION("Erase root 2")
        {
            tree.insert(50);
            tree.insert(30);
            tree.insert(10);
            
            REQUIRE(tree.erase(50));
            REQUIRE(tree.find(30));
            REQUIRE(tree.path == "");
            REQUIRE(tree.find(10));
            REQUIRE(tree.path == "L");
        }
        
        SECTION("Erase regular node")
        {
            tree.insert(50);
            tree.insert(30);
            tree.insert(60);
            tree.insert(70);
            
            REQUIRE(tree.erase(60));
        }
    }
    
    SECTION("Erase node with two children")
    {
        tree.insert(50);
        tree.insert(25);
        tree.insert(70);
        tree.insert(15);
        tree.insert(40);
        tree.insert(60);
        tree.insert(90);
        
        SECTION("Erase root")
        {
            REQUIRE(tree.erase(50));
            REQUIRE(tree.find(40));
            REQUIRE(tree.path == "");
        }
        
        SECTION("Erase regular node")
        {
            REQUIRE(tree.erase(70));
            REQUIRE(tree.find(60));
            REQUIRE(tree.path == "R");
        }
        
    }
}

TEST_CASE("toStr")
{
    BSTreeInt tree;
    REQUIRE(tree.toStr() == "");
    
    tree.insert(50);
    tree.insert(25);
    tree.insert(70);
    tree.insert(15);
    tree.insert(40);
    tree.insert(60);
    tree.insert(90);
    
    REQUIRE(tree.toStr() == " 15 25 40 50 60 70 90");   
}