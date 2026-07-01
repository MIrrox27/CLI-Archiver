// author github.com/MIrrox27/CLI-Archiver
// include/decoder.hpp

#ifndef DECODER_HPP
#define DECODER_HPP

#include <string>
#include <vector>


std::vector<char> get_binary_archive(std::string path);
std::vector<unsigned char> decode_binary(std::vector<char> binary);
int wright_decode_to_file (std::vector<unsigned char> compressed, std::string name);


#endif