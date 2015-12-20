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

Pointer<const Signed> Signed::fromBigEndianArray(const tech::RuntimeArray<unsigned char> &array){
	return std::make_shared<Signed>(array, Endianess::Big);
}

Pointer<const Signed> Signed::fromLittleEndianArray(const tech::RuntimeArray<unsigned char> &array){
	return std::make_shared<Signed>(array, Endianess::Little);
}

Pointer<const Signed> Signed::fromBinaryInString(const std::string &binaryInString){
	return fromHexadecimalInString(
			binaryInString[0] + coma::util::BaseConverter("01","0123456789ABCDEF").
			convert(binaryInString.substr(1, binaryInString.length() - 1)));
}

Pointer<const Signed> Signed::fromOctalInString(const std::string &octalInString){
	return fromHexadecimalInString(
			octalInString[0] + coma::util::BaseConverter("01234567","0123456789ABCDEF").
			convert(octalInString.substr(1, octalInString.length() - 1)));
}

Pointer<const Signed> Signed::fromDecimalInString(const std::string &decimalInString){
	return fromHexadecimalInString(
			decimalInString[0] + coma::util::BaseConverter("0123456789","0123456789ABCDEF").
			convert(decimalInString.substr(1, decimalInString.length() - 1)));
}

Pointer<const Signed> Signed::fromHexadecimalInString(const std::string &hexadecimalInString){
	std::unique_ptr<unsigned char[]> chars{ util::numb::arrayFromSignedHexadecimal(hexadecimalInString) };
	unsigned long long length { util::numb::sizeFromSignedHexadecimal(hexadecimalInString) };
	return fromLittleEndianArray(tech::RuntimeArray<unsigned char>(chars.get(), length));
}

//======================================
//--------------COPYABLE----------------
//======================================

Pointer<const Number> Signed::copy() const{
	return getAsSignedInteger();
}

//======================================
//-------------ARITHMETIC---------------
//======================================

Pointer<const Number> Signed::getSum(Pointer<const Number> toAdd) const{
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toAdd->getSum(sharedThis());
}

Pointer<const Number> Signed::getSum(Pointer<const Complex> toAdd) const{
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toAdd->getSum(sharedThis());
}

Pointer<const Number> Signed::getSum(Pointer<const FloatingPoint> toAdd) const{
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toAdd->getSum(sharedThis());
}

