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

void addArray(unsigned char *const toAdd1, const unsigned long long size1,
		const unsigned char *const toAdd2, const unsigned long long size2){
	unsigned char carry {0};
	for(unsigned long long i = 0; i < size2 || (carry == 1 && i < size1); ++i){
		if(i < size2){
			if(toAdd1[i] += toAdd2[i] < toAdd2[i]) carry = 1;
			else carry = 0;
		}
		if(toAdd1[i] += carry < carry) carry = 1;
		else carry = 0;
	}
}

void negateArray(unsigned char *const toNegate, const unsigned long long size){
	unsigned char one { 1 };
	for(unsigned long long i = 0; i < size; ++i){
		toNegate[i] = ~toNegate[i];
	}
	addArray(toNegate, size, &one, 1);
}

void subtractArray(unsigned char *const left, const unsigned long long sizeLeft,
			const unsigned char *const right, const unsigned long long sizeRight){
	unsigned char borrow {0};
	for(unsigned long long i = 0; i < sizeRight || (borrow == 1 && i < sizeLeft); ++i){
		if(i < sizeRight){
			if(left[i] -= right[i] > left[i]) borrow = 1;
			else borrow = 0;
		}
		if(left[i] -= borrow > left[i]) borrow = 1;
		else borrow = 0;
	}
}

const unsigned long long getUsedBytes(const unsigned char *const array, const unsigned long long maxSize, const bool negative){
	unsigned long long result { maxSize };
	unsigned char checkVal{ negative ? static_cast<unsigned char>(-1) : 0 };
	while(array[result - 1] == checkVal) --result;
	return result;
}

}
}
}
