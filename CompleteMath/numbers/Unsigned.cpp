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

Unsigned::Unsigned(const tech::RuntimeArray<unsigned char> &array, const Endianess endianess) :
		Integer(util::withoutMeaninglessChars(array, false), endianess){}

Pointer< Unsigned> Unsigned::fromBigEndianArray(const tech::RuntimeArray<unsigned char> &array){
	return std::make_shared<Unsigned>(array, Endianess::Big);
}

Pointer< Unsigned> Unsigned::fromLittleEndianArray(const tech::RuntimeArray<unsigned char> &array){
	return std::make_shared<Unsigned>(array, Endianess::Little);
}

Pointer< Unsigned> Unsigned::fromBinaryInString(const std::string &binaryInString){
	return fromHexadecimalInString(util::BaseConverter("01","0123456789ABCDEF").convert(binaryInString));
}

Pointer< Unsigned> Unsigned::fromOctalInString(const std::string &octalInString){
	return fromHexadecimalInString(util::BaseConverter("01234567","0123456789ABCDEF").convert(octalInString));
}

Pointer< Unsigned> Unsigned::fromDecimalInString(const std::string &decimalInString){
	return fromHexadecimalInString(util::BaseConverter::decimalToHexConverter().convert(decimalInString));
}

Pointer< Unsigned> Unsigned::fromHexadecimalInString(const std::string &hexadecimalInString){
	std::unique_ptr<unsigned char[]> chars{util::numb::arrayFromHexadecimal(hexadecimalInString)};
	unsigned long long length = util::numb::sizeFromHexadecimal(hexadecimalInString);
	return fromLittleEndianArray({chars.get(), length});
}

//======================================
//--------------COPYABLE----------------
//======================================

Pointer< Number> Unsigned::copy() const{
	return getAsUnsignedInteger();
}

//======================================
//-------------ARITHMETIC---------------
//======================================

Pointer< Number> Unsigned::getSum(Pointer< Number> toAdd) const{
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toAdd->getSum(sharedThis());
}

Pointer< Number> Unsigned::getSum(Pointer< Complex> toAdd) const{
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toAdd->getSum(sharedThis());
}

Pointer< Number> Unsigned::getSum(Pointer< FloatingPoint> toAdd) const{
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toAdd->getSum(sharedThis());
}

Pointer< Number> Unsigned::getSum(Pointer< Signed> toAdd) const{
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toAdd->getSum(sharedThis());
}

Pointer< Number> Unsigned::getSum(Pointer< Unsigned> toAdd) const{
	using namespace util;
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	tech::RuntimeArray<unsigned char> tmp(std::max(this->getArray().length(), toAdd->getArray().length()) + 1);
	std::copy(getArray().begin(), getArray().end(), tmp.begin());
	tmp += toAdd->getArray();
	return fromLittleEndianArray(tmp);
}

Pointer< Number> Unsigned::getProduct(Pointer< Number> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toMultiply->getProduct(sharedThis());
}

Pointer< Number> Unsigned::getProduct(Pointer< Complex> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toMultiply->getProduct(sharedThis());
}

Pointer< Number> Unsigned::getProduct(Pointer< FloatingPoint> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toMultiply->getProduct(sharedThis());
}

Pointer< Number> Unsigned::getProduct(Pointer< Signed> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toMultiply->getProduct(sharedThis());
}

Pointer< Number> Unsigned::getProduct(Pointer< Unsigned> toMultiply) const{
	using namespace util;
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	tech::RuntimeArray<unsigned char> tmp(this->getArray().length() + toMultiply->getArray().length());
	std::copy(getArray().begin(), getArray().end(), tmp.begin());
	tmp *= toMultiply->getArray();
	return fromLittleEndianArray(tmp);
}

//======================================
//---------------NUMBER-----------------
//======================================

bool Unsigned::isZero() const noexcept{
	return getArray().length() == 1 && getArray()[0] == 0;
}

std::string Unsigned::getAsBinary() const {
	std::string num = getAsHexadecimal();
	return coma::util::BaseConverter("01234567890ABCDEF", "01").convert(num);
}

std::string Unsigned::getAsOctal() const {
	std::string num = getAsHexadecimal();
	return coma::util::BaseConverter("01234567890ABCDEF", "01234567").convert(num);
}

std::string Unsigned::getAsDecimal() const {
	std::string num = getAsHexadecimal();
	return coma::util::BaseConverter::hexToDecimalConverter().convert(num);
}

