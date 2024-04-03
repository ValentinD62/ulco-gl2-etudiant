#include <todolist-cpp/Task.hpp>
#include <iostream>

std::string showTask(const Task& task){
    return std::to_string(task._id) + ". " + task._name;
}