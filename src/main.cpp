// author github.com/MIrrox27/CLI-Archiver
// src/main.cpp

#include <iostream>
#include <string>
#include <map> 
#include <functional>
#include <vector>
#include "encoder.hpp"



void encode_archive(const std::vector<std::string>& args){ // функция для создания архива
  // args[0] - 
  // args[1] - 

  std::vector<char> result = get_binary_file(args[0]);
  std::cout << args[0] << " " << args[1] << " encode_archive" << std::endl;
}; 

void decode_archive(const std::vector<std::string>& args){}; // функция для распаковки архива 



int main(int argc, char* argv[]) {
  using Callback = std::function<void(std::vector<std::string>)>; // Тип данных для функций

  std::map<std::string, Callback> tags;
  tags["-c"] = encode_archive;
  tags["-d "] = decode_archive;

  std::cout << argc << std::endl;
  std::cout << argv[1] << std::endl;
  std::cout << argv[2] << std::endl;
  std::cout << argv[3] << std::endl;
    
  std::string tag = argv[1];
  std::string path = argv[2];
  std::string name = argv[3];
  

  std::vector<std::string> args = {path, name};
  if (tags.find(tag) != tags.end()) tags[tag](args);
  else std::cerr << "Invalid arg: " << tag << std::endl;
  
  
  std::cout << " -- Program ended without errors..." << std::endl;
  return 0;
}