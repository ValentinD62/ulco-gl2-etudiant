#pragma once

#include "Itemable.hpp"
#include "Titleable.hpp"
#include <fstream>
#include <iostream>

class Board : public Titleable, public Itemable{
    private:
        std::vector<std::string> _tasks;

    public:
        Board()=default;

        void add(const std::string & t) {
            _tasks.push_back(t);
        }

        std::vector<std::string> getItems() const override{
            return _tasks;
        }

        virtual std::string getTitle() const override {
            return "Board";
        }
};

