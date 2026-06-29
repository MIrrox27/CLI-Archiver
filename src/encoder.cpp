// author github.com/MIrrox27/CLI-Archiver
// src/encoder.cpp

#include <fstream>
#include <vector>
#include <iostream>

  // Получение бинарной информации из файла
std::vector<char> get_binary_file(std::string path) {

  std::ifstream file(path, std::ios::binary);
  if (!file.is_open()) {
    std::cerr << "Invalid path: " << path << std::endl;
    return {};
  }
  else {
    std::vector<char> binary_buffer((std::istreambuf_iterator<char>(file)),
                                  std::istreambuf_iterator<char>());
    file.close();
    return binary_buffer;
  }
}
