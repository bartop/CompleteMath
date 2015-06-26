/*
 * Integer.cpp
 *
 *  Created on: 26 cze 2015
 *      Author: Bartosz Miera
 */

#include "Integer.h"
#include <algorithm>

namespace cm{
namespace numb{

	const unsigned char *const Integer::arrayCopy(const unsigned char *const toCopy, const unsigned long long size){
		unsigned char *copy = new unsigned char[size]{};
		std::copy(toCopy, toCopy+size, copy);
		return copy;
	}

	Integer::Integer(const unsigned char *const numbersArray, const unsigned long long arrayLength):
		m_size(arrayLength),
		m_integer(arrayCopy(numbersArray, arrayLength)){}

	const unsigned long long Integer::getArraySize() const{
		return m_size;
	}

	const unsigned char *const Integer::getArray() const{
		return m_integer;
	}

	Integer::~Integer(){
		delete[] m_integer;
	}

}/* namespace numb */
} /* namespace cm */
