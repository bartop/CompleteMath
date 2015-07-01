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
		unsigned long long index { (size >= 2 * i) ? size - 2 * i : 0};
		unsigned char length { (size >= 2 * i) ? (unsigned char)2 : (unsigned char)1};
		sstream << std::hex << hexadecimal.substr(index, length);
		sstream >> array[i];
	}
}

void shiftArrayLeft(unsigned char *const toShift, const unsigned long long size){
	for(unsigned long long i = 0; i < size - 1; ++i){
		toShift[size - 1 - i] = toShift[size - 2 - i];
	}
	toShift[0] = 0;
}

unsigned char *const arraySubtract(const unsigned char *const left, const unsigned long long sizeLeft,
			const unsigned char *const right, const unsigned long long sizeRight){
	unsigned char *ptr = new unsigned char[sizeLeft]{};
	unsigned char borrow { 0 };
	for(unsigned long long i = 0; i < sizeRight; ++i){
		if((ptr[i] = left[i] - right[i] - borrow) > left[i]) borrow = 1;
		else borrow = 0;
	}
	unsigned long long j = sizeRight;
	while(borrow && j < sizeLeft){
		if((ptr[j] = left[j] - borrow) > left[j]) borrow = 1;
		else borrow = 0;
	}
	return ptr;
}

}
}
}
