#include <todolist-cpp/Board.hpp>

void Board::addTodo(std::string desc){
    Task t {_nextId, desc };
    auto it = _todo.begin();
    _todo.insert(it, t);
    _nextId ++;
}