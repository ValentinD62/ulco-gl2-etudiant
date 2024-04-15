#include "Tictactoe.hpp"
#include <sstream>

#include <catch2/catch.hpp>

TEST_CASE("test getCell vide") { 
    Jeu jeu;
    REQUIRE(jeu.getCell(0, 1) == Cell::Vide);
}

TEST_CASE("test affichage grille vide") { 
    Jeu jeu;
    std::stringstream out;
    out << jeu;
    REQUIRE(out.str() == "...\n...\n...\n");
}