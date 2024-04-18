#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include <array>
#include <iostream>

enum class Status { Egalite, RougeGagne, VertGagne, RougeJoue, VertJoue };

enum class Cell { Vide, Rouge, Vert };

/// Moteur de jeu de tictactoe.
class Jeu {
    private:
        std::array<std::array<Cell, 3>, 3> _plateau;
        Status _statut;

    public:
        /// \brief Constructeur à utiliser.
        Jeu();

        /// \brief Retourne le status du jeu courant (Egalite, RougeGagne, VertGagne, RougeJoue, VertJoue).
        Status getStatus() const;

        /// \brief Retourne l'état d'une case du plateau
        /// @param i : int (entre 0 et 2)
        /// @param j : int (entre 0 et 2)
        Cell getCell(int i, int j) const;

        /// \brief Vois si il y a une victoire.
        void victoire();


        /// \brief Joue un coup pour le joueur courant.
        /// 
        /// @param i ligne choisie (0, 1 ou 2)
        /// @param j colonne choisie (0, 1 ou 2)
        /// 
        /// Si le coup est invalide, retourne false. Si le coup est valide,
        /// joue le coup et retourne true.
        bool jouer(int i, int j);

        /// \brief Réinitialise le jeu.
        void raz();
};

std::ostream & operator<<(std::ostream & os, const Jeu & jeu);

#endif

