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

Unsigned *Unsigned::fromBigEndianArray(const util::RuntimeArray<unsigned char> &array){
	return new Unsigned { array, Endianess::Big };
}

Unsigned *Unsigned::fromLittleEndianArray(const util::RuntimeArray<unsigned char> &array){
	return new Unsigned { array, Endianess::Little };
}

Unsigned *Unsigned::fromBinaryInString(const std::string &binaryInString){
	return fromHexadecimalInString(util::BaseConverter("01","0123456789ABCDEF").convert(binaryInString));
}

Unsigned *Unsigned::fromOctalInString(const std::string &octalInString){
	return fromHexadecimalInString(util::BaseConverter("01234567","0123456789ABCDEF").convert(octalInString));
}

Unsigned *Unsigned::fromDecimalInString(const std::string &decimalInString){
	return fromHexadecimalInString(util::BaseConverter::decimalToHexConverter().convert(decimalInString));
}

Unsigned *Unsigned::fromHexadecimalInString(const std::string &hexadecimalInString){
	std::unique_ptr<unsigned char[]> chars{util::numb::arrayFromHexadecimal(hexadecimalInString)};
	unsigned long long length = util::numb::sizeFromHexadecimal(hexadecimalInString);
	return fromLittleEndianArray({chars.get(), length});
}

Unsigned::~Unsigned(){}

//======================================
//--------------COPYABLE----------------
//======================================

Number *Unsigned::copy() const{
	return getAsUnsignedInteger();
}

//======================================
//-------------ARITHMETIC---------------
//======================================

Number *Unsigned::getSum(const Number *toAdd) const{
	return toAdd->getSum(this);
}

Number *Unsigned::getSum(const Complex *toAdd) const{
	return toAdd->getSum(this);
}

Number *Unsigned::getSum(const FloatingPoint *toAdd) const{
	return toAdd->getSum(this);
}

Number *Unsigned::getSum(const Signed *toAdd) const{
	return toAdd->getSum(this);
}

Number *Unsigned::getSum(const Unsigned *toAdd) const{
	if(!toAdd) throw 1;//TODO exceptions
	util::RuntimeArray<unsigned char> tmp{ std::max(this->getArray().length(), toAdd->getArray().length()) + 1 };
	std::copy(getArray().begin(), getArray().end(), tmp.begin());
	tmp += toAdd->getArray();
	return fromLittleEndianArray(tmp);
}

Number *Unsigned::getProduct(const Number *toMultiply) const{
	return toMultiply->getProduct(this);
}

Number *Unsigned::getProduct(const Complex *toMultiply) const{
	return toMultiply->getProduct(this);
}

Number *Unsigned::getProduct(const FloatingPoint *toMultiply) const{
	return toMultiply->getProduct(this);
}

Number *Unsigned::getProduct(const Signed *toMultiply) const{
	return toMultiply->getProduct(this);
}

Number *Unsigned::getProduct(const Unsigned *toMultiply) const{
	if(!toMultiply) throw 1;//TODO exceptions
	util::RuntimeArray<unsigned char> tmp{ this->getArray().length() + toMultiply->getArray().length() };
	std::copy(getArray().begin(), getArray().end(), tmp.begin());
	tmp *= toMultiply->getArray();
	return fromLittleEndianArray(tmp);
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

Unsigned *Unsigned::getAsUnsignedInteger() const{
	return fromLittleEndianArray(getArray());
}

Signed *Unsigned::getAsSignedInteger() const{
	util::RuntimeArray<unsigned char> tmp { getArray().length() + 1 };
	std::copy(getArray().begin(), getArray().end(), tmp.begin());
	return Signed::fromLittleEndianArray(tmp);
}

FloatingPoint *Unsigned::getAsFloatingPoint() const{
	return FloatingPoint::fromFraction(this,
			ONE(),
			ZERO());
}

Complex *Unsigned::getAsComplex() const{
	//TODO complete after Complex definition
}

Number *Unsigned::getNegation() const{
	std::unique_ptr<Signed> asSigned { getAsSignedInteger() };
	return asSigned->getNegation();
}

Number *Unsigned::getInversion() const{
	return FloatingPoint::fromFraction(static_cast<const Integer *>(ONE()),
			this,
			ZERO());
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

Integer *Unsigned::getIntegerQuotient(const Integer *toDivide) const{
	return static_cast<const coma::numb::IntegerArithmetic<Unsigned, Integer> *const>(toDivide)->getIntegerQuotientInverse(this);
}

Integer *Unsigned::getRemainder(const Integer *toDivide) const{
	return static_cast<const coma::numb::IntegerArithmetic<Unsigned, Integer> *const>(toDivide)->getInverseRemainder(this);
}

Integer *Unsigned::getIntegerQuotientInverse(const Integer *dividend) const{
	return static_cast<const coma::numb::IntegerArithmetic<Unsigned, Integer> *const>(dividend)->getIntegerQuotient(this);
}

Integer *Unsigned::getInverseRemainder(const Integer *dividend) const{
	return static_cast<const coma::numb::IntegerArithmetic<Unsigned, Integer> *const>(dividend)->getInverseRemainder(this);
}

Integer *Unsigned::getIntegerQuotient(const Signed *toDivide) const{
	return static_cast<const coma::numb::IntegerArithmetic<Unsigned, Integer> *const>(toDivide)->getIntegerQuotientInverse(this);
}

Integer *Unsigned::getRemainder(const Signed *toDivide) const{
	return static_cast<const coma::numb::IntegerArithmetic<Unsigned, Integer> *const>(toDivide)->getInverseRemainder(this);
}

Integer *Unsigned::getIntegerQuotientInverse(const Signed *dividend) const{
	return static_cast<const coma::numb::IntegerArithmetic<Unsigned, Integer> *const>(dividend)->getIntegerQuotient(this);
}

Integer *Unsigned::getInverseRemainder(const Signed *dividend) const{
	return static_cast<const coma::numb::IntegerArithmetic<Unsigned, Integer> *const>(dividend)->getRemainder(this);
}

Integer *Unsigned::getIntegerQuotient(const Unsigned *toDivide) const{
	if(!toDivide) throw 1;//TODO exceptions
	if(toDivide->isZero()) throw 1;//TODO exceptions
	util::RuntimeArray<unsigned char> result = getArray();
	result /= toDivide->getArray();
	return fromLittleEndianArray(result);
}

Integer *Unsigned::getRemainder(const Unsigned *toDivide) const{
	if(!toDivide) throw 1;//TODO exceptions
	if(toDivide->isZero()) throw 1;//TODO exceptions
	util::RuntimeArray<unsigned char> result = getArray();
	result %= toDivide->getArray();
	return fromLittleEndianArray(result);
}

Integer *Unsigned::getIntegerQuotientInverse(const Unsigned *dividend) const{
	return static_cast<const coma::numb::IntegerArithmetic<Unsigned, Integer> *const>(dividend)->getIntegerQuotient(this);
}

Integer *Unsigned::getInverseRemainder(const Unsigned *dividend) const{
	return static_cast<const coma::numb::IntegerArithmetic<Unsigned, Integer> *const>(dividend)->getRemainder(this);
}

} /* namespace numb */
} /* namespace coma */
