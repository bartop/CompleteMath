/*
 * Integer.cpp
 *
 *  Created on: 26 cze 2015
 *      Author: Bartosz Miera
 */

#include "Integer.h"
#include "FloatingPoint.h"
#include "Signed.h"
#include "Unsigned.h"

#include "../Utility/Numbers.h"
#include "../Utility/ArrayArithmetic.h"

#include <algorithm>
#include <memory>

namespace coma{
namespace numb{

Integer::Integer(const util::RuntimeArray<unsigned char> numbersArray, const Endianess endianess):
		m_integer{ endianess == Endianess::Little ? numbersArray : util::reverse(numbersArray) }{}

const util::RuntimeArray<unsigned char> &Integer::getArray() const{
	return m_integer;
}

Integer *const Integer::fromLittleEndianArray(const util::RuntimeArray<unsigned char> &array, bool asSigned){
	if(!asSigned) return Unsigned::fromLittleEndianArray(array);
	else{
		if(array[array.length() - 1] & 0x80) return Signed::fromLittleEndianArray(array);
		else return Unsigned::fromLittleEndianArray(array);
	}
}

Integer *const Integer::fromBigEndianArray(const util::RuntimeArray<unsigned char> &array, bool asSigned){
	if(!asSigned) return Unsigned::fromBigEndianArray(array);
	else{
		if(array[array.length() - 1] & 0x80) return Signed::fromBigEndianArray(array);
		else return Unsigned::fromBigEndianArray(array);
	}
}

Integer *const Integer::fromBinaryInString(const std::string &binary){
	if(binary[0] == '-') return Signed::fromBinaryInString(binary);
	else{
		if(binary[0] == '+') return Unsigned::fromBinaryInString(binary.substr(1, binary.length() - 1));
		else return Unsigned::fromBinaryInString(binary);
	}
}

Integer *const Integer::fromOctalInString(const std::string &octal){
	if(octal[0] == '-') return Signed::fromOctalInString(octal);
	else{
		if(octal[0] == '+') return Unsigned::fromOctalInString(octal.substr(1, octal.length() - 1));
		else return Unsigned::fromOctalInString(octal);
	}
}

Integer *const Integer::fromDecimalInString(const std::string &decimal){
	if(decimal[0] == '-') return Signed::fromDecimalInString(decimal);
	else{
		if(decimal[0] == '+') return Unsigned::fromDecimalInString(decimal.substr(1, decimal.length() - 1));
		else return Unsigned::fromDecimalInString(decimal);
	}
}

Integer *const Integer::fromHexadecimalInString(const std::string &hex){
	if(hex[0] == '-') return Signed::fromHexadecimalInString(hex);
	else{
		if(hex[0] == '+') return Unsigned::fromHexadecimalInString(hex.substr(1, hex.length() - 1));
		else return Unsigned::fromHexadecimalInString(hex);
	}
}

}/* namespace numb */
} /* namespace coma */
