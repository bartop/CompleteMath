/*
 * Unsigned.cpp
 *
 *  Created on: 24 cze 2015
 *      Author: Bartosz Miera
 */

#include <algorithm>
#include <memory>
#include "Unsigned.h"
#include "Signed.h"
#include "FloatingPoint.h"
#include "Complex.h"
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
		std::unique_ptr<unsigned char[]> chars = util::numb::arrayFromHexadecimal(hexadecimalInString);
		unsigned long long length = util::numb::sizeFromHexadecimal(hexadecimalInString);
		tmp = new Unsigned{chars, length, Endianess::Little};
		return tmp;
	}

	//======================================
	//-------------COMPARABLE---------------
	//======================================

	const CompareResult Unsigned::compare(const RealNumber *const toCompare) const{
		if(!toCompare) throw 1;//TODO exceptions
		return toCompare->coma::numb::Comparable<Unsigned>::compare(this);
	}

	const CompareResult Unsigned::compare(const FloatingPoint *const toCompare) const{
		if(!toCompare) throw 1;//TODO exceptions
		return toCompare->coma::numb::Comparable<Unsigned>::compare(this);
	}

	const CompareResult Unsigned::compare(const Signed *const toCompare) const{
		if(!toCompare) throw 1;//TODO exceptions
		return toCompare->coma::numb::Comparable<Unsigned>::compare(this);
	}

	const CompareResult Unsigned::compare(const Unsigned *const toCompare) const{
		if(!toCompare) throw 1;//TODO exceptions
		if(toCompare->getArraySize() == this->getArraySize()){
			unsigned long long index { 0 };
			while(index < this->getArraySize() && this->getArray()[index] == toCompare->getArray()[index]) ++index;
			if (index == this->getArraySize()) return CompareResult::Equal;
			else return this->getArray()[index] < toCompare->getArray()[index] ?
				CompareResult::ThisLesser : CompareResult::ThisGreater;
		}
		else return toCompare->getArraySize() > this->getArraySize() ? CompareResult::ThisLesser : CompareResult::ThisGreater;
	}

	//======================================
	//-------------ARITHMETIC---------------
	//======================================

	Number *const Unsigned::getSum(const Number *const toAdd) const{
		if(!toAdd) throw 1;//TODO exceptions
		return toAdd->coma::numb::Arithmetic<Unsigned>::getSum(this);
	}

	Complex *const Unsigned::getSum(const Complex *const toAdd) const{
		if(!toAdd) throw 1;//TODO exceptions
		return toAdd->coma::numb::Arithmetic<Unsigned>::getSum(this);
	}

	FloatingPoint *const Unsigned::getSum(const FloatingPoint *const toAdd) const{
		if(!toAdd) throw 1;//TODO exceptions
		return toAdd->coma::numb::Arithmetic<Unsigned>::getSum(this);
	}

	Signed *const Unsigned::getSum(const Signed *const toAdd) const{
		if(!toAdd) throw 1;//TODO exceptions
		return toAdd->coma::numb::Arithmetic<Unsigned>::getSum(this);
	}

	Unsigned *const Unsigned::getSum(const Unsigned *const toAdd) const{
		if(!toAdd) throw 1;//TODO exceptions
		const unsigned char *arr1 = this->getArray();
		unsigned long long size1 = this->getArraySize();
		const unsigned char *arr2 = toAdd->getArray();
		unsigned long long size2 = toAdd->getArraySize();
		unsigned long long sumSize { std::max(size1, size2) + 1 };
		std::unique_ptr<unsigned char[]> sum = new unsigned char[sumSize] { };
		unsigned char carry = 0;
		for(unsigned long long i{0}; i < sumSize - 1 ; ++i){
			if(i < std::min(size1, size2)){
				if((sum[i] = arr1[i] + arr2[i] + carry) < arr1[i]) carry = 1;
			}
			else{
				if((sum[i] = (size1 > size2 ? arr1[i] : arr2[i]) + carry) < arr1[i]) carry = 1;
			}
		}
		if(!(sum[sumSize - 1] = carry)) --sumSize;
		return fromLittleEndianArray(sum.get(), sumSize);
	}
} /* namespace numb */
} /* namespace coma */
