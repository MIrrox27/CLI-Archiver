// author github.com/MIrrox27/CLI-Archiver
// src/main.cpp

#include <iostream>
#include <string>
#include <map> 
#include <functional>
#include <vector>
#include "encoder.hpp"

  // Скелеты функций
void encode_archive(std::string path);
void decode_archive(std::string path);


int main(int argc, char* argv[]) {
  using Callback = std::function<void(std::string)>; // Тип данных для функций

  std::map<std::string, Callback> tags;
  tags["-c"] = [](std::string path) { encode_archive(path); };
  tags["-d "] = [](std::string path) { decode_archive(path); };

  std::cout << argc << std::endl;
  std::cout << argv[1] << std::endl;
  std::cout << argv[2] << std::endl;
  std::cout << argv[3] << std::endl;
    
  std::string tag = argv[1];
  std::string path = argv[2];
  std::string archive_name = argv[3];
  
  if (tags.find(tag) != tags.end()) tags[tag](path);
  else std::cerr << "Invalid arg: " << tag << std::endl;
  
  
  std::cout << " -- Program ended without errors..." << std::endl;
  return 0;
}



void encode_archive(std::string path){ // функция для создания архива
  //std::vector<char> result = get_binary_file(path);
  std::cout << "encode_archive " << std::endl;
}; 

void decode_archive(std::string path){}; // функция для распаковки архива 