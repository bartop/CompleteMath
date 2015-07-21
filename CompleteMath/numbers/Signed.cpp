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

Signed *const Signed::fromHexadecimalInString(const std::string &hexadecimalInString){//TODO testing, testing
	std::unique_ptr<unsigned char[]> chars{ util::numb::arrayFromSignedHexadecimal(hexadecimalInString) };
	unsigned long long length { util::numb::sizeFromSignedHexadecimal(hexadecimalInString) };
	return fromLittleEndianArray({chars.get(), length});
}

	//======================================
	//-------------ARITHMETIC---------------
	//======================================

	Number *const Signed::getSum(const Number *const toAdd) const{
		return static_cast<const coma::numb::Arithmetic<Signed, Number> *const>(toAdd)->getSum(this);
	}

	Number *const Signed::getSum(const Complex *const toAdd) const{
		return static_cast<const coma::numb::Arithmetic<Signed, Number> *const>(toAdd)->getSum(this);
	}

	Number *const Signed::getSum(const FloatingPoint *const toAdd) const{
		return static_cast<const coma::numb::Arithmetic<Signed, Number> *const>(toAdd)->getSum(this);
	}

	Number *const Signed::getSum(const Signed *const toAdd) const{
		util::RuntimeArray<unsigned char> tmp1
			{ std::max(toAdd->getArray().length(), this->getArray().length()), this->isNegative() ? 0xFF : 0 };
		util::RuntimeArray<unsigned char> tmp2
			{ std::max(toAdd->getArray().length(), this->getArray().length()), toAdd->isNegative() ? 0xFF : 0 };
		std::copy(this->getArray().begin(), this->getArray().end(), tmp1.begin());
		std::copy(toAdd->getArray().begin(), toAdd->getArray().end(), tmp2.begin());
		tmp1 += tmp2;
		return fromLittleEndianArray(tmp1);
	}

	Number *const Signed::getSum(const Unsigned *const toAdd) const{
		std::unique_ptr<coma::numb::Arithmetic<Signed, Number> > left { toAdd->getAsSignedInteger() };
		return left->getSum(this);
	}

	Number *const Signed::getDifference(const Number *const toSubtract) const{
		return static_cast<const coma::numb::Arithmetic<Signed, Number> *const>(toSubtract)->getDifferenceNegation(this);
	}

	Number *const Signed::getDifference(const Complex *const toSubtract) const{
		return static_cast<const coma::numb::Arithmetic<Signed, Number> *const>(toSubtract)->getDifferenceNegation(this);
	}

	Number *const Signed::getDifference(const FloatingPoint *const toSubtract) const{
		return static_cast<const coma::numb::Arithmetic<Signed, Number> *const>(toSubtract)->getDifferenceNegation(this);
	}

	Number *const Signed::getDifference(const Signed *const toSubtract) const{//TODO this is bulls**t, have to rewrite it
		std::unique_ptr<coma::numb::Arithmetic<Number> > right{ toSubtract->getNegation() };
		return right->getSum(this);
	}

	Number *const Signed::getDifference(const Unsigned *const toSubtract) const{
		std::unique_ptr<coma::numb::Arithmetic<Signed, Number> > left { toSubtract->getAsSignedInteger() };
		return left->getDifferenceNegation(this);
	}

	Number *const Signed::getProduct(const Number *const toMultiply) const{
		return static_cast<const coma::numb::Arithmetic<Signed, Number> *const>(toMultiply)->getProduct(this);
	}

	Number *const Signed::getProduct(const Complex *const toMultiply) const{
		return static_cast<const coma::numb::Arithmetic<Signed, Number> *const>(toMultiply)->getProduct(this);
	}

	Number *const Signed::getProduct(const FloatingPoint *const toMultiply) const{
		return static_cast<const coma::numb::Arithmetic<Signed, Number> *const>(toMultiply)->getProduct(this);
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
		std::unique_ptr<coma::numb::Arithmetic<Signed, Number> > left { toMultiply->getAsSignedInteger() };
		return left->getProduct(this);
	}

	Number *const Signed::getQuotient(const Number *const toDivide) const{
		return static_cast<const coma::numb::Arithmetic<Signed, Number> *const>(toDivide)->getQuotientInverse(this);
	}

	Number *const Signed::getQuotient(const Complex *const toDivide) const{
		return static_cast<const coma::numb::Arithmetic<Signed, Number> *const>(toDivide)->getQuotientInverse(this);
	}

	Number *const Signed::getQuotient(const FloatingPoint *const toDivide) const{
		return static_cast<const coma::numb::Arithmetic<Signed, Number> *const>(toDivide)->getQuotientInverse(this);
	}

	Number *const Signed::getQuotient(const Signed *const toDivide) const{
		std::unique_ptr<coma::numb::Arithmetic<Signed, Number> > left{ toDivide->getAsFloatingPoint() };
		return left->getQuotientInverse(this);
	}

	Number *const Signed::getQuotient(const Unsigned *const toDivide) const{
		std::unique_ptr<coma::numb::Arithmetic<Signed, Number> > left { toDivide->getAsFloatingPoint() };
		return left->getQuotientInverse(this);
	}

	Number *const Signed::getDifferenceNegation(const Number *const minuend) const{
		return static_cast<const coma::numb::Arithmetic<Signed, Number> *const>(minuend)->getDifference(this);
	}

	Number *const Signed::getDifferenceNegation(const Complex *const minuend) const{
		return static_cast<const coma::numb::Arithmetic<Signed, Number> *const>(minuend)->getDifference(this);
	}

	Number *const Signed::getDifferenceNegation(const FloatingPoint *const minuend) const{
		return static_cast<const coma::numb::Arithmetic<Signed, Number> *const>(minuend)->getDifference(this);
	}

	Number *const Signed::getDifferenceNegation(const Signed *const minuend) const{
		return static_cast<const coma::numb::Arithmetic<Signed, Number> *const>(minuend)->getDifference(this);
	}

	Number *const Signed::getDifferenceNegation(const Unsigned *const minuend) const{
		std::unique_ptr<coma::numb::Arithmetic<Signed, Number> > left { minuend->getAsSignedInteger() };
		return left->getDifference(this);
	}

	Number *const Signed::getQuotientInverse(const Number *const dividend) const{
		return static_cast<const coma::numb::Arithmetic<Signed, Number> *const>(dividend)->getQuotient(this);
	}

	Number *const Signed::getQuotientInverse(const Complex *const dividend) const{
		return static_cast<const coma::numb::Arithmetic<Signed, Number> *const>(dividend)->getQuotient(this);
	}

	Number *const Signed::getQuotientInverse(const FloatingPoint *const dividend) const{
		return static_cast<const coma::numb::Arithmetic<Signed, Number> *const>(dividend)->getQuotient(this);
	}

	Number *const Signed::getQuotientInverse(const Signed *const dividend) const{
		return static_cast<const coma::numb::Arithmetic<Signed, Number> *const>(dividend)->getQuotient(this);
	}

	Number *const Signed::getQuotientInverse(const Unsigned *const dividend) const{
		std::unique_ptr<coma::numb::Arithmetic<Signed, Number> > left { dividend->getAsSignedInteger() };
		return left->getQuotient(this);
	}

	//======================================
	//---------------NUMBER-----------------
	//======================================

	const bool Signed::isZero() const{//TODO tests
		return getArray().length() == 1 && getArray()[0] == 0;
	}

	const std::string Signed::getAsBinary() const{
		std::string result = getAsHexadecimal();
		return result[0] + util::BaseConverter("0123456789ABCDEF", "01").convert(result.substr(1, result.length() - 1));
	}

	const std::string Signed::getAsOctal() const{
		std::string result = getAsHexadecimal();
		return result[0] + util::BaseConverter("0123456789ABCDEF", "01234567").convert(result.substr(1, result.length() - 1));
	}

	const std::string Signed::getAsDecimal() const{
		std::string result = getAsHexadecimal();
		return result[0] + util::BaseConverter("0123456789ABCDEF", "0123456789").convert(result.substr(1, result.length() - 1));
	}

	const std::string Signed::getAsHexadecimal() const{
		if(!isNegative()) return "+"+std::unique_ptr<Number>(getAsUnsignedInteger())->getAsHexadecimal();
		else{
			return "-"+std::unique_ptr<Number>(getNegation())->getAsHexadecimal();
		}
	}

	Unsigned *const Signed::getAsUnsignedInteger() const{
		return Unsigned::fromLittleEndianArray(getArray());
	}

	Signed *const Signed::getAsSignedInteger() const{
		return fromLittleEndianArray(getArray());
	}

	FloatingPoint *const Signed::getAsFloatingPoint() const{
		//TODO complete after FloatingPoint definition
	}

	Complex *const Signed::getAsComplex() const{
		//TODO complete after Complex definition
	}

	Number *const Signed::getNegation() const{
		util::RuntimeArray<unsigned char> tmp { getArray().length() + 1 };
		std::copy(getArray().begin(), getArray().end(), tmp.begin());
		util::negate(tmp);
		return fromLittleEndianArray(tmp);
	}

	Number *const Signed::getInversion() const{
		//TODO finish after FloatingPoint definition
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

	Integer *const Signed::getIntegerQuotient(const Signed *const toDivide) const{//TODO test, then optimize
		std::unique_ptr<Integer> left{}, right{}, result{};
		if(this->isNegative()){
			left.reset(std::unique_ptr<Number>(this->getNegation())->getAsUnsignedInteger());
		}else{
			left.reset(this->getAsUnsignedInteger());
		}
		if(toDivide->isNegative()){
			left.reset(std::unique_ptr<Number>(toDivide->getNegation())->getAsUnsignedInteger());
		}else{
			left.reset(toDivide->getAsUnsignedInteger());
		}
		result.reset(static_cast<const coma::numb::IntegerArithmetic<Integer> *const>(left.get())->getIntegerQuotient(right.get()));
		if(this->isNegative() != toDivide->isNegative()) result.reset(std::unique_ptr<Number>(result->getNegation())->getAsSignedInteger());
		return result.release();
	}

	Integer *const Signed::getRemainder(const Signed *const toDivide) const{//TODO test and improve later
		std::unique_ptr<Integer> left{}, right{}, result{};
		if(this->isNegative()){
			left.reset(std::unique_ptr<Number>(this->getNegation())->getAsUnsignedInteger());
		}else{
			left.reset(this->getAsUnsignedInteger());
		}
		if(toDivide->isNegative()){
			left.reset(std::unique_ptr<Number>(toDivide->getNegation())->getAsUnsignedInteger());
		}else{
			left.reset(toDivide->getAsUnsignedInteger());
		}
		result.reset(static_cast<const coma::numb::IntegerArithmetic<Integer> *const>(left.get())->getRemainder(right.get()));
		if(this->isNegative() != toDivide->isNegative()){
			result.reset(std::unique_ptr<Number>(static_cast<const coma::numb::Arithmetic<Number> *const>(right.get())->
					getDifference(result.get()))->getAsSignedInteger());
		}
		return result.release();
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


Signed::~Signed(){
}

} /* namespace numb */
} /* namespace coma */
