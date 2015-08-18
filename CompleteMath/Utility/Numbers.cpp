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

unsigned char *arrayFromHexadecimal(const std::string &hex){
	std::string tempCopy = hex;
	removeLeftTrailingZeroes(tempCopy);
	unsigned long long size = tempCopy.length() / 2 + tempCopy.length() % 2;
	unsigned char *array = new unsigned char[size]{};
	fillArrayfromHexadecimal(tempCopy, array, size);
	return array;
}

unsigned char *arrayFromSignedHexadecimal(const std::string &hex){
	std::string tempCopy = hex.substr(1, hex.length() - 1);
	removeLeftTrailingZeroes(tempCopy);
	unsigned long long size = sizeFromSignedHexadecimal(hex);
	unsigned char *array = new unsigned char[size]{};
	fillArrayfromHexadecimal(tempCopy, array, tempCopy.length() / 2 + tempCopy.length() % 2);
	if(hex[0] == '-'){
		util::numb::negateArray(array, size);
	}
	return array;
}

const unsigned long long sizeFromHexadecimal(const std::string &hex){
	std::string tmp = hex;
	removeLeftTrailingZeroes(tmp);
	return tmp.length() / 2 + tmp.length() % 2;
}

const unsigned long long sizeFromSignedHexadecimal(const std::string &hex){
	std::string tempCopy = hex.substr(1, hex.length() - 1);
	removeLeftTrailingZeroes(tempCopy);
	unsigned long long size = tempCopy.length() / 2 + tempCopy.length() % 2;
	if ( !(tempCopy.length() % 2) && tempCopy[0] > '8') ++size;
	return size;
}

void fillArrayfromHexadecimal(const std::string &hexadecimal, unsigned char *array, const unsigned long long size){
	std::stringstream sstream { };
	sstream.exceptions(std::stringstream::eofbit | std::stringstream::badbit);
	for(unsigned long long i = 0; i < size; ++i){
		unsigned long long index { (hexadecimal.length() % 2 && i != 0) ? 2 * i - 1 : 2 * i };
		unsigned int tmp {};
		unsigned char length { (hexadecimal.length() % 2 && i == 0) ? (unsigned char)1 : (unsigned char)2 };
		std::string substring = hexadecimal.substr(index, length);
		util::numb::removeLeftTrailingZeroes(substring);
		sstream << std::hex << substring << std::endl;
		sstream >> tmp;
		array[size - 1 - i] = tmp;
	}
}

void shiftArrayLeft(unsigned char *toShift, const unsigned long long size){
	for(unsigned long long i = 0; i < size - 1; ++i){
		toShift[size - 1 - i] = toShift[size - 2 - i];
	}
	toShift[0] = 0;
}

void addArray(unsigned char *toAdd1, const unsigned long long size1,
		const unsigned char *toAdd2, const unsigned long long size2){
	unsigned char carry {0};
	for(unsigned long long i = 0; i < size2 || (carry == 1 && i < size1); ++i){
		if(i < size2) addWithCarry(toAdd1[i], toAdd2[i], carry);
		else addWithCarry(toAdd1[i], 0, carry);
	}
}

void negateArray(unsigned char *toNegate, const unsigned long long size){
	unsigned char one { 1 };
	for(unsigned long long i = 0; i < size; ++i){
		toNegate[i] = ~toNegate[i];
	}
	addArray(toNegate, size, &one, 1);
}


}
}
}
