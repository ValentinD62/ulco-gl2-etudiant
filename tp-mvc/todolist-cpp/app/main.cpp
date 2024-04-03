#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/View.hpp>
#include <todolist-cpp/Board.hpp>

#include <iostream>
#include <sstream>

int main() {
    Board b;
    std::string x, cmd, rst;
    while (x != "quit"){
        std::string msg = printBoard(b);
        std::cout << msg << std::endl;
        std::getline(std::cin, x);
        std::istringstream iss(x);
        std::getline(iss, cmd, ' ');
        std::getline(iss, rst);
        if (cmd == "add" and rst != ""){
            b.addTodo(rst);
        }
        else if (cmd == "done" and rst != ""){
            try{
                b.toDone(std::stoi(rst));
            }
            catch(std::exception e){
                std::cout << "Erreur" << std::endl;
                break;
            }
            
        }
        else{
            std::cout << "Erreur" << std::endl;
            break;
        }
    }
    
    return 0;
}