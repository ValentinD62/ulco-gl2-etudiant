#include <todolist-cpp/View.hpp>

#include <catch2/catch.hpp>

TEST_CASE( "test view" ) {
    Task t {1, "TODO"};
    std::string res = showTask(t);
    REQUIRE( res == "1. TODO" );
}

TEST_CASE( "test view board" ) {
    Board b;
    b.addTodo("TODO");
    std::string res = printBoard(b);
    std::string normal = "Todo:\n1. TODO\n\n Done:\n";
    REQUIRE( res == normal );
}