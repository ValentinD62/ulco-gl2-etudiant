#include <todolist-cpp/Board.hpp>

#include <catch2/catch.hpp>

TEST_CASE( "test board" ) {
    Board b;
    b.addTodo("TODO");
    auto it = b._todo.begin();
    REQUIRE( it->_name == "TODO" );
}

