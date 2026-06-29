// author github.com/MIrrox27/CLI-Archiver
// src/main.cpp

#include <iostream>
#include <string>
#include <map> 
#include <functional>
#include "encoder.hpp"

  // Скелеты функций
void encode_archive(std::string path);
void decode_archive(std::string path);


int main() {
  using Callback = std::function<void(std::string)>; // Тип данных для функций

  std::map<std::string, Callback> tags;
  tags["-c"] = [](std::string path) { encode_archive(path); };
  tags["-d "] = [](std::string path) { decode_archive(path); };


  
  std::cout << " -- Pragramm ended without errors..." << std::endl;
  return 0;
}



void encode_archive(std::string path){}; // функция для создания архива
void decode_archive(std::string path){}; // функция для распаковки архива 