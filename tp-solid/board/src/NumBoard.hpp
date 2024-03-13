#pragma once

#include "Board.hpp"
#include <fstream>
#include <iostream>

class NumBoard: public Board{
    private:
        int _add_num = 0;
    public:
        NumBoard()=default;
        void ajout_num(const std::string & t) {
            _add_num ++;
            std::string msg = std::to_string(_add_num) + ". " + t;
            add(msg);
        }

        std::string getTitle(){
            return "NumBoard";
        }
};