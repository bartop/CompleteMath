/*
 * Signed.cpp
 *
 *  Created on: 27 cze 2015
 *      Author: Bartosz Miera
 */


#include "Signed.h"
#include "../Utility/Numbers.h"
#include "../Utility/BaseConverter.h"
#include "Unsigned.h"
#include "FloatingPoint.h"
#include "Complex.h"
#include <memory>


namespace coma {
namespace numb {

//======================================
//---------------SIGNED-----------------
//======================================

Signed::Signed(const unsigned char *const numbersArray,
		const unsigned long long arrayLenght ,
		const Endianess endianess) :
				Integer(numbersArray, util::numb::getUsedBytesSigned(numbersArray, arrayLenght), endianess){}

Signed *const Signed::fromBigEndianArray(const unsigned char *const numbersArray,
			const unsigned long long arrayLenght){
	return new Signed{ numbersArray, arrayLenght, Endianess::Big };
}

Signed *const Signed::fromLittleEndianArray(const unsigned char *const numbersArray,
			const unsigned long long arrayLenght){
	return new Signed{ numbersArray, arrayLenght, Endianess::Little };
}

Signed *const Signed::fromBinaryInString(const std::string &binaryInString){
	return fromHexadecimalInString(
			binaryInString[0] + coma::util::BaseConverter("01","0123456789ABCDEF").convert(binaryInString));
}

Signed *const Signed::fromOctalInString(const std::string &octalInString){
	return fromHexadecimalInString(
			octalInString[0] + coma::util::BaseConverter("01234567","0123456789ABCDEF").convert(octalInString));
}

Signed *const Signed::fromDecimalInString(const std::string &decimalInString){
	return fromHexadecimalInString(
			decimalInString[0] + coma::util::BaseConverter("01234567","0123456789ABCDEF").convert(decimalInString));
}

Signed *const Signed::fromHexadecimalInString(const std::string &hexadecimalInString){//TODO testing, testing
	std::unique_ptr<unsigned char[]> chars{ util::numb::arrayFromSignedHexadecimal(hexadecimalInString) };
	unsigned long long length { util::numb::sizeFromSignedHexadecimal(hexadecimalInString) };
	return fromLittleEndianArray(chars.get(), length);
}
	//======================================
	//-------------COMPARABLE---------------
	//======================================


	const CompareResult Signed::compare(const RealNumber *const toCompare) const{
		return invertComparison(static_cast<const coma::numb::Comparable<Signed> *const>(toCompare)->compare(this));
	}

	const CompareResult Signed::compare(const FloatingPoint *const toCompare) const{
		return invertComparison(static_cast<const coma::numb::Comparable<Signed> *const>(toCompare)->compare(this));
	}

	const CompareResult Signed::compare(const Signed *const toCompare) const{
		std::unique_ptr<Number> tmp { this->getDifference(toCompare) };
		if(tmp->isZero()) return CompareResult::Equal;
		else{
			std::unique_ptr<Signed> sig { tmp->getAsSignedInteger() };
			return sig->isPositive() ? CompareResult::ThisGreater : CompareResult::ThisLesser;
		}
	}

	const CompareResult Signed::compare(const Unsigned *const toCompare) const{
		std::unique_ptr<coma::numb::Comparable<Signed> > left { toCompare->getAsSignedInteger() };
		return invertComparison(left->compare(this));
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
		unsigned long long size { std::max(this->getArraySize(), toAdd->getArraySize()) + 1 };
		std::unique_ptr<unsigned char[]> sum{ new unsigned char[size]{} };
		std::copy(this->getArray(), this->getArray() + this->getArraySize(), sum.get());
		util::numb::addArray(sum.get(), size, toAdd->getArray(), toAdd->getArraySize());
		return fromLittleEndianArray(sum.get(), size);
	}

	Number *const Signed::getSum(const Unsigned *const toAdd) const{//TODO testing
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

	Number *const Signed::getDifference(const Signed *const toSubtract) const{//TODO testing
		unsigned long long size { 1 + std::max(this->getArraySize(), toSubtract->getArraySize()) };
		std::unique_ptr<unsigned char[]> diff{ new unsigned char[size] {} };
		std::copy(toSubtract->getArray(), toSubtract->getArray() + toSubtract->getArraySize(), diff.get());
		if(toSubtract->isNegative()) for(unsigned long long i = toSubtract->getArraySize(); i < size; ++i)
			diff[i] = static_cast<unsigned char>(-1);
		util::numb::negateArray(diff.get(), size);
		return fromLittleEndianArray(diff.get(), size);
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
		std::unique_ptr<Number> right{};
		std::unique_ptr<Number> left{}, result{};
		if(this->isNegative()){
			left.reset(this->getNegation());
			left.reset(left->getAsUnsignedInteger());
		}else{
			left.reset(this->getAsUnsignedInteger());
		}

		if(toMultiply->isNegative()){
			right.reset(toMultiply->getNegation());
			right.reset(right->getAsUnsignedInteger());
		}else{
			right.reset(toMultiply->getAsUnsignedInteger());
		}
		result.reset(static_cast<coma::numb::Arithmetic<Number> *>(right.get())->getProduct(left.get()));
		/* != is logical XOR */
		if(this->isNegative() != toMultiply->isNegative()) result.reset(result->getNegation());
		return result.release();
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
		return getArraySize() == 1 && getArray()[0] == 0;
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
		return Unsigned::fromLittleEndianArray(getArray(), getArraySize());
	}

	Signed *const Signed::getAsSignedInteger() const{
		return fromLittleEndianArray(getArray(), getArraySize());
	}

	FloatingPoint *const Signed::getAsFloatingPoint() const{
		//TODO complete after FloatingPoint definition
	}

	Complex *const Signed::getAsComplex() const{
		//TODO complete after Complex definition
	}

	Number *const Signed::getNegation() const{
		unsigned long long size { getArraySize() + (isNegative() ? 1 : 0) };
		std::unique_ptr<unsigned char[]> array { new unsigned char[size]{} };
		std::copy(getArray(), getArray() + getArraySize(), array.get());
		if(isNegative()) array[size - 1] = 0xFF;
		util::numb::negateArray(array.get(), size);
	}

	Number *const Signed::getInversion() const{
		//TODO finish after FloatingPoint definition
	}

	const bool Signed::isNegative() const{
		return getArray()[getArraySize() - 1] & 0x80;
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

	Integer *const Signed::getIntegerQuotient(const Signed *const toDivide) const{
		//TODO implementation
	}

	Integer *const Signed::getRemainder(const Signed *const toDivide) const{
		//TODO implementation
	}

	Integer *const Signed::getIntegerQuotientInverse(const Signed *const dividend) const{
		//TODO implementation
	}

	Integer *const Signed::getInverseRemainder(const Signed *const dividend) const{
		//TODO implementation
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
