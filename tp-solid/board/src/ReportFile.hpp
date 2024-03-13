#pragma once

#include "Board.hpp"
#include "Reportable.hpp"
#include <fstream>
#include <iostream>

class ReportFile : public Reportable{
    private:
        std::ofstream _ofs;
    public:
        ReportFile(const std::string & filename) : _ofs(filename){}

        void report(const Board & _board) override{
            for (const std::string & item : _board.getItems())
                _ofs << item << std::endl;
            _ofs << std::endl;
        }
};