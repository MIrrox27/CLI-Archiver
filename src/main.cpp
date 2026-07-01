// author github.com/MIrrox27/CLI-Archiver
// src/main.cpp

#include <iostream>
#include <string>
#include <map> 
#include <functional>
#include <vector>
#include "encoder.hpp"
#include "decoder.hpp"


  // скелеты функций
void encode_archive(const std::vector<std::string>& args);
void decode_archive(const std::vector<std::string>& args);



int main(int argc, char* argv[]) {
  std::cout << " -- Author https://github.com/MIrrox27/CLI-Archiver --\n -- Thank you for using my project -- \n" << std::endl;

  using Callback = std::function<void(std::vector<std::string>)>; // Тип данных для функций

  std::map<std::string, Callback> tags;
  tags["-c"] = encode_archive;
  tags["-d"] = decode_archive;

  std::cout << "Got arguments: " << argc << std::endl;
  std::cout << "Command: " << argv[0];
  std::cout << " " << argv[1];
  std::cout << " " << argv[2];
  std::cout << " " << argv[3] << std::endl;
    
  std::string tag = argv[1];
  std::string path = argv[2];
  std::string name = argv[3];
  

  std::vector<std::string> args = {path, name};
  if (tags.find(tag) != tags.end()) tags[tag](args);
  else std::cerr << "Invalid arg: " << tag << std::endl;

  return 0;
}



void encode_archive(const std::vector<std::string>& args){ // функция для создания архива
  // args[0] - path
  // args[1] - new_name

  std::vector<char> binary_file = get_binary_file(args[0]);
  if (binary_file.empty()) return;
  std::vector<unsigned char> encode_bites = encode_binary(binary_file);
  int write_archive = wright_encode_to_archive(encode_bites, args[1]+".archive");

  if (write_archive != 0) 
    std::cerr << "Error with make archive" << std::endl;
  else {
    std::cout << "Building complete! File: " << args[1]+".archive" << std::endl;
    std::cout << " -- Program ended without errors..." << std::endl;
  }
}; 



void decode_archive(const std::vector<std::string>& args){
  // args[0] - path
  // args[1] - new_name (for file)

  std::vector<char> binary_archive = get_binary_archive(args[0]);
  if (binary_archive.empty()) return;
  std::vector<unsigned char> decode_bites = decode_binary(binary_archive);
  int write_file = wright_decode_to_file(decode_bites, args[1]);

  if (write_file != 0) 
    std::cerr << "Error with make archive" << std::endl;
  else {
    std::cout << "Building complete! File: " << args[1]+".archive" << std::endl;
    std::cout << " -- Program ended without errors..." << std::endl;
  }



}; // функция для распаковки архива 
