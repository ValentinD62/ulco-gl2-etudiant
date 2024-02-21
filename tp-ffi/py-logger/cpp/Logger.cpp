#include "Logger.hpp"

#include <algorithm>
#include <iomanip>
#include <map>
#include <sstream>

void Logger::addItem(Level l, const std::string & m) {
  std::tuple tuple1 = {l, m};
  this->_items.push_back(tuple1);
}

std::string Logger::reportByAdded() const {
  std::string texte = "**** report_by_added ****\n";
  for(const std::tuple t : _items){
    if(std::get<0>(t) == Level::Info){
      texte += "[I] " + std::get<1>(t) + " \n";  
    }
    if(std::get<0>(t) == Level::Warning){
      texte += "[W] " + std::get<1>(t) + " \n";  
    }
    if(std::get<0>(t) == Level::Error){
      texte += "[E] " + std::get<1>(t) + " \n";  
    }
  }
  return texte;
}

std::string Logger::reportByLevel() const {
  std::string texte = "**** report_by_level ****\n";
  for(const std::tuple t : _items){
    if(std::get<0>(t) == Level::Info){
      texte += "[I] " + std::get<1>(t) + " \n";  
    }
  }
  for(const std::tuple t : _items){
    if(std::get<0>(t) == Level::Warning){
          texte += "[W] " + std::get<1>(t) + " \n";  
    }
  }
  for(const std::tuple t : _items){
    if(std::get<0>(t) == Level::Error){
      texte += "[E] " + std::get<1>(t) + " \n";  
    }
  }
  return texte;
}

