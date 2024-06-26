#include "Tictactoe.hpp"
#include <memory>

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

void Jeu::victoire(){
    int ok = 0;
    for (int i = 0; i < 3; i++){
        //Vérif ligne.
        if(_plateau[i][0] == _plateau[i][1] && _plateau[i][0] == _plateau[i][2]){
            if(_plateau[i][0] == Cell::Rouge){
                _statut = Status::RougeGagne;
                ok = 1;
            }
            else if (_plateau[i][0] == Cell::Vert){
                _statut = Status::VertGagne;
                ok = 1;
            }
        }
        //Vérif colonne.
        if(_plateau[0][i] == _plateau[1][i] && _plateau[0][i] == _plateau[2][i]){
            if(_plateau[0][i] == Cell::Rouge){
                _statut = Status::RougeGagne;
                ok = 1;
            }
            else if (_plateau[0][i] == Cell::Vert){
                _statut = Status::VertGagne;
                ok = 1;
            }
        }
    }
    //Vérif diag 1.
    if(_plateau[0][0] == _plateau[1][1] && _plateau[0][0] == _plateau[2][2]){
        if(_plateau[0][0] == Cell::Rouge){
                _statut = Status::RougeGagne;
                ok = 1;
        }
        else if (_plateau[0][0] == Cell::Vert){
            _statut = Status::VertGagne;
            ok = 1;
        }
    }
    //Vérif diag 2.
    if(_plateau[0][2] == _plateau[1][1] && _plateau[0][2] == _plateau[2][0]){
        if(_plateau[0][2] == Cell::Rouge){
            _statut = Status::RougeGagne;
            ok = 1;
        }
        else if (_plateau[0][2] == Cell::Vert){
            _statut = Status::VertGagne;
            ok = 1;
        }
    }
    if(ok == 0){//Si il n'y a pas de victoires.
    int vide = 0;
        for (int i=0;  i < 3; i++){
            for (int j=0; j < 3; j++){
                if(_plateau[i][j] == Cell::Vide){
                    vide = 1;
                }
            }
            if(vide == 0){
                _statut = Status::Egalite;
            }
        }
    }
}

bool Jeu::jouer(int i, int j) {
    if(getCell(i,j) == Cell::Vide && i <= 2 && j <= 2 && i >= 0 && j >= 0){
        switch (_statut)
        {
        case Status::RougeJoue:
            _plateau[i][j] = Cell::Rouge;
            _statut = Status::VertJoue;
            break;
        case Status::VertJoue:
            _plateau[i][j] = Cell::Vert;
            _statut = Status::RougeJoue;
            break;
        default:
            return false;
        }
        victoire();
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

