#include "Board.hpp"

#include <stdexcept>


Board::Board() : Board(0, 0)
{}

Board::Board(int i, int j) : 
    _i(i),
    _j(j),
    _board({
        row_t {Cell::Free, Cell::Free, Cell::Free, Cell::Free, Cell::Free, Cell::Free, Cell::Free, Cell::Wall, Cell::Wall, Cell::Free},
        row_t {Cell::Wall, Cell::Wall, Cell::Wall, Cell::Free, Cell::Wall, Cell::Wall, Cell::Free, Cell::Wall, Cell::Wall, Cell::Free},
        row_t {Cell::Free, Cell::Wall, Cell::Free, Cell::Free, Cell::Free, Cell::Free, Cell::Free, Cell::Free, Cell::Free, Cell::Free},
        row_t {Cell::Free, Cell::Wall, Cell::Free, Cell::Wall, Cell::Wall, Cell::Free, Cell::Wall, Cell::Wall, Cell::Free, Cell::Wall},
        row_t {Cell::Free, Cell::Wall, Cell::Free, Cell::Free, Cell::Wall, Cell::Wall, Cell::Wall, Cell::Free, Cell::Free, Cell::Free},
        row_t {Cell::Free, Cell::Free, Cell::Free, Cell::Wall, Cell::Wall, Cell::Goal, Cell::Free, Cell::Free, Cell::Wall, Cell::Wall},
        row_t {Cell::Free, Cell::Wall, Cell::Free, Cell::Wall, Cell::Wall, Cell::Wall, Cell::Wall, Cell::Free, Cell::Free, Cell::Free},
        row_t {Cell::Free, Cell::Wall, Cell::Free, Cell::Free, Cell::Wall, Cell::Free, Cell::Wall, Cell::Free, Cell::Wall, Cell::Free},
        row_t {Cell::Free, Cell::Wall, Cell::Wall, Cell::Free, Cell::Wall, Cell::Free, Cell::Free, Cell::Free, Cell::Wall, Cell::Free},
        row_t {Cell::Free, Cell::Goal, Cell::Free, Cell::Free, Cell::Wall, Cell::Wall, Cell::Wall, Cell::Wall, Cell::Wall, Cell::Free}
    })
{}

int Board::getI() const {
    return _i;
}

int Board::getJ() const {
    return _j;
}

Cell Board::operator()(int i, int j) const {
    if (i<0 or i>9 or j<0 or j>9)
        throw std::invalid_argument("invalid index");
    return _board[i][j];
}

void Board::tryGoLeft() {
    if(_board[_i][_j-1] == Cell::Free && _j-1 >= 0){
        _j--;
    }
}

void Board::tryGoRight() {
    if(_board[_i][_j+1] == Cell::Free && _j+1 <= 9){
        _j++;
    }
}
void Board::tryGoUp() {
    if(_board[_i+1][_j] == Cell::Free && _i+1 <= 9){
        _i++;
    }
}
void Board::tryGoDown() {
    if(_board[_i-1][_j] == Cell::Free && _i-1 >= 0){
        _i--;
    }
}