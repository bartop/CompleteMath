/*
 * Unsigned.cpp
 *
 *  Created on: 24 cze 2015
 *      Author: Bartosz Miera
 */

#include <algorithm>
#include <memory>
#include <sstream>
#include <iomanip>
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

	Unsigned *const Unsigned::fromBinaryInString(const std::string &binaryInString){
		return fromHexadecimalInString(util::BaseConverter("01","0123456789ABCDEF").convert(binaryInString));
	}

	Unsigned *const Unsigned::fromOctalInString(const std::string &octalInString){
		return fromHexadecimalInString(util::BaseConverter("01234567","0123456789ABCDEF").convert(octalInString));
	}

	Unsigned *const Unsigned::fromDecimalInString(const std::string &decimalInString){
		return fromHexadecimalInString(util::BaseConverter::decimalToHexConverter().convert(decimalInString));
	}

	Unsigned *const Unsigned::fromHexadecimalInString(const std::string &hexadecimalInString){
		std::unique_ptr<unsigned char[]> chars{util::numb::arrayFromHexadecimal(hexadecimalInString)};
		unsigned long long length = util::numb::sizeFromHexadecimal(hexadecimalInString);
		return fromLittleEndianArray(chars.get(), length);
	}

	//======================================
	//-------------COMPARABLE---------------
	//======================================


	const CompareResult Unsigned::compare(const RealNumber *const toCompare) const{
		return invertComparison(static_cast<const coma::numb::Comparable<Unsigned> *const >(toCompare)->compare(this));
	}

	const CompareResult Unsigned::compare(const FloatingPoint *const toCompare) const{
		return invertComparison(static_cast<const coma::numb::Comparable<Unsigned> *const >(toCompare)->compare(this));
	}

	const CompareResult Unsigned::compare(const Signed *const toCompare) const{
		return invertComparison(static_cast<const coma::numb::Comparable<Unsigned> *const >(toCompare)->compare(this));
	}

	const CompareResult Unsigned::compare(const Unsigned *const toCompare) const{//TODO testing
		if(!toCompare) throw 1;//TODO exceptions
		if(toCompare->getArraySize() == this->getArraySize()){
			unsigned long long i { 0 };
			unsigned long long index { this->getArraySize() - 1 };
			while(i < this->getArraySize() && this->getArray()[index] == toCompare->getArray()[index]){
				++i;
				--index;
			}
			if (i == this->getArraySize()) return CompareResult::Equal;
			else return this->getArray()[index] < toCompare->getArray()[index] ?
				CompareResult::ThisLesser : CompareResult::ThisGreater;
		}
		else return toCompare->getArraySize() > this->getArraySize() ? CompareResult::ThisLesser : CompareResult::ThisGreater;
	}

	//======================================
	//-------------ARITHMETIC---------------
	//======================================

	Number *const Unsigned::getSum(const Number *const toAdd) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(toAdd)->getSum(this);
	}

	Number *const Unsigned::getSum(const Complex *const toAdd) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(toAdd)->getSum(this);
	}

	Number *const Unsigned::getSum(const FloatingPoint *const toAdd) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(toAdd)->getSum(this);
	}

	Number *const Unsigned::getSum(const Signed *const toAdd) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(toAdd)->getSum(this);
	}

	Number *const Unsigned::getSum(const Unsigned *const toAdd) const{//TODO testing
		if(!toAdd) throw 1;//TODO exceptions
		unsigned long long resultSize = std::max(this->getArraySize(), toAdd->getArraySize()) + 1;
		std::unique_ptr<unsigned char[]> result{ new unsigned char [resultSize] {}};
		std::copy(this->getArray(), this->getArray() + this->getArraySize(), result.get());
		util::numb::addArray(result.get(), resultSize, toAdd->getArray(), toAdd->getArraySize());
		return fromLittleEndianArray(result.get(), util::numb::getUsedBytes(result.get(), resultSize));
	}

	Number *const Unsigned::getDifference(const Number *const toSubtract) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(toSubtract)->getDifferenceNegation(this);
	}

	Number *const Unsigned::getDifference(const Complex *const toSubtract) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(toSubtract)->getDifferenceNegation(this);
	}

	Number *const Unsigned::getDifference(const FloatingPoint *const toSubtract) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(toSubtract)->getDifferenceNegation(this);
	}

	Number *const Unsigned::getDifference(const Signed *const toSubtract) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(toSubtract)->getDifferenceNegation(this);
	}

	Number *const Unsigned::getDifference(const Unsigned *const toSubtract) const{
		std::unique_ptr<coma::numb::Arithmetic<Unsigned, Number> > left { toSubtract->getAsSignedInteger() };
		return left->getDifferenceNegation(this);
	}

	Number *const Unsigned::getProduct(const Number *const toMultiply) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(toMultiply)->getProduct(this);
	}

	Number *const Unsigned::getProduct(const Complex *const toMultiply) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(toMultiply)->getProduct(this);
	}

	Number *const Unsigned::getProduct(const FloatingPoint *const toMultiply) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(toMultiply)->getProduct(this);
	}

	Number *const Unsigned::getProduct(const Signed *const toMultiply) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(toMultiply)->getProduct(this);
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
				if((table[i + j]     += lower + carry) < (lower + carry)) carry = 1; else carry = 0;
				if((table[i + j + 1] += upper + carry) < (upper + carry)) carry = 1; else carry = 0;
			}
		}
		while(!table[size - 1]) --size;
		return fromLittleEndianArray(table.get(), size);
	}

	Number *const Unsigned::getQuotient(const Number *const toDivide) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(toDivide)->getQuotientInverse(this);
	}

	Number *const Unsigned::getQuotient(const Complex *const toDivide) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(toDivide)->getQuotientInverse(this);
	}

	Number *const Unsigned::getQuotient(const FloatingPoint *const toDivide) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(toDivide)->getQuotientInverse(this);
	}

	Number *const Unsigned::getQuotient(const Signed *const toDivide) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(toDivide)->getQuotientInverse(this);
	}

	Number *const Unsigned::getQuotient(const Unsigned *const toDivide) const{
		std::unique_ptr<FloatingPoint> left { this->getAsFloatingPoint() };
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(left.get())->getQuotient(toDivide);
	}

	Number *const Unsigned::getDifferenceNegation(const Number *const minuend) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(minuend)->getDifference(this);
	}

	Number *const Unsigned::getDifferenceNegation(const Complex *const minuend) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(minuend)->getDifference(this);
	}

	Number *const Unsigned::getDifferenceNegation(const FloatingPoint *const minuend) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(minuend)->getDifference(this);
	}

	Number *const Unsigned::getDifferenceNegation(const Signed *const minuend) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(minuend)->getDifference(this);
	}

	Number *const Unsigned::getDifferenceNegation(const Unsigned *const minuend) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(minuend)->getDifference(this);
	}

	Number *const Unsigned::getQuotientInverse(const Number *const dividend) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(dividend)->getQuotient(this);
	}

	Number *const Unsigned::getQuotientInverse(const Complex *const dividend) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(dividend)->getQuotient(this);
	}

	Number *const Unsigned::getQuotientInverse(const FloatingPoint *const dividend) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(dividend)->getQuotient(this);
	}

	Number *const Unsigned::getQuotientInverse(const Signed *const dividend) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(dividend)->getQuotient(this);
	}

	Number *const Unsigned::getQuotientInverse(const Unsigned *const dividend) const{
		return static_cast<const coma::numb::Arithmetic<Unsigned, Number> *const>(dividend)->getQuotient(this);
	}

	//======================================
	//---------------NUMBER-----------------
	//======================================

	const bool Unsigned::isZero() const{
		return getArraySize() == 1 && getArray()[0] == 0;
	}

	const std::string Unsigned::getAsBinary() const{
		std::string num = getAsHexadecimal();
		return coma::util::BaseConverter("01234567890ABCDEF", "01").convert(num);
	}

	const std::string Unsigned::getAsOctal() const{
		std::string num = getAsHexadecimal();
		return coma::util::BaseConverter("01234567890ABCDEF", "01234567").convert(num);
	}

	const std::string Unsigned::getAsDecimal() const{
		std::string num = getAsHexadecimal();
		return coma::util::BaseConverter::hexToDecimalConverter().convert(num);
	}

	const std::string Unsigned::getAsHexadecimal() const{
		std::stringstream sstream{ };
		sstream << std::uppercase;
		sstream << std::setfill('0');
		for(unsigned long long i = 0; i < getArraySize(); ++i){
			unsigned int tmp = getArray()[getArraySize() - 1 - i];
			sstream << std::hex << std::setw(2) << tmp;
		}
		std::string tmp = sstream.str();
		coma::util::numb::removeLeftTrailingZeroes(tmp);
		return tmp;
	}

	Unsigned *const Unsigned::getAsUnsignedInteger() const{
		return fromLittleEndianArray(getArray(), getArraySize());
	}

	Signed *const Unsigned::getAsSignedInteger() const{
		//TODO complete after Signed definition
	}

	FloatingPoint *const Unsigned::getAsFloatingPoint() const{
		//TODO complete after FloatingPoint definition
	}

	Complex *const Unsigned::getAsComplex() const{
		//TODO complete after Complex definition
	}

	Number *const Unsigned::getNegation() const{
		//TODO finish after Signed definition
	}

	Number *const Unsigned::getInversion() const{
		//TODO finish after FloatingPoint definition
	}

	const bool Unsigned::isNegative() const{
		return false;
	}

	const bool Unsigned::isPositive() const{
		return !isZero();
	}

	//======================================
	//---------INTEGERARITHMETIC------------
	//======================================

	Integer *const Unsigned::getIntegerQuotient(const Integer *const toDivide) const{
		return static_cast<const coma::numb::IntegerArithmetic<Unsigned, Integer> *const>(toDivide)->getIntegerQuotientInverse(this);
	}

	Integer *const Unsigned::getRemainder(const Integer *const toDivide) const{
		return static_cast<const coma::numb::IntegerArithmetic<Unsigned, Integer> *const>(toDivide)->getInverseRemainder(this);
	}

	Integer *const Unsigned::getIntegerQuotientInverse(const Integer *const dividend) const{
		return static_cast<const coma::numb::IntegerArithmetic<Unsigned, Integer> *const>(dividend)->getIntegerQuotient(this);
	}

	Integer *const Unsigned::getInverseRemainder(const Integer *const dividend) const{
		return static_cast<const coma::numb::IntegerArithmetic<Unsigned, Integer> *const>(dividend)->getInverseRemainder(this);
	}

	Integer *const Unsigned::getIntegerQuotient(const Signed *const toDivide) const{
		return static_cast<const coma::numb::IntegerArithmetic<Unsigned, Integer> *const>(toDivide)->getIntegerQuotientInverse(this);
	}

	Integer *const Unsigned::getRemainder(const Signed *const toDivide) const{
		return static_cast<const coma::numb::IntegerArithmetic<Unsigned, Integer> *const>(toDivide)->getInverseRemainder(this);
	}

	Integer *const Unsigned::getIntegerQuotientInverse(const Signed *const dividend) const{
		return static_cast<const coma::numb::IntegerArithmetic<Unsigned, Integer> *const>(dividend)->getIntegerQuotient(this);
	}

	Integer *const Unsigned::getInverseRemainder(const Signed *const dividend) const{
		return static_cast<const coma::numb::IntegerArithmetic<Unsigned, Integer> *const>(dividend)->getInverseRemainder(this);
	}

	Integer *const Unsigned::getIntegerQuotient(const Unsigned *const toDivide) const{//TODO testing, testing
		if(!toDivide) throw 1;//TODO exceptions
		if(toDivide->isZero()) throw 1;//TODO exceptions
		unsigned long long size = std::max(this->getArraySize(), toDivide->getArraySize());
		std::unique_ptr<unsigned char[]> array1{new unsigned char[size]{}};
		std::copy(this->getArray(), this->getArray() + this->getArraySize(), array1.get());
		std::unique_ptr<unsigned char[]> array2{new unsigned char[size]{}};
		std::copy(toDivide->getArray(), toDivide->getArray() + toDivide->getArraySize(), array2.get());
		std::unique_ptr<unsigned char[]> quot(new unsigned char[size]{});
		std::unique_ptr<unsigned char[]> rema(new unsigned char[size]{});

		//magic happens here
		for(unsigned long long i = 0; i < size; ++i){
			util::numb::shiftArrayLeft(rema.get(), size);
			rema[0] = array1[i];
			bool RgeD {};
			do{
				unsigned long long i { 0 };
				unsigned long long index { size - 1 };
				while(i < size && rema[index] == array2[index]){
					++i;
					--index;
				}
				RgeD =  (rema[index] > array2[index] || i == size );//R >= D
				if (RgeD){
					util::numb::subtractArray(rema.get(), size, array2.get(), size);
					quot[i] += 1;
				}
			}while(RgeD);
		}
		return fromLittleEndianArray(quot.get(),util::numb::getUsedBytes(quot.get(), size));
	}

	Integer *const Unsigned::getRemainder(const Unsigned *const toDivide) const{//TODO testing, testing
		if(!toDivide) throw 1;//TODO exceptions
		if(toDivide->isZero()) throw 1;//TODO exceptions
		unsigned long long size = std::max(this->getArraySize(), toDivide->getArraySize());
		std::unique_ptr<unsigned char[]> array1{new unsigned char[size]{}};
		std::copy(this->getArray(), this->getArray() + this->getArraySize(), array1.get());
		std::unique_ptr<unsigned char[]> array2{new unsigned char[size]{}};
		std::copy(toDivide->getArray(), toDivide->getArray() + toDivide->getArraySize(), array2.get());
		std::unique_ptr<unsigned char[]> quot(new unsigned char[size]{});
		std::unique_ptr<unsigned char[]> rema(new unsigned char[size]{});

		//magic happens here
		for(unsigned long long i = 0; i < size; ++i){
			util::numb::shiftArrayLeft(rema.get(), size);
			rema[0] = array1[i];
			bool RgeD {};
			do{
				unsigned long long i { 0 };
				unsigned long long index { size - 1 };
				while(i < size && rema[index] == array2[index]){
					++i;
					--index;
				}
				RgeD =  (rema[index] > array2[index] || i == size );//R >= D
				if (RgeD){
					util::numb::subtractArray(rema.get(), size, array2.get(), size);
					quot[i] += 1;
				}
			}while(RgeD);
		}
		return fromLittleEndianArray(rema.get(),util::numb::getUsedBytes(rema.get(), size));
	}

	Integer *const Unsigned::getIntegerQuotientInverse(const Unsigned *const dividend) const{
		return static_cast<const coma::numb::IntegerArithmetic<Unsigned, Integer> *const>(dividend)->getIntegerQuotient(this);
	}

	Integer *const Unsigned::getInverseRemainder(const Unsigned *const dividend) const{
		return static_cast<const coma::numb::IntegerArithmetic<Unsigned, Integer> *const>(dividend)->getRemainder(this);
	}

Unsigned::~Unsigned(){}
} /* namespace numb */
} /* namespace coma */
