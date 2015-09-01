/*
 * Signed.cpp
 *
 *  Created on: 27 cze 2015
 *      Author: Bartosz Miera
 */


#include "Signed.h"
#include "../Utility/Numbers.h"
#include "../Utility/BaseConverter.h"
#include "../Technical/RuntimeArray.h"
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

Signed::Signed(const tech::RuntimeArray<unsigned char> &array,
		const Endianess endianess) :
				Integer( util::withoutMeaninglessChars(array, true) , endianess){}

Signed *Signed::fromBigEndianArray(const tech::RuntimeArray<unsigned char> &array){
	return new Signed{ array, Endianess::Big };
}

Signed *Signed::fromLittleEndianArray(const tech::RuntimeArray<unsigned char> &array){
	return new Signed{ array, Endianess::Little };
}

Signed *Signed::fromBinaryInString(const std::string &binaryInString){
	return fromHexadecimalInString(
			binaryInString[0] + coma::util::BaseConverter("01","0123456789ABCDEF").
			convert(binaryInString.substr(1, binaryInString.length() - 1)));
}

Signed *Signed::fromOctalInString(const std::string &octalInString){
	return fromHexadecimalInString(
			octalInString[0] + coma::util::BaseConverter("01234567","0123456789ABCDEF").
			convert(octalInString.substr(1, octalInString.length() - 1)));
}

Signed *Signed::fromDecimalInString(const std::string &decimalInString){
	return fromHexadecimalInString(
			decimalInString[0] + coma::util::BaseConverter("0123456789","0123456789ABCDEF").
			convert(decimalInString.substr(1, decimalInString.length() - 1)));
}

Signed *Signed::fromHexadecimalInString(const std::string &hexadecimalInString){
	std::unique_ptr<unsigned char[]> chars{ util::numb::arrayFromSignedHexadecimal(hexadecimalInString) };
	unsigned long long length { util::numb::sizeFromSignedHexadecimal(hexadecimalInString) };
	return fromLittleEndianArray(tech::RuntimeArray<unsigned char>(chars.get(), length));
}

//======================================
//--------------COPYABLE----------------
//======================================

Number *Signed::copy() const{
	return getAsSignedInteger();
}

//======================================
//-------------ARITHMETIC---------------
//======================================

Number *Signed::getSum(const Number *toAdd) const{
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toAdd->getSum(this);
}

Number *Signed::getSum(const Complex *toAdd) const{
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toAdd->getSum(this);
}

Number *Signed::getSum(const FloatingPoint *toAdd) const{
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toAdd->getSum(this);
}

Number *Signed::getSum(const Signed *toAdd) const{
	using namespace util;
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	tech::RuntimeArray<unsigned char> tmp1
		(1 + std::max(toAdd->getArray().length(), this->getArray().length()), this->isNegative() ? 0xFF : 0);
	tech::RuntimeArray<unsigned char> tmp2
		(1 + std::max(toAdd->getArray().length(), this->getArray().length()), toAdd->isNegative() ? 0xFF : 0);
	std::copy(this->getArray().begin(), this->getArray().end(), tmp1.begin());
	std::copy(toAdd->getArray().begin(), toAdd->getArray().end(), tmp2.begin());
	tmp1 += tmp2;
	return fromLittleEndianArray(tmp1);
}

Number *Signed::getSum(const Unsigned *toAdd) const{
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	std::unique_ptr<coma::numb::Signed> left { toAdd->getAsSignedInteger() };
	return left->getSum(this);
}

Number *Signed::getProduct(const Number *toMultiply) const{
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toMultiply->getProduct(this);
}

Number *Signed::getProduct(const Complex *toMultiply) const{
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toMultiply->getProduct(this);
}

Number *Signed::getProduct(const FloatingPoint *toMultiply) const{
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toMultiply->getProduct(this);
}

