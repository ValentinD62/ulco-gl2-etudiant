#include "Tictactoe.hpp"

using namespace std;
/// @brief Permet de jouer au clavier
/// @return void
int main() {
    Jeu jeu;
    while (jeu.getStatus() != Status::Egalite && jeu.getStatus() != Status::RougeGagne && jeu.getStatus() != Status::VertGagne){
        cout << jeu;
        string ligne = "";
        string i = "";
        string j = "";
        switch (jeu.getStatus()){
            case Status::VertJoue:
            case Status::RougeJoue:
                if(jeu.getStatus() == Status::RougeJoue){
                    cout << "rouge joue" << endl;
                }
                else{
                    cout << "vert joue" << endl;
                }
                
                cout << "Entrer un coup (i, j) : ";
                getline(cin, ligne);
                try {
                    size_t pos = ligne.find(' ');
                    i = ligne.substr(0, pos);
                    j = ligne.substr(pos+1);
                    jeu.jouer(stoi(i), stoi(j));
                }
                catch (exception e){
                    cout << "Erreur de saisie" << endl;
                }
                break;
            default:
                break;
        }
    }
    if(jeu.getStatus() == Status::RougeGagne){
        cout << "Les rouges ont gagnés !" << endl;
    }
    else if (jeu.getStatus() == Status::VertGagne){
        cout << "Les verts ont gagnés ! " << endl;
    }
    cout << jeu;
    cout << "Partie terminée !" << endl;
    
    return 0;
}