std::string Unsigned::getAsHexadecimal() const {
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

Pointer< Unsigned> Unsigned::getAsUnsignedInteger() const{
	return fromLittleEndianArray(getArray());
}

Pointer< Signed> Unsigned::getAsSignedInteger() const{
	tech::RuntimeArray<unsigned char> tmp(getArray().length() + 1);
	std::copy(getArray().begin(), getArray().end(), tmp.begin());
	return Signed::fromLittleEndianArray(tmp);
}

Pointer< FloatingPoint> Unsigned::getAsFloatingPoint() const{
	return FloatingPoint::fromFraction(sharedThis(),
			ONE(),
			ZERO());
}

Pointer< Complex> Unsigned::getAsComplex() const{
	//TODO complete after Complex definition
}

Pointer< Number> Unsigned::getNegation() const{
	return getAsSignedInteger()->getNegation();
}

Pointer< Number> Unsigned::getInversion() const{
	return FloatingPoint::fromFraction(std::static_pointer_cast<const Integer>(ONE()),
			sharedThis(),
			ZERO());
}

bool Unsigned::isNegative() const noexcept{
	return false;
}

bool Unsigned::isPositive() const noexcept{
	return !isZero();
}

//======================================
//---------INTEGERARITHMETIC------------
//======================================

Pointer< Integer> Unsigned::getIntegerQuotient(Pointer< Integer> toDivide) const{
	if(!toDivide) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return std::static_pointer_cast<
			const coma::numb::IntegerArithmetic<Pointer< Unsigned> , Pointer< Integer> >>(
					toDivide)->getIntegerQuotientInverse(sharedThis());
}

Pointer< Integer> Unsigned::getRemainder(Pointer< Integer> toDivide) const{
	if(!toDivide) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return std::static_pointer_cast<
			const coma::numb::IntegerArithmetic<Pointer< Unsigned> , Pointer< Integer> >>(
					toDivide)->getInverseRemainder(sharedThis());
}

Pointer< Integer> Unsigned::getIntegerQuotientInverse(Pointer< Integer> dividend) const{
	if(!dividend) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return std::static_pointer_cast<
			const coma::numb::IntegerArithmetic<Pointer< Unsigned> , Pointer< Integer> >>(
					dividend)->getIntegerQuotient(sharedThis());
}

Pointer< Integer> Unsigned::getInverseRemainder(Pointer< Integer> dividend) const{
	if(!dividend) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return std::static_pointer_cast<
			const coma::numb::IntegerArithmetic<Pointer< Unsigned> , Pointer< Integer> >>(
					dividend)->getInverseRemainder(sharedThis());
}

Pointer< Integer> Unsigned::getIntegerQuotient(Pointer< Signed> toDivide) const{
	if(!toDivide) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return std::static_pointer_cast<
			const coma::numb::IntegerArithmetic<Pointer< Unsigned> , Pointer< Integer> >>(
					toDivide)->getIntegerQuotientInverse(sharedThis());
}

Pointer< Integer> Unsigned::getRemainder(Pointer< Signed> toDivide) const{
	if(!toDivide) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return std::static_pointer_cast<
			const coma::numb::IntegerArithmetic<Pointer< Unsigned> , Pointer< Integer> >>(
					toDivide)->getInverseRemainder(sharedThis());
}

Pointer< Integer> Unsigned::getIntegerQuotientInverse(Pointer< Signed> dividend) const{
	if(!dividend) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return std::static_pointer_cast<
			const coma::numb::IntegerArithmetic<Pointer< Unsigned> , Pointer< Integer> >>(
					dividend)->getIntegerQuotient(sharedThis());
}

Pointer< Integer> Unsigned::getInverseRemainder(Pointer< Signed> dividend) const{
	if(!dividend) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return std::static_pointer_cast<
			const coma::numb::IntegerArithmetic<Pointer< Unsigned> , Pointer< Integer> >>(
					dividend)->getRemainder(sharedThis());
}

Pointer< Integer> Unsigned::getIntegerQuotient(Pointer< Unsigned> toDivide) const{
	using namespace util;
	if(!toDivide) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	if(toDivide->isZero()) REPORT_ERROR(std::exception("Division by zero exception"), nullptr);
	tech::RuntimeArray<unsigned char> result = getArray();
	result /= toDivide->getArray();
	return fromLittleEndianArray(result);
}

Pointer< Integer> Unsigned::getRemainder(Pointer< Unsigned> toDivide) const{
	using namespace util;
	if(!toDivide) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	if(toDivide->isZero()) REPORT_ERROR(std::exception("Division by zero exception"), nullptr);
	tech::RuntimeArray<unsigned char> result = getArray();
	result %= toDivide->getArray();
	return fromLittleEndianArray(result);
}

Pointer< Integer> Unsigned::getIntegerQuotientInverse(Pointer< Unsigned> dividend) const{
	if(!dividend) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return std::static_pointer_cast<
			const coma::numb::IntegerArithmetic<Pointer< Unsigned> , Pointer< Integer> >>(
					dividend)->getIntegerQuotient(sharedThis());
}

Pointer< Integer> Unsigned::getInverseRemainder(Pointer< Unsigned> dividend) const{
	if(!dividend) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return std::static_pointer_cast<
			const coma::numb::IntegerArithmetic<Pointer< Unsigned> , Pointer< Integer> >>(
					dividend)->getRemainder(sharedThis());
}

Pointer< Unsigned> Unsigned::sharedThis() const{
	return std::static_pointer_cast<const Unsigned>(shared_from_this());
}

} /* namespace numb */
} /* namespace coma */
