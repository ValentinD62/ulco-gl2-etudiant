
#include "Board.hpp"
#include "ReportStdout.hpp"
#include "ReportFile.hpp"
#include "NumBoard.hpp"

void testBoard(Board & b) {
    std::cout << b.getTitle() << std::endl;
    b.add("item 1");
    b.add("item 2");
    b.add("item 2");

    //b.reportStdout();
    ReportStdout repstd;
    repstd.reportStdout(b);

    ReportFile repfile("tmp2.txt");
    repfile.reportFile(b);
}

void testNumBoard(NumBoard & b){
    std::cout << b.getTitle() << std::endl;
    b.ajout_num("item 1");
    b.ajout_num("item 4");
    b.ajout_num("item 2");
    b.ajout_num("item 2");

    ReportStdout repstd;
    repstd.reportStdout(b);

    ReportFile repfile("tmp3.txt");
    repfile.reportFile(b);
}

int main() {
    Board b1;
    testBoard(b1);

    NumBoard b2;
    testNumBoard(b2);
    
    return 0;
}

