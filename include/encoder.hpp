// author github.com/MIrrox27/CLI-Archiver
// include/encoder.hpp

#ifndef ENCODER_HPP
#define ENCODER_HPP

#include <string>
#include <vector>


std::vector<char> get_binary_file(std::string path);
std::vector<unsigned char> encode_binary(std::vector<char> binary_file);
int wright_encode_to_file(std::vector<unsigned char> compressed, std::string name);



#endif
