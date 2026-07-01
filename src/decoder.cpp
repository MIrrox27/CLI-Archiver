// author github.com/MIrrox27/CLI-Archiver
// src/decoder.cpp


#include <fstream>
#include <string>
#include <vector>
#include <iostream>


std::vector<char> get_binary_archive(std::string path){
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


std::vector<unsigned char> decode_binary(std::vector<char> binary_archive){
  //for (unsigned char c : binary_archive) std::cout << static_cast<int>(c) << " ";
  std::cout << "Starting decode information..." << std::endl;
  std::vector<unsigned char> compressed;
  
  std::string str_AXA = "AXA";
  std::vector<unsigned char> AXA(str_AXA.begin(), str_AXA.end());
  
  for (int i = 0; i < AXA.size(); ++i){
    if (binary_archive[i] != AXA[i]){
      std::cerr << "Invalid archive" << std::endl;
      return {};
    }
  }
  int counter; 
  unsigned char bite;
  std::cout << std::endl << "\n - Encode bites: ";
  for (int i = AXA.size(); i < binary_archive.size(); i+=2){
    counter = static_cast<int>(static_cast<unsigned char>(binary_archive[i])); // первый байт всегда счетчик
    bite = binary_archive[i + 1]; // после уже сам символ
    std::cout << counter << " " << (int)bite << " " ;
    for (int j = 0; j < counter; ++j) compressed.push_back(bite);
  }
  std::cout <<"\n\n - Decode bites: ";
  for (unsigned char c : compressed) std::cout << static_cast<int>(c) << " ";
  
  std::cout << std::endl << "\nDecode information was ended" << std::endl;
  return compressed;
}



int wright_decode_to_file (std::vector<unsigned char> compressed, std::string name){
  std::cout << "Starting make file " << name << std::endl;
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
