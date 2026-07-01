// author github.com/MIrrox27/CLI-Archiver
// src/encoder.cpp

#include <fstream>
#include <vector>
#include <iostream>

  // Получение бинарной информации из файла
std::vector<char> get_binary_file(std::string path) {
  std::cout << "Open " << path << std::endl;

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


std::vector<unsigned char> encode_binary(std::vector<char> binary_file){
  //for (unsigned char c : binary_file) std::cout << static_cast<int>(c) << " ";
  std::cout << "Starting encode information..." << std::endl;
  std::vector<unsigned char> compressed;

  // Надо записать первые 3 байта своими символами, чтобы понимать что этот архив мой
  std::string AXA = "AXA";
  for (char c : AXA) compressed.push_back(static_cast<unsigned char>(c));


  unsigned char current_bite = static_cast<unsigned char>(binary_file[0]);
  int counter = 1;

  for (int i = 1; i < binary_file.size(); ++i){
    unsigned char bite = static_cast<unsigned char>(binary_file[i]);
    if (bite == current_bite && counter < 255) { // если байт совпадает с пердыдущим увеличиваем счетчик 
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
  std::cout << "Encode information was ended" << std::endl;
  return compressed; // сжатый архив 

}

int wright_encode_to_archive(std::vector<unsigned char> compressed, std::string name){
  std::cout << "Starting make archive..." << std::endl;
  std::ofstream out_file(name, std::ios::out | std::ios::binary);

  if (!out_file) {
    std::cerr << "Error opened file" << std::endl;
    return 1;
  }

  if (!compressed.empty()) 
    out_file.write(reinterpret_cast<const char*>(compressed.data()), 
                                                  compressed.size());
  
  out_file.close();
  return 0;
}
