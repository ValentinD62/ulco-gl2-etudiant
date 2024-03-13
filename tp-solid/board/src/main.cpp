
#include "Board.hpp"
#include "ReportStdout.hpp"
#include "ReportFile.hpp"
#include "NumBoard.hpp"
#include "Reportable.hpp"

void testBoard(Board & b, Reportable & rep) {
    std::cout << b.getTitle() << std::endl;
    b.add("item 1");
    b.add("item 2");
    b.add("item 2");
    rep.report(b);
}

void testNumBoard(NumBoard & b, Reportable & rep){
    std::cout << b.getTitle() << std::endl;
    b.ajout_num("item 1");
    b.ajout_num("item 4");
    b.ajout_num("item 2");
    b.ajout_num("item 2");
    rep.report(b);
}

int main() {
    ReportFile repfile("tmp3.txt");
    ReportStdout repstd;
    Board b1;
    testBoard(b1, repstd);

    NumBoard b2;
    testNumBoard(b2, repfile);
    
    return 0;
}