Number *Signed::getProduct(const Signed *toMultiply) const{
	using namespace util;
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	tech::RuntimeArray<unsigned char>
		tmp1(this->getArray().length() + toMultiply->getArray().length() + 2, this->isNegative() ? 0xFF : 0),
		tmp2(this->getArray().length() + toMultiply->getArray().length() + 2, toMultiply->isNegative() ? 0xFF : 0);
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

Number *Signed::getProduct(const Unsigned *toMultiply) const{
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	std::unique_ptr<coma::numb::Signed> left { toMultiply->getAsSignedInteger() };
	return left->getProduct(this);
}

//======================================
//---------------NUMBER-----------------
//======================================

const bool Signed::isZero() const noexcept{
	return getArray().length() == 1 && getArray()[0] == 0;
}

const std::string Signed::getAsBinary() const noexcept{
	std::string result = getAsHexadecimal();
	if(isNegative())
		return result[0] + util::BaseConverter("0123456789ABCDEF", "01").convert(result.substr(1, result.length() - 1));
	else return util::BaseConverter("0123456789ABCDEF", "01").convert(result.substr(0, result.length()));
}

const std::string Signed::getAsOctal() const noexcept{
	std::string result = getAsHexadecimal();
	if(isNegative())
		return result[0] + util::BaseConverter("0123456789ABCDEF", "01234567").convert(result.substr(1, result.length() - 1));
	else return util::BaseConverter("0123456789ABCDEF", "01234567").convert(result.substr(0, result.length()));
}

const std::string Signed::getAsDecimal() const noexcept{
	std::string result = getAsHexadecimal();
	if(isNegative())
		return result[0] + util::BaseConverter("0123456789ABCDEF", "0123456789").convert(result.substr(1, result.length() - 1));
	else return util::BaseConverter("0123456789ABCDEF", "0123456789").convert(result.substr(0, result.length()));
}

const std::string Signed::getAsHexadecimal() const noexcept{
	if(!isNegative()) return std::unique_ptr<Number>(getAsUnsignedInteger())->getAsHexadecimal();
	else return "-"+std::unique_ptr<Number>(getNegation())->getAsHexadecimal();

}

Unsigned *Signed::getAsUnsignedInteger() const{
	return Unsigned::fromLittleEndianArray(getArray());
}

Signed *Signed::getAsSignedInteger() const{
	return fromLittleEndianArray(getArray());
}

FloatingPoint *Signed::getAsFloatingPoint() const{
	return FloatingPoint::fromFraction(this,
			ONE(),
			ZERO());
}

Complex *Signed::getAsComplex() const{
	//TODO complete after Complex definition
}

Number *Signed::getNegation() const{
	tech::RuntimeArray<unsigned char> tmp(getArray().length() + 1, isNegative() ? 0xFF : 0);
	std::copy(getArray().begin(), getArray().end(), tmp.begin());
	util::negate(tmp);
	if(isNegative()) return Unsigned::fromLittleEndianArray(tmp);
	else return Signed::fromLittleEndianArray(tmp);
}

Number *Signed::getInversion() const{
	return FloatingPoint::fromFraction(ONE(),
			this,
			ZERO());
}

const bool Signed::isNegative() const noexcept{
	return getArray()[getArray().length() - 1] & 0x80;
}

const bool Signed::isPositive() const noexcept{
	return !isNegative() && !isZero();
}

//======================================
//---------INTEGERARITHMETIC------------
//======================================

Integer *Signed::getIntegerQuotient(const Integer *toDivide) const{
	if(!toDivide) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	if(toDivide->isZero()) REPORT_ERROR(std::exception("Division by zero exception"), nullptr);
	return static_cast<const coma::numb::IntegerArithmetic<Signed, Integer> *const>(toDivide)->getIntegerQuotientInverse(this);
}

Integer *Signed::getRemainder(const Integer *toDivide) const{
	if(!toDivide) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	if(toDivide->isZero()) REPORT_ERROR(std::exception("Division by zero exception"), nullptr);
	return static_cast<const coma::numb::IntegerArithmetic<Signed, Integer> *const>(toDivide)->getInverseRemainder(this);
}

Integer *Signed::getIntegerQuotientInverse(const Integer *dividend) const{
	if(!dividend) REPORT_ERROR(std::exception("null pointer exception"), nullptr);
	if(dividend->isZero()) REPORT_ERROR(std::exception("division by zero exception"), nullptr);
	return static_cast<const coma::numb::IntegerArithmetic<Signed, Integer> *const>(dividend)->getIntegerQuotient(this);
}

Integer *Signed::getInverseRemainder(const Integer *dividend) const{
	if(!dividend) REPORT_ERROR(std::exception("null pointer exception"), nullptr);
	if(dividend->isZero()) REPORT_ERROR(std::exception("division by zero exception"), nullptr);
	return static_cast<const coma::numb::IntegerArithmetic<Signed, Integer> *const>(dividend)->getRemainder(this);
}

Integer *Signed::getIntegerQuotient(const Signed *toDivide) const{//TODO optimize
	using namespace util;
	if(!toDivide) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	if(toDivide->isZero()) REPORT_ERROR(std::exception("Division by zero exception"), nullptr);
	tech::RuntimeArray<unsigned char>
		left (this    ->getArray().length() + 1, this    ->isNegative() ? 0xFF : 0),
		right(toDivide->getArray().length() + 1, toDivide->isNegative() ? 0xFF : 0);
	std::copy(this    ->getArray().begin(), this    ->getArray().end(), left .begin());
	std::copy(toDivide->getArray().begin(), toDivide->getArray().end(), right.begin());
	if(this    ->isNegative()) util::negate(left);
	if(toDivide->isNegative()) util::negate(right);
	left /= right;
	if(this->isNegative() != toDivide->isNegative()) util::negate(left);
	return fromLittleEndianArray(left);
}

Integer *Signed::getRemainder(const Signed *toDivide) const{//TODO test and improve later
	using namespace util;
	if(!toDivide) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	if(toDivide->isZero()) REPORT_ERROR(std::exception("Division by zero exception"), nullptr);
	tech::RuntimeArray<unsigned char>
		left(std::max(this->getArray().length(), toDivide->getArray().length()) + 1, this    ->isNegative() ? 0xFF : 0),
		right(std::max(this->getArray().length(), toDivide->getArray().length()) + 1, toDivide->isNegative() ? 0xFF : 0);
	std::copy(this    ->getArray().begin(), this    ->getArray().end(), left .begin());
	std::copy(toDivide->getArray().begin(), toDivide->getArray().end(), right.begin());
	if(this    ->isNegative()) util::negate(left);
	if(toDivide->isNegative()) util::negate(right);
	left %= right;
	if(this->isNegative() != toDivide->isNegative()){
		if([](const tech::RuntimeArray<unsigned char> &check){
			for(unsigned long long i = 0; i < check.length(); ++i){
				if(check[i] != 0) return true;
			}
			return false;
		}(left)){
			tech::RuntimeArray<unsigned char> zero(1);
			util::negate(left);
			left += right;
		}
	}
	return fromLittleEndianArray(left);
}

Integer *Signed::getIntegerQuotientInverse(const Signed *dividend) const{
	if(!dividend) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	if(dividend->isZero()) REPORT_ERROR(std::exception("Division by zero exception"), nullptr);
	return static_cast<const coma::numb::IntegerArithmetic<Signed, Integer> *const>(dividend)->getIntegerQuotient(this);
}

Integer *Signed::getInverseRemainder(const Signed *dividend) const{
	if(!dividend) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	if(dividend->isZero()) REPORT_ERROR(std::exception("Division by zero exception"), nullptr);
	return static_cast<const coma::numb::IntegerArithmetic<Signed, Integer> *const>(dividend)->getRemainder(this);
}

Integer *Signed::getIntegerQuotient(const Unsigned *toDivide) const{
	if(!toDivide) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	if(toDivide->isZero()) REPORT_ERROR(std::exception("Division by zero exception"), nullptr);
	std::unique_ptr<coma::numb::IntegerArithmetic<Signed, Integer> > left { toDivide->getAsSignedInteger() };
	return left->getIntegerQuotientInverse(this);
}

Integer *Signed::getRemainder(const Unsigned *toDivide) const{
	if(!toDivide) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	if(toDivide->isZero()) REPORT_ERROR(std::exception("Division by zero exception"), nullptr);
	std::unique_ptr<coma::numb::IntegerArithmetic<Signed, Integer> > left { toDivide->getAsSignedInteger() };
	return left->getInverseRemainder(this);
}

Integer *Signed::getIntegerQuotientInverse(const Unsigned *dividend) const{
	if(!dividend) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	if(dividend->isZero()) REPORT_ERROR(std::exception("Division by zero exception"), nullptr);
	std::unique_ptr<coma::numb::IntegerArithmetic<Signed, Integer> > left { dividend->getAsSignedInteger() };
	return left->getIntegerQuotient(this);
}

Integer *Signed::getInverseRemainder(const Unsigned *dividend) const{
	if(!dividend) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	if(dividend->isZero()) REPORT_ERROR(std::exception("Division by zero exception"), nullptr);
	std::unique_ptr<coma::numb::IntegerArithmetic<Signed, Integer> > left { dividend->getAsSignedInteger() };
	return left->getRemainder(this);
}

} /* namespace numb */
} /* namespace coma */
