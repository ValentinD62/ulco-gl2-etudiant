#pragma once

#include "Board.hpp"
#include <fstream>
#include <iostream>

class ReportFile{
    private:
        std::ofstream _ofs;
    public:
        ReportFile(const std::string & filename) : _ofs(filename){}

        void reportFile(const Board & _board) {
            for (const std::string & item : _board.getItems())
                _ofs << item << std::endl;
            _ofs << std::endl;
        }
};