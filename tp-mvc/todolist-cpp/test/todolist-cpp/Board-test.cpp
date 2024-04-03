#include <todolist-cpp/Board.hpp>

#include <catch2/catch.hpp>

TEST_CASE( "test board" ) {
    Board b;
    b.addTodo("TODO");
    auto it = b._todo.begin();
    REQUIRE( it->_name == "TODO" );
}

TEST_CASE( "test board done" ) {
    Board b;
    b.addTodo("TODO");
    b.addTodo("TODI");
    b.addTodo("TODU");
    b.toDone(2);
    auto it = b._done.begin();
    REQUIRE( it->_name == "TODI" );
}