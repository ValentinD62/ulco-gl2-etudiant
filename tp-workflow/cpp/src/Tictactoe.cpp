#include "Tictactoe.hpp"

Jeu::Jeu() {
    raz();
}

Status Jeu::getStatus() const {
    return _statut;
}

Cell Jeu::getCell(int i, int j) const {
    return _plateau[i][j];
}

std::ostream & operator<<(std::ostream & os, const Jeu & jeu) {
    for (int i = 0; i < 3; i ++){
        for (int j = 0; j < 3; j++){
            switch(jeu.getCell(i, j)){
                case Cell::Vide :
                    os << '.';
                    break;
                case Cell::Rouge:
                    os << 'R';
                    break;
                case Cell::Vert:
                    os << 'V';
                    break;
            }
        }
        os << std::endl;
    }
    return os;
}

bool Jeu::jouer(int i, int j) {
    if(getCell(i,j) == Cell::Vide && i <= 2 && j <= 2 && i >= 0 && j >= 0){
        switch (_statut)
        {
        case Status::RougeJoue:
            _plateau[i][j] = Cell::Rouge;
            break;
        case Status::VertJoue:
            _plateau[i][j] = Cell::Vert;
            break;
        default:
            return false;
        }
        return true;
    }
    else
        return false;
}

void Jeu::raz() {
    for (int i=0;  i < 3; i++){
        for (int j=0; j < 3; j++){
            _plateau[i][j] = Cell::Vide;
        }
    }
    _statut = Status::RougeJoue;
}

