/*
 * Integer.cpp
 *
 *  Created on: 26 cze 2015
 *      Author: Bartosz Miera
 */

#include "Integer.h"
#include "FloatingPoint.h"
#include "../Utility/Numbers.h"
#include <algorithm>
#include <memory>

namespace coma{
namespace numb{

const unsigned char *const Integer::arrayCopy(const unsigned char *const toCopy,
		const unsigned long long size,
		const Endianess endianess){
	if(size == 0 || toCopy == nullptr) throw 1;//TODO exceptions
	unsigned char *copy = new unsigned char[size]{};
	if(endianess == Endianess::Little){
		std::copy(toCopy, toCopy+size, copy);
	}else if(endianess == Endianess::Big){
		std::copy(std::reverse_iterator<const unsigned char *>(toCopy + size),
				std::reverse_iterator<const unsigned char *>(toCopy),
				copy);
	}
	return copy;
}

Integer::Integer(const unsigned char *const numbersArray,
		const unsigned long long arrayLength,
		const Endianess endianess):
		m_size { arrayLength },
		m_integer{ arrayCopy(numbersArray, arrayLength, endianess) }{}

const unsigned long long Integer::getArraySize() const{
	return m_size;
}

const unsigned char *const Integer::getArray() const{
	return m_integer;
}

Integer::~Integer(){
	if(m_integer) delete[] m_integer;
}

}/* namespace numb */
} /* namespace coma */
