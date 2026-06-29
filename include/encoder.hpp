// author github.com/MIrrox27/CLI-Archiver
// include/encoder.hpp

#ifndef ENCODER_HPP
#define ENCODER_HPP

#include <fstream>
#include <string>


std::vector<char> get_binary_file(std::string path);
std::vector<char> encode_binary(std::vector<char> binary_file);



#endif
