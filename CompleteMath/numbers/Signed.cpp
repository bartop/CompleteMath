/*
 * Signed.cpp
 *
 *  Created on: 27 cze 2015
 *      Author: Bartosz Miera
 */


#include "Signed.h"
#include "../Utility/Numbers.h"
#include "../Utility/BaseConverter.h"
#include "../Utility/RuntimeArray.h"
#include "../Utility/ArrayArithmetic.h"
#include "Unsigned.h"
#include "FloatingPoint.h"
#include "Complex.h"
#include <memory>


namespace coma {
namespace numb {

//======================================
//---------------SIGNED-----------------
//======================================

Signed::Signed(const util::RuntimeArray<unsigned char> &array,
		const Endianess endianess) :
				Integer( util::withoutMeaninglessChars(array, true) , endianess){}

Signed *const Signed::fromBigEndianArray(const util::RuntimeArray<unsigned char> &array){
	return new Signed{ array, Endianess::Big };
}

Signed *const Signed::fromLittleEndianArray(const util::RuntimeArray<unsigned char> &array){
	return new Signed{ array, Endianess::Little };
}

Signed *const Signed::fromBinaryInString(const std::string &binaryInString){
	return fromHexadecimalInString(
			binaryInString[0] + coma::util::BaseConverter("01","0123456789ABCDEF").
			convert(binaryInString.substr(1, binaryInString.length() - 1)));
}

Signed *const Signed::fromOctalInString(const std::string &octalInString){
	return fromHexadecimalInString(
			octalInString[0] + coma::util::BaseConverter("01234567","0123456789ABCDEF").
			convert(octalInString.substr(1, octalInString.length() - 1)));
}

Signed *const Signed::fromDecimalInString(const std::string &decimalInString){
	return fromHexadecimalInString(
			decimalInString[0] + coma::util::BaseConverter("0123456789","0123456789ABCDEF").
			convert(decimalInString.substr(1, decimalInString.length() - 1)));
}

Signed *const Signed::fromHexadecimalInString(const std::string &hexadecimalInString){
	std::unique_ptr<unsigned char[]> chars{ util::numb::arrayFromSignedHexadecimal(hexadecimalInString) };
	unsigned long long length { util::numb::sizeFromSignedHexadecimal(hexadecimalInString) };
	return fromLittleEndianArray({chars.get(), length});
}

Signed::~Signed(){}
//======================================
//--------------COPYABLE----------------
//======================================

Number *const Signed::copy() const{
	return getAsSignedInteger();
}

//======================================
//-------------ARITHMETIC---------------
//======================================

Number *const Signed::getSum(const Number *const toAdd) const{
	return toAdd->getSum(this);
}

Number *const Signed::getSum(const Complex *const toAdd) const{
	return toAdd->getSum(this);
}

Number *const Signed::getSum(const FloatingPoint *const toAdd) const{
	return toAdd->getSum(this);
}

Number *const Signed::getSum(const Signed *const toAdd) const{
	util::RuntimeArray<unsigned char> tmp1
		{ 1 + std::max(toAdd->getArray().length(), this->getArray().length()), this->isNegative() ? 0xFF : 0 };
	util::RuntimeArray<unsigned char> tmp2
		{ 1 + std::max(toAdd->getArray().length(), this->getArray().length()), toAdd->isNegative() ? 0xFF : 0 };
	std::copy(this->getArray().begin(), this->getArray().end(), tmp1.begin());
	std::copy(toAdd->getArray().begin(), toAdd->getArray().end(), tmp2.begin());
	tmp1 += tmp2;
	return fromLittleEndianArray(tmp1);
}

Number *const Signed::getSum(const Unsigned *const toAdd) const{
	std::unique_ptr<coma::numb::Signed> left { toAdd->getAsSignedInteger() };
	return left->getSum(this);
}

Number *const Signed::getProduct(const Number *const toMultiply) const{
	return toMultiply->getProduct(this);
}

Number *const Signed::getProduct(const Complex *const toMultiply) const{
	return toMultiply->getProduct(this);
}

Number *const Signed::getProduct(const FloatingPoint *const toMultiply) const{
	return toMultiply->getProduct(this);
}

Number *const Signed::getProduct(const Signed *const toMultiply) const{
	util::RuntimeArray<unsigned char>
		tmp1{ this->getArray().length() + toMultiply->getArray().length() + 2, this->isNegative() ? 0xFF : 0 },
		tmp2{ this->getArray().length() + toMultiply->getArray().length() + 2, toMultiply->isNegative() ? 0xFF : 0 };
	std::copy(this->getArray().begin(),
			this->getArray().end(), tmp1.begin());
	std::copy(toMultiply->getArray().begin(),
			toMultiply->getArray().end(), tmp2.begin());
	if(this->isNegative()) util::negate(tmp1);
	if(toMultiply->isNegative()) util::negate(tmp2);
	tmp1 *= tmp2;
	if(this->isNegative() != toMultiply->isNegative()) util::negate(tmp1);
	return fromLittleEndianArray(tmp1);
}

Number *const Signed::getProduct(const Unsigned *const toMultiply) const{//TODO serious testing
	std::unique_ptr<coma::numb::Signed> left { toMultiply->getAsSignedInteger() };
	return left->getProduct(this);
}

//======================================
//---------------NUMBER-----------------
//======================================

const bool Signed::isZero() const{
	return getArray().length() == 1 && getArray()[0] == 0;
}

const std::string Signed::getAsBinary() const{
	std::string result = getAsHexadecimal();
	if(isNegative())
		return result[0] + util::BaseConverter("0123456789ABCDEF", "01").convert(result.substr(1, result.length() - 1));
	else return util::BaseConverter("0123456789ABCDEF", "01").convert(result.substr(0, result.length()));
}

const std::string Signed::getAsOctal() const{
	std::string result = getAsHexadecimal();
	if(isNegative())
		return result[0] + util::BaseConverter("0123456789ABCDEF", "01234567").convert(result.substr(1, result.length() - 1));
	else return util::BaseConverter("0123456789ABCDEF", "01234567").convert(result.substr(0, result.length()));
}

const std::string Signed::getAsDecimal() const{
	std::string result = getAsHexadecimal();
	if(isNegative())
		return result[0] + util::BaseConverter("0123456789ABCDEF", "0123456789").convert(result.substr(1, result.length() - 1));
	else return util::BaseConverter("0123456789ABCDEF", "0123456789").convert(result.substr(0, result.length()));
}

const std::string Signed::getAsHexadecimal() const{
	if(!isNegative()) return std::unique_ptr<Number>(getAsUnsignedInteger())->getAsHexadecimal();
	else return "-"+std::unique_ptr<Number>(getNegation())->getAsHexadecimal();

}

Unsigned *const Signed::getAsUnsignedInteger() const{
	return Unsigned::fromLittleEndianArray(getArray());
}

Signed *const Signed::getAsSignedInteger() const{
	return fromLittleEndianArray(getArray());
}

FloatingPoint *const Signed::getAsFloatingPoint() const{
	return FloatingPoint::fromFraction(this,
			ONE(),
			ZERO());
}

Complex *const Signed::getAsComplex() const{
	//TODO complete after Complex definition
}

Number *const Signed::getNegation() const{
	util::RuntimeArray<unsigned char> tmp { getArray().length() + 1, isNegative() ? 0xFF : 0 };
	std::copy(getArray().begin(), getArray().end(), tmp.begin());
	util::negate(tmp);
	if(isNegative()) return Unsigned::fromLittleEndianArray(tmp);
	else return Signed::fromLittleEndianArray(tmp);
}

Number *const Signed::getInversion() const{
	return FloatingPoint::fromFraction(static_cast<const Integer *>(multiplicationNeutralElement()),
			this,
			ZERO());
}

const bool Signed::isNegative() const{
	return getArray()[getArray().length() - 1] & 0x80;
}

const bool Signed::isPositive() const{
	return !isNegative() && !isZero();
}

//======================================
//---------INTEGERARITHMETIC------------
//======================================

Integer *const Signed::getIntegerQuotient(const Integer *const toDivide) const{
	return static_cast<const coma::numb::IntegerArithmetic<Signed, Integer> *const>(toDivide)->getIntegerQuotientInverse(this);
}

Integer *const Signed::getRemainder(const Integer *const toDivide) const{
	return static_cast<const coma::numb::IntegerArithmetic<Signed, Integer> *const>(toDivide)->getInverseRemainder(this);
}

Integer *const Signed::getIntegerQuotientInverse(const Integer *const dividend) const{
	return static_cast<const coma::numb::IntegerArithmetic<Signed, Integer> *const>(dividend)->getIntegerQuotient(this);
}

Integer *const Signed::getInverseRemainder(const Integer *const dividend) const{
	return static_cast<const coma::numb::IntegerArithmetic<Signed, Integer> *const>(dividend)->getRemainder(this);
}

Integer *const Signed::getIntegerQuotient(const Signed *const toDivide) const{//TODO optimize
	util::RuntimeArray<unsigned char>
		left { this    ->getArray().length() + 1, this    ->isNegative() ? 0xFF : 0 },
		right{ toDivide->getArray().length() + 1, toDivide->isNegative() ? 0xFF : 0 };
	std::copy(this    ->getArray().begin(), this    ->getArray().end(), left .begin());
	std::copy(toDivide->getArray().begin(), toDivide->getArray().end(), right.begin());
	if(this    ->isNegative()) util::negate(left);
	if(toDivide->isNegative()) util::negate(right);
	left /= right;
	if(this->isNegative() != toDivide->isNegative()) util::negate(left);
	return fromLittleEndianArray(left);
}

Integer *const Signed::getRemainder(const Signed *const toDivide) const{//TODO test and improve later
	util::RuntimeArray<unsigned char>
		left { std::max(this->getArray().length(), toDivide->getArray().length()) + 1, this    ->isNegative() ? 0xFF : 0 },
		right{ std::max(this->getArray().length(), toDivide->getArray().length()) + 1, toDivide->isNegative() ? 0xFF : 0 };
	std::copy(this    ->getArray().begin(), this    ->getArray().end(), left .begin());
	std::copy(toDivide->getArray().begin(), toDivide->getArray().end(), right.begin());
	if(this    ->isNegative()) util::negate(left);
	if(toDivide->isNegative()) util::negate(right);
	left %= right;
	if(this->isNegative() != toDivide->isNegative()){
		if([](const util::RuntimeArray<unsigned char> &check){
			for(unsigned long long i = 0; i < check.length(); ++i){
				if(check[i] != 0) return true;
			}
			return false;
		}(left)){
			util::RuntimeArray<unsigned char> zero { 1 };
			util::negate(left);
			left += right;
		}
	}
	return fromLittleEndianArray(left);
}

Integer *const Signed::getIntegerQuotientInverse(const Signed *const dividend) const{
	return static_cast<const coma::numb::IntegerArithmetic<Signed, Integer> *const>(dividend)->getIntegerQuotient(this);
}

Integer *const Signed::getInverseRemainder(const Signed *const dividend) const{
	return static_cast<const coma::numb::IntegerArithmetic<Signed, Integer> *const>(dividend)->getRemainder(this);
}

Integer *const Signed::getIntegerQuotient(const Unsigned *const toDivide) const{
	std::unique_ptr<coma::numb::IntegerArithmetic<Signed, Integer> > left { toDivide->getAsSignedInteger() };
	return left->getIntegerQuotientInverse(this);
}

Integer *const Signed::getRemainder(const Unsigned *const toDivide) const{
	std::unique_ptr<coma::numb::IntegerArithmetic<Signed, Integer> > left { toDivide->getAsSignedInteger() };
	return left->getInverseRemainder(this);
}

Integer *const Signed::getIntegerQuotientInverse(const Unsigned *const dividend) const{
	std::unique_ptr<coma::numb::IntegerArithmetic<Signed, Integer> > left { dividend->getAsSignedInteger() };
	return left->getIntegerQuotient(this);
}

Integer *const Signed::getInverseRemainder(const Unsigned *const dividend) const{
	std::unique_ptr<coma::numb::IntegerArithmetic<Signed, Integer> > left { dividend->getAsSignedInteger() };
	return left->getRemainder(this);
}

} /* namespace numb */
} /* namespace coma */
