#include <todolist-cpp/View.hpp>
#include <iostream>

std::string showTask(const Task& task){
    return std::to_string(task._id) + ". " + task._name;
}

std::string printBoard(const Board& b){
    std::string msg = "Todo:\n";
    for (auto it : b._todo){
        msg = msg + showTask(it) + "\n";
    }
    msg += "\n Done:\n";
    for (auto it : b._done){
        msg = msg + showTask(it) + "\n";
    }
    return msg;
}