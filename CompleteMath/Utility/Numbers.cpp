/*
 * Numbers.cpp
 *
 *  Created on: 26 cze 2015
 *      Author: Bartosz Miera
 */

#include "Numbers.h"
#include <sstream>

namespace coma{
namespace util{
namespace numb{

unsigned char *const arrayFromHexadecimal(const std::string &hex){
	std::string tmp = hex;
	removeLeftTrailingZeroes(tmp);
	unsigned long long size = tmp.length() / 2 + tmp.length() % 2;
	unsigned char *array = new unsigned char[size]{};
	fillArrayfromHexadecimal(hex, array, size);
	return array;
}

const unsigned long long sizeFromHexadecimal(const std::string &hex){
	std::string tmp = hex;
	removeLeftTrailingZeroes(tmp);
	return tmp.length() / 2 + tmp.length() % 2;
}

void fillArrayfromHexadecimal(const std::string &hexadecimal, unsigned char *const array, const unsigned long long size){
	std::stringstream sstream { };
	for(unsigned long long i = 0; i < size; ++i){
		unsigned long long index {size >= 2 * i ? size - 2 * i : 0};
		unsigned char length { size >= 2 * i ? 2 : 1};
		sstream << std::hex << hexadecimal.substr(index, length);
		sstream >> array[i];
	}
}

}
}
}
