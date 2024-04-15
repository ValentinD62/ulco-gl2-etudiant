#include "Tictactoe.hpp"
#include <sstream>

#include <catch2/catch.hpp>

TEST_CASE("test getCell vide") { 
    Jeu jeu;
    REQUIRE(jeu.getCell(0, 1) == Cell::Vide);
}

TEST_CASE("test statut de base") { 
    Jeu jeu;
    REQUIRE(jeu.getStatus() == Status::RougeJoue);
}

TEST_CASE("test affichage grille vide") { 
    Jeu jeu;
    std::stringstream out;
    out << jeu;
    REQUIRE(out.str() == "...\n...\n...\n");
}

TEST_CASE("jouer 0 1"){
    Jeu jeu;
    REQUIRE(jeu.jouer(0, 1) == true);
    REQUIRE(jeu.getCell(0,1) == Cell::Rouge);
}

TEST_CASE("jouer mauvais"){
    Jeu jeu;
    REQUIRE(jeu.jouer(5, 5) == false);
}

TEST_CASE("jouer plusieurs fois sur la même case"){
    Jeu jeu;
    REQUIRE(jeu.jouer(0, 1) == true);
    REQUIRE(jeu.jouer(0, 1) == false);
}

TEST_CASE("Victoire rouge"){
    Jeu jeu;
    jeu.jouer(0, 0);
    jeu.jouer(1, 1);
    jeu.jouer(1, 0);
    jeu.jouer(1, 2);
    jeu.jouer(2, 0);
    REQUIRE(jeu.getStatus() == Status::RougeGagne);
}

TEST_CASE("Victoire verte"){
    Jeu jeu;
    jeu.jouer(0, 0);
    jeu.jouer(1, 1);
    jeu.jouer(0, 1);
    jeu.jouer(1, 0);
    jeu.jouer(2, 2);
    jeu.jouer(1, 2);
    std::cout << jeu;
    REQUIRE(jeu.getStatus() == Status::VertGagne);
}