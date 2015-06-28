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


#include <cassert>

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
		std::unique_ptr<unsigned char[]> chars{util::numb::arrayFromHexadecimal(hexadecimalInString)};
		unsigned long long length = util::numb::sizeFromHexadecimal(hexadecimalInString);
		return fromLittleEndianArray(chars.get(), length);
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

	const CompareResult Unsigned::compare(const Unsigned *const toCompare) const{//TODO testing
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
		return toAdd->coma::numb::Arithmetic<Unsigned, Number>::getSum(this);
	}

	Number *const Unsigned::getSum(const Complex *const toAdd) const{
		if(!toAdd) throw 1;//TODO exceptions
		return toAdd->coma::numb::Arithmetic<Unsigned, Number>::getSum(this);
	}

	Number *const Unsigned::getSum(const FloatingPoint *const toAdd) const{
		if(!toAdd) throw 1;//TODO exceptions
		return toAdd->coma::numb::Arithmetic<Unsigned, Number>::getSum(this);
	}

	Number *const Unsigned::getSum(const Signed *const toAdd) const{
		if(!toAdd) throw 1;//TODO exceptions
		return toAdd->coma::numb::Arithmetic<Unsigned, Number>::getSum(this);
	}

	Number *const Unsigned::getSum(const Unsigned *const toAdd) const{//TODO testing
		if(!toAdd) throw 1;//TODO exceptions
		const unsigned char *arr1 = this->getArray();
		unsigned long long size1 = this->getArraySize();
		const unsigned char *arr2 = toAdd->getArray();
		unsigned long long size2 = toAdd->getArraySize();
		unsigned long long sumSize { std::max(size1, size2) + 1 };
		std::unique_ptr<unsigned char[]> sum { new unsigned char[sumSize] { } };
		unsigned char carry = 0;
		for(unsigned long long i{0}; i < sumSize - 1 ; ++i){
			if(i < std::min(size1, size2)){
				if((sum[i] = arr1[i] + arr2[i] + carry) < arr1[i]) carry = 1;
				else carry = 0;
			}
			else{
				if((sum[i] = (size1 > size2 ? arr1[i] : arr2[i]) + carry) < arr1[i]) carry = 1;
				else carry = 0;
			}
		}
		if(!(sum[sumSize - 1] = carry)) --sumSize;
		return fromLittleEndianArray(sum.get(), sumSize);
	}

	Number *const Unsigned::getDifference(const Number *const toSubtract) const{
		if(!toSubtract) throw 1;//TODO exceptions
		return toSubtract->coma::numb::Arithmetic<Unsigned, Number>::getDifferenceNegation(this);
	}

	Number *const Unsigned::getDifference(const Complex *const toSubtract) const{
		if(!toSubtract) throw 1;//TODO exceptions
		return toSubtract->coma::numb::Arithmetic<Unsigned, Number>::getDifferenceNegation(this);
	}

	Number *const Unsigned::getDifference(const FloatingPoint *const toSubtract) const{
		if(!toSubtract) throw 1;//TODO exceptions
		return toSubtract->coma::numb::Arithmetic<Unsigned, Number>::getDifferenceNegation(this);
	}

	Number *const Unsigned::getDifference(const Signed *const toSubtract) const{
		if(!toSubtract) throw 1;//TODO exceptions
		return toSubtract->coma::numb::Arithmetic<Unsigned, Number>::getDifferenceNegation(this);
	}

	Number *const Unsigned::getDifference(const Unsigned *const toSubtract) const{
		if(!toSubtract) throw 1;//TODO exceptions
		std::unique_ptr<Signed> left { this->getAsSignedInteger() };
		return left->coma::numb::Arithmetic<Unsigned, Number>::getDifference(toSubtract);
	}

	Number *const Unsigned::getProduct(const Number *const toMultiply) const{
		if(!toMultiply) throw 1;//TODO exceptions
		return toMultiply->coma::numb::Arithmetic<Unsigned, Number>::getProduct(this);
	}

	Number *const Unsigned::getProduct(const Complex *const toMultiply) const{
		if(!toMultiply) throw 1;//TODO exceptions
		return toMultiply->coma::numb::Arithmetic<Unsigned, Number>::getProduct(this);
	}

	Number *const Unsigned::getProduct(const FloatingPoint *const toMultiply) const{
		if(!toMultiply) throw 1;//TODO exceptions
		return toMultiply->coma::numb::Arithmetic<Unsigned, Number>::getProduct(this);
	}

	Number *const Unsigned::getProduct(const Signed *const toMultiply) const{
		if(!toMultiply) throw 1;//TODO exceptions
		return toMultiply->coma::numb::Arithmetic<Unsigned, Number>::getProduct(this);
	}

	Number *const Unsigned::getProduct(const Unsigned *const toMultiply) const{//TODO serious testing
		if(!toMultiply) throw 1;//TODO exceptions
		unsigned long long size { this->getArraySize() + toMultiply->getArraySize() };
		std::unique_ptr<unsigned char[]> table { new unsigned char[size] { } };
		const unsigned char *arr1 = this->getArray();
		const unsigned char *arr2 = toMultiply->getArray();
		unsigned char carry { 0 };
		for(unsigned long long i = 0; i < this->getArraySize(); ++i){
			unsigned buffer { 0 };
			for(unsigned long long j = 0; j < toMultiply->getArraySize(); ++j){
				buffer = arr1[i] * arr2[j];
				unsigned char lower { static_cast<unsigned char>(buffer)      };
				unsigned char upper { static_cast<unsigned char>(buffer >> 8) };
				if((table[i + j]     += lower + carry) < lower) carry = 1; else carry = 0;
				if((table[i + j + 1] += upper + carry) < upper) carry = 1; else carry = 0;
			}
		}
		assert(!carry);
		while(!table[size - 1]) --size;
		return fromLittleEndianArray(table.get(), size);
	}

	Number *const Unsigned::getQuotient(const Number *const toDivide) const{
		if(!toDivide) throw 1;//TODO exceptions
		return toDivide->coma::numb::Arithmetic<Unsigned, Number>::getQuotientInverse(this);
	}

	Number *const Unsigned::getQuotient(const Complex *const toDivide) const{
		if(!toDivide) throw 1;//TODO exceptions
		return toDivide->coma::numb::Arithmetic<Unsigned, Number>::getQuotientInverse(this);
	}

	Number *const Unsigned::getQuotient(const FloatingPoint *const toDivide) const{
		if(!toDivide) throw 1;//TODO exceptions
		return toDivide->coma::numb::Arithmetic<Unsigned, Number>::getQuotientInverse(this);
	}

	Number *const Unsigned::getQuotient(const Signed *const toDivide) const{
		if(!toDivide) throw 1;//TODO exceptions
		return toDivide->coma::numb::Arithmetic<Unsigned, Number>::getQuotientInverse(this);
	}

	Number *const Unsigned::getQuotient(const Unsigned *const toDivide) const{
		if(!toDivide) throw 1;//TODO exceptions
		std::unique_ptr<FloatingPoint> left { this->getAsFloatingPoint() };
		return left->coma::numb::Arithmetic<Unsigned, Number>::getQuotient(toDivide);
	}

	Number *const Unsigned::getDifferenceNegation(const Number *const minuend) const{
		if(!minuend) throw 1;//TODO exceptions
		return minuend->coma::numb::Arithmetic<Unsigned, Number>::getDifference(this);
	}

	Number *const Unsigned::getDifferenceNegation(const Complex *const minuend) const{
		if(!minuend) throw 1;//TODO exceptions
		return minuend->coma::numb::Arithmetic<Unsigned, Number>::getDifference(this);
	}

	Number *const Unsigned::getDifferenceNegation(const FloatingPoint *const minuend) const{
		if(!minuend) throw 1;//TODO exceptions
		return minuend->coma::numb::Arithmetic<Unsigned, Number>::getDifference(this);
	}

	Number *const Unsigned::getDifferenceNegation(const Signed *const minuend) const{
		if(!minuend) throw 1;//TODO exceptions
		return minuend->coma::numb::Arithmetic<Unsigned, Number>::getDifference(this);
	}

	Number *const Unsigned::getDifferenceNegation(const Unsigned *const minuend) const{
		if(!minuend) throw 1;//TODO exceptions
		return minuend->coma::numb::Arithmetic<Unsigned, Number>::getDifference(this);
	}

	Number *const Unsigned::getQuotientInverse(const Number *const dividend) const{
		if(!dividend) throw 1;//TODO exceptions
		return dividend->coma::numb::Arithmetic<Unsigned, Number>::getQuotient(this);
	}

	Number *const Unsigned::getQuotientInverse(const Complex *const dividend) const{
		if(!dividend) throw 1;//TODO exceptions
		return dividend->coma::numb::Arithmetic<Unsigned, Number>::getQuotient(this);
	}

	Number *const Unsigned::getQuotientInverse(const FloatingPoint *const dividend) const{
		if(!dividend) throw 1;//TODO exceptions
		return dividend->coma::numb::Arithmetic<Unsigned, Number>::getQuotient(this);
	}

	Number *const Unsigned::getQuotientInverse(const Signed *const dividend) const{
		if(!dividend) throw 1;//TODO exceptions
		return dividend->coma::numb::Arithmetic<Unsigned, Number>::getQuotient(this);
	}

	Number *const Unsigned::getQuotientInverse(const Unsigned *const dividend) const{
		if(!dividend) throw 1;//TODO exceptions
		return dividend->coma::numb::Arithmetic<Unsigned, Number>::getQuotient(this);
	}

	//======================================
	//---------------NUMBER-----------------
	//======================================

	const bool Unsigned::isZero() const{
		return getArraySize() == 1 && getArray()[0] == 0;
	}



} /* namespace numb */
} /* namespace coma */
