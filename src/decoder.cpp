// author github.com/MIrrox27/CLI-Archiver
// src/decoder.cpp


#include <fstream>
#include <string>
#include <vector>
#include <iostream>


std::vector<char> get_encode_file(std::string path){
  std::cout << "Open archive " << path << std::endl;

  std::ifstream file(path, std::ios::binary);
  if (!file.is_open()) {
    std::cerr << "Invalid path: " << path << std::endl;
    return {};
  }
  else {
    std::vector<char> binary_buffer((std::istreambuf_iterator<char>(file)),
                                  std::istreambuf_iterator<char>());
    file.close();
    std::cout << "Got binary info" << std::endl;
    return binary_buffer;
  }

}




std::vector<unsigned char> decode_binary(std::vector<char> binary);
int wright_decode_to_file (std::vector<unsigned char> compressed, std::string name);
