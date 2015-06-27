/*
 * Unsigned.cpp
 *
 *  Created on: 24 cze 2015
 *      Author: Bartosz Miera
 */

#include "Unsigned.h"
#include "FloatingPoint.h"
#include "../Utility/Numbers.h"
#include "../Utility/BaseConverter.h"

namespace coma {
namespace numb {

	//======================================
	//--------------UNSIGNED----------------
	//======================================

	Unsigned::Unsigned(const unsigned char *const numbersArray, const unsigned long long arrayLength, const Endianess endianess) :
			Integer(numbersArray, arrayLength, endianess){}

	Unsigned *const Unsigned::fromBigEndianArray(const unsigned char *const numbersArray, const unsigned long long arrayLength){
		return new Unsigned { numbersArray, arrayLength, Endianess::Big };
	}

	Unsigned *const Unsigned::fromLittleEndianArray(const unsigned char *const numbersArray, const unsigned long long arrayLength){
		return new Unsigned { numbersArray, arrayLength, Endianess::Little };
	}

	Unsigned *const Unsigned::fromBinaryInString(const NumberInString &binaryInString){
		return fromHexadecimalInString(util::BaseConverter("01","0123456789ABCDEF").convert(binaryInString));
	}

	Unsigned *const Unsigned::fromOctalInString(const NumberInString &octalInString){
		return fromHexadecimalInString(util::BaseConverter("01234567","0123456789ABCDEF").convert(octalInString));
	}

	Unsigned *const Unsigned::fromDecimalInString(const NumberInString &decimalInString){
		return fromHexadecimalInString(util::BaseConverter::decimalToHexConverter().convert(decimalInString));
	}

	Unsigned *const Unsigned::fromHexadecimalInString(const NumberInString &hexadecimalInString){
		Unsigned *tmp { nullptr };
		unsigned char *chars = util::numb::arrayFromHexadecimal(hexadecimalInString);
		unsigned long long length = util::numb::sizeFromHexadecimal(hexadecimalInString);
		tmp = new Unsigned{chars, length, Endianess::Little};
		delete[] chars;
		return tmp;
	}

	//======================================
	//-------------COMPARABLE---------------
	//======================================

	const CompareResult Unsigned::compare(const RealNumber *const toCompare) const{
		return toCompare->coma::numb::Comparable<Unsigned>::compare(this);
	}

	const CompareResult Unsigned::compare(const FloatingPoint *const toCompare) const{
		return toCompare->coma::numb::Comparable<Unsigned>::compare(this);
	}

	const CompareResult Unsigned::compare(const Signed *const toCompare) const{
		return toCompare->coma::numb::Comparable<Unsigned>::compare(this);
	}

	const CompareResult Unsigned::compare(const Unsigned *const toCompare) const{
		//TODO: create method body
		return 0;
	}

} /* namespace numb */
} /* namespace coma */
