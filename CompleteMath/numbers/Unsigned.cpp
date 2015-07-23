/*
 * Unsigned.cpp
 *
 *  Created on: 24 cze 2015
 *      Author: Bartosz Miera
 */

#include <algorithm>
#include <memory>
#include <string>
#include <sstream>
#include <iomanip>

#include "Unsigned.h"
#include "Signed.h"
#include "FloatingPoint.h"
#include "Complex.h"

#include "../Utility/Numbers.h"
#include "../Utility/BaseConverter.h"
#include "../Utility/ArrayArithmetic.h"

namespace coma {
namespace numb {

	//======================================
	//--------------UNSIGNED----------------
	//======================================

	Unsigned::Unsigned(const util::RuntimeArray<unsigned char> &array, const Endianess endianess) :
			Integer(util::withoutMeaninglessChars(array, false), endianess){}

	Unsigned *const Unsigned::fromBigEndianArray(const util::RuntimeArray<unsigned char> &array){
		return new Unsigned { array, Endianess::Big };
	}

	Unsigned *const Unsigned::fromLittleEndianArray(const util::RuntimeArray<unsigned char> &array){
		return new Unsigned { array, Endianess::Little };
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
		return fromLittleEndianArray({chars.get(), length});
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

	Number *const Unsigned::getSum(const Unsigned *const toAdd) const{
		if(!toAdd) throw 1;//TODO exceptions
		util::RuntimeArray<unsigned char> tmp{ std::max(this->getArray().length(), toAdd->getArray().length()) + 1 };
		std::copy(getArray().begin(), getArray().end(), tmp.begin());
		tmp += toAdd->getArray();
		return fromLittleEndianArray(tmp);
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

	Number *const Unsigned::getProduct(const Unsigned *const toMultiply) const{
		if(!toMultiply) throw 1;//TODO exceptions
		util::RuntimeArray<unsigned char> tmp{ this->getArray().length() + toMultiply->getArray().length() };
		std::copy(getArray().begin(), getArray().end(), tmp.begin());
		tmp *= toMultiply->getArray();
		return fromLittleEndianArray(tmp);
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
		return getArray().length() == 1 && getArray()[0] == 0;
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
		std::stringstream ss{ };
		ss << std::uppercase;
		ss << std::setfill('0');
		for(unsigned long long i = 0; i < getArray().length(); ++i){
			unsigned int tmp = getArray()[getArray().length() - 1 - i];
			ss << std::hex << std::setw(2) << tmp;
		}
		std::string tmp = ss.str();
		coma::util::numb::removeLeftTrailingZeroes(tmp);
		return tmp;
	}

	Unsigned *const Unsigned::getAsUnsignedInteger() const{
		return fromLittleEndianArray(getArray());
	}

	Signed *const Unsigned::getAsSignedInteger() const{
		util::RuntimeArray<unsigned char> tmp { getArray().length() + 1 };
		std::copy(getArray().begin(), getArray().end(), tmp.begin());
		return Signed::fromLittleEndianArray(tmp);
	}

	FloatingPoint *const Unsigned::getAsFloatingPoint() const{
		//TODO complete after FloatingPoint definition
	}

	Complex *const Unsigned::getAsComplex() const{
		//TODO complete after Complex definition
	}

	Number *const Unsigned::getNegation() const{
		std::unique_ptr<Signed> asSigned { getAsSignedInteger() };
		return asSigned->getNegation();
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

	Integer *const Unsigned::getIntegerQuotient(const Unsigned *const toDivide) const{
		if(!toDivide) throw 1;//TODO exceptions
		if(toDivide->isZero()) throw 1;//TODO exceptions
		util::RuntimeArray<unsigned char> result = getArray();
		result /= toDivide->getArray();
		return fromLittleEndianArray(result);
	}

	Integer *const Unsigned::getRemainder(const Unsigned *const toDivide) const{
		if(!toDivide) throw 1;//TODO exceptions
		if(toDivide->isZero()) throw 1;//TODO exceptions
		util::RuntimeArray<unsigned char> result = getArray();
		result %= toDivide->getArray();
		return fromLittleEndianArray(result);
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
