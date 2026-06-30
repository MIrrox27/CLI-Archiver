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


std::vector<unsigned char> encode_binary(std::vector<char> binary_file){
  for (unsigned char c : binary_file) std::cout << static_cast<int>(c) << " ";
  std::cout << " " << std::endl << std::endl << std::endl;
  std::vector<unsigned char> compressed;

  // Надо записать первые 3 байта своими символами, чтобы понимать что этот архив мой
  std::string AXA = "AXA";
  for (char c : AXA) compressed.push_back(static_cast<unsigned char>(c));


  unsigned char current_bite = static_cast<unsigned char>(binary_file[0]);
  int counter = 1;

  for (int i = 1; i < binary_file.size(); ++i){
    unsigned char bite = static_cast<unsigned char>(binary_file[i]);
    if (bite == current_bite && counter < 256) { // если байт совпадает с пердыдущим увеличиваем счетчик 
      counter++;
    }
    else { // записываем в compressed байты в формате "счетчик байт" и обнуляем счетчик 
      compressed.push_back(static_cast<unsigned char>(counter));
      compressed.push_back(current_bite);
      counter = 1;
    }
    current_bite = bite;
  }
  compressed.push_back(static_cast<unsigned char>(counter));
  compressed.push_back(current_bite);

  for (unsigned char c : compressed) std::cout << static_cast<int>(c) << " ";

  return compressed; // сжатый архив 

}