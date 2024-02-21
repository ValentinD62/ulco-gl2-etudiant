#include "Logger.hpp"

#include <algorithm>
#include <iomanip>
#include <map>
#include <sstream>
#include <ctime>

void Logger::addItem(Level l, const std::string & m) {
  std::time_t t = std::time(nullptr);
  std::tm* now = std::localtime(&t);
  char buffer[128];
  strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", now);
  std::tuple tuple1 = {l, m, buffer};
  this->_items.push_back(tuple1);
}

std::string Logger::reportByAdded() const {
  std::string texte = "**** report_by_added ****\n";
  for(const std::tuple t : _items){
    if(std::get<0>(t) == Level::Info){
      texte += std::get<2>(t) + " [I] " + std::get<1>(t) + " \n";  
    }
    if(std::get<0>(t) == Level::Warning){
      texte += std::get<2>(t) + " [W] " + std::get<1>(t) + " \n";  
    }
    if(std::get<0>(t) == Level::Error){
      texte += std::get<2>(t) + " [E] " + std::get<1>(t) + " \n";  
    }
  }
  return texte;
}

std::string Logger::reportByLevel() const {
  std::string texte = "**** report_by_level ****\n";
  for(const std::tuple t : _items){
    if(std::get<0>(t) == Level::Info){
      texte += std::get<2>(t) + " [I] " + std::get<1>(t) + " \n";  
    }
  }
  for(const std::tuple t : _items){
    if(std::get<0>(t) == Level::Warning){
          texte += std::get<2>(t) + " [W] " + std::get<1>(t) + " \n";  
    }
  }
  for(const std::tuple t : _items){
    if(std::get<0>(t) == Level::Error){
      texte += std::get<2>(t) + " [E] " + std::get<1>(t) + " \n";  
    }
  }
  return texte;
}