Pointer<const Number> Signed::getSum(Pointer<const Signed> toAdd) const{
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

Pointer<const Number> Signed::getSum(Pointer<const Unsigned> toAdd) const{
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toAdd->getAsSignedInteger()->getSum(sharedThis());
}

Pointer<const Number> Signed::getProduct(Pointer<const Number> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toMultiply->getProduct(sharedThis());
}

Pointer<const Number> Signed::getProduct(Pointer<const Complex> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toMultiply->getProduct(sharedThis());
}

Pointer<const Number> Signed::getProduct(Pointer<const FloatingPoint> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toMultiply->getProduct(sharedThis());
}

Pointer<const Number> Signed::getProduct(Pointer<const Signed> toMultiply) const{
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

Pointer<const Number> Signed::getProduct(Pointer<const Unsigned> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toMultiply->getAsSignedInteger()->getProduct(sharedThis());
}

//======================================
//---------------NUMBER-----------------
//======================================

bool Signed::isZero() const noexcept{
	return getArray().length() == 1 && getArray()[0] == 0;
}

std::string Signed::getAsBinary() const noexcept{
	std::string result = getAsHexadecimal();
	if(isNegative())
		return result[0] + util::BaseConverter("0123456789ABCDEF", "01").convert(result.substr(1, result.length() - 1));
	else return util::BaseConverter("0123456789ABCDEF", "01").convert(result.substr(0, result.length()));
}

std::string Signed::getAsOctal() const noexcept{
	std::string result = getAsHexadecimal();
	if(isNegative())
		return result[0] + util::BaseConverter("0123456789ABCDEF", "01234567").convert(result.substr(1, result.length() - 1));
	else return util::BaseConverter("0123456789ABCDEF", "01234567").convert(result.substr(0, result.length()));
}

std::string Signed::getAsDecimal() const noexcept{
	std::string result = getAsHexadecimal();
	if(isNegative())
		return result[0] + util::BaseConverter("0123456789ABCDEF", "0123456789").convert(result.substr(1, result.length() - 1));
	else return util::BaseConverter("0123456789ABCDEF", "0123456789").convert(result.substr(0, result.length()));
}

std::string Signed::getAsHexadecimal() const noexcept{
	if(!isNegative()) return getAsUnsignedInteger()->getAsHexadecimal();
	else return "-"+getNegation()->getAsHexadecimal();

}

Pointer<const Unsigned> Signed::getAsUnsignedInteger() const{
	return Unsigned::fromLittleEndianArray(getArray());
}

Pointer<const Signed> Signed::getAsSignedInteger() const{
	return fromLittleEndianArray(getArray());
}

Pointer<const FloatingPoint> Signed::getAsFloatingPoint() const{
	return FloatingPoint::fromFraction(sharedThis(),
			ONE(),
			ZERO());
}

Pointer<const Complex> Signed::getAsComplex() const{
	//TODO complete after Complex definition
}

Pointer<const Number> Signed::getNegation() const{
	tech::RuntimeArray<unsigned char> tmp(getArray().length() + 1, isNegative() ? 0xFF : 0);
	std::copy(getArray().begin(), getArray().end(), tmp.begin());
	util::negate(tmp);
	if(isNegative()) return Unsigned::fromLittleEndianArray(tmp);
	else return Signed::fromLittleEndianArray(tmp);
}

Pointer<const Number> Signed::getInversion() const{
	return FloatingPoint::fromFraction(ONE(),
			sharedThis(),
			ZERO());
}

bool Signed::isNegative() const noexcept{
	return getArray()[getArray().length() - 1] & 0x80;
}

bool Signed::isPositive() const noexcept{
	return !isNegative() && !isZero();
}

//======================================
//---------INTEGERARITHMETIC------------
//======================================

Pointer<const Integer> Signed::getIntegerQuotient(Pointer<const Integer> toDivide) const{
	if(!toDivide) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	if(toDivide->isZero()) REPORT_ERROR(std::exception("Division by zero exception"), nullptr);
	return std::static_pointer_cast<
			const coma::numb::IntegerArithmetic<Pointer<const Signed>, Pointer<const Integer>>>(
					toDivide)->getIntegerQuotientInverse(sharedThis());
}

Pointer<const Integer> Signed::getRemainder(Pointer<const Integer> toDivide) const{
	if(!toDivide) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	if(toDivide->isZero()) REPORT_ERROR(std::exception("Division by zero exception"), nullptr);
	return std::static_pointer_cast<
			const coma::numb::IntegerArithmetic<Pointer<const Signed>, Pointer<const Integer>>>(
					toDivide)->getInverseRemainder(sharedThis());
}

Pointer<const Integer> Signed::getIntegerQuotientInverse(Pointer<const Integer> dividend) const{
	if(!dividend) REPORT_ERROR(std::exception("null pointer exception"), nullptr);
	if(dividend->isZero()) REPORT_ERROR(std::exception("division by zero exception"), nullptr);
	return std::static_pointer_cast<
			const coma::numb::IntegerArithmetic<Pointer<const Signed>, Pointer<const Integer>>>(
					dividend)->getIntegerQuotient(sharedThis());
}

Pointer<const Integer> Signed::getInverseRemainder(Pointer<const Integer> dividend) const{
	if(!dividend) REPORT_ERROR(std::exception("null pointer exception"), nullptr);
	if(dividend->isZero()) REPORT_ERROR(std::exception("division by zero exception"), nullptr);
	return std::static_pointer_cast<
			const coma::numb::IntegerArithmetic<Pointer<const Signed>, Pointer<const Integer>>>(
					dividend)->getRemainder(sharedThis());
}

Pointer<const Integer> Signed::getIntegerQuotient(Pointer<const Signed> toDivide) const{//TODO optimize
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

Pointer<const Integer> Signed::getRemainder(Pointer<const Signed> toDivide) const{//TODO test and improve later
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

Pointer<const Integer> Signed::getIntegerQuotientInverse(Pointer<const Signed> dividend) const{
	if(!dividend) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	if(dividend->isZero()) REPORT_ERROR(std::exception("Division by zero exception"), nullptr);
	return std::static_pointer_cast<
			const coma::numb::IntegerArithmetic<Pointer<const Signed>, Pointer<const Integer>>>(
					dividend)->getIntegerQuotient(sharedThis());
}

Pointer<const Integer> Signed::getInverseRemainder(Pointer<const Signed> dividend) const{
	if(!dividend) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	if(dividend->isZero()) REPORT_ERROR(std::exception("Division by zero exception"), nullptr);
	return std::static_pointer_cast<
			const coma::numb::IntegerArithmetic<Pointer<const Signed>, Pointer<const Integer>>>(
					dividend)->getRemainder(sharedThis());
}

Pointer<const Integer> Signed::getIntegerQuotient(Pointer<const Unsigned> toDivide) const{//TODO tutaj zacznij robotê
	if(!toDivide) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	if(toDivide->isZero()) REPORT_ERROR(std::exception("Division by zero exception"), nullptr);
	Pointer<const coma::numb::IntegerArithmetic<Pointer<const Signed>, Pointer<const Integer>>>
		left { toDivide->getAsSignedInteger() };
	return left->getIntegerQuotientInverse(sharedThis());
}

Pointer<const Integer> Signed::getRemainder(Pointer<const Unsigned> toDivide) const{
	if(!toDivide) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	if(toDivide->isZero()) REPORT_ERROR(std::exception("Division by zero exception"), nullptr);
	Pointer<const coma::numb::IntegerArithmetic<Pointer<const Signed>, Pointer<const Integer>>>
		left { toDivide->getAsSignedInteger() };
	return left->getInverseRemainder(sharedThis());
}

Pointer<const Integer> Signed::getIntegerQuotientInverse(Pointer<const Unsigned> dividend) const{
	if(!dividend) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	if(dividend->isZero()) REPORT_ERROR(std::exception("Division by zero exception"), nullptr);
	Pointer<const coma::numb::IntegerArithmetic<Pointer<const Signed>, Pointer<const Integer>>>
		left { dividend->getAsSignedInteger() };
	return left->getIntegerQuotient(sharedThis());
}

Pointer<const Integer> Signed::getInverseRemainder(Pointer<const Unsigned> dividend) const{
	if(!dividend) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	if(dividend->isZero()) REPORT_ERROR(std::exception("Division by zero exception"), nullptr);
	Pointer<const coma::numb::IntegerArithmetic<Pointer<const Signed>, Pointer<const Integer>>>
		left { dividend->getAsSignedInteger() };
	return left->getRemainder(sharedThis());
}

Pointer<const Signed> Signed::sharedThis() const{
	return std::static_pointer_cast<const Signed>(shared_from_this());
}

} /* namespace numb */
} /* namespace coma */
