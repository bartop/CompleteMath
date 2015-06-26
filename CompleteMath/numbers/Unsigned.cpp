/*
 * Unsigned.cpp
 *
 *  Created on: 24 cze 2015
 *      Author: Bartosz Miera
 */

#include "Unsigned.h"

namespace cm {
namespace numb {

	Unsigned::Unsigned(const NumberInString &decimalInString){}

	Unsigned::Unsigned(const unsigned char *const numbersArray, const unsigned long long arrayLength, const Endianess endianess) :
			Integer(numbersArray, arrayLength, endianess){}

	Unsigned *const Unsigned::fromBigEndianArray(const unsigned char *const numbersArray, const unsigned long long arrayLength){
	return new Unsigned { numbersArray, arrayLength, Endianess::Big };
	}

	Unsigned *const Unsigned::fromLittleEndianArray(const unsigned char *const numbersArray, const unsigned long long arrayLength){
	return new Unsigned { numbersArray, arrayLength, Endianess::Little };
	}

	Unsigned *const Unsigned::fromBinaryInString(const NumberInString &binaryInString){
	}

} /* namespace numb */
} /* namespace cm */
