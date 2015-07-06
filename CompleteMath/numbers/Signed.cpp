/*
 * Signed.cpp
 *
 *  Created on: 27 cze 2015
 *      Author: Bartosz Miera
 */

#include "Signed.h"
#include "../Utility/Numbers.h"
#include "Unsigned.h"
#include "FloatingPoint.h"
#include "Complex.h"
#include <memory>
#include <sstream>

namespace coma {
namespace numb {

Signed::Signed() {
	// TODO Auto-generated constructor stub

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
		//TODO implementation
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
		//TODO implementation
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

	Number *const Signed::getDifference(const Signed *const toSubtract) const{
		//TODO implementation
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
		//TODO implementation
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
		//TODO implementation
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
		//TODO implementation
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
		//TODO implementation
	}

	Number *const Signed::getQuotientInverse(const Unsigned *const dividend) const{
		std::unique_ptr<coma::numb::Arithmetic<Signed, Number> > left { dividend->getAsSignedInteger() };
		return left->getQuotient(this);
	}

	//======================================
	//---------------NUMBER-----------------
	//======================================

	const bool Signed::isZero() const{//TODO implement
	}

	const NumberInString Signed::getAsBinary() const{
	}

	const NumberInString Signed::getAsOctal() const{
	}

	const NumberInString Signed::getAsDecimal() const{
	}

	const NumberInString Signed::getAsHexadecimal() const{
	}

	Unsigned *const Signed::getAsUnsignedInteger() const{
	}

	Signed *const Signed::getAsSignedInteger() const{
		//TODO complete after Signed definition
	}

	FloatingPoint *const Signed::getAsFloatingPoint() const{
		//TODO complete after FloatingPoint definition
	}

	Complex *const Signed::getAsComplex() const{
		//TODO complete after Complex definition
	}

	Number *const Signed::getNegation() const{
		//TODO finish after Signed definition
	}

	Number *const Signed::getInversion() const{
		//TODO finish after FloatingPoint definition
	}

	const bool Signed::isNegative() const{
	}

	const bool Signed::isPositive() const{
	}

	//======================================
	//---------INTEGERARITHMETIC------------
	//======================================

	Integer *const Signed::getIntegerQuotient(const Integer *const toDivide) const{
		return toDivide->coma::numb::IntegerArithmetic<Signed, Integer>::getIntegerQuotientInverse(this);
	}

	Integer *const Signed::getRemainder(const Integer *const toDivide) const{
		return toDivide->coma::numb::IntegerArithmetic<Signed, Integer>::getInverseRemainder(this);
	}

	Integer *const Signed::getIntegerQuotientInverse(const Integer *const dividend) const{
		return dividend->coma::numb::IntegerArithmetic<Signed, Integer>::getIntegerQuotient(this);
	}

	Integer *const Signed::getInverseRemainder(const Integer *const dividend) const{
		return dividend->coma::numb::IntegerArithmetic<Signed, Integer>::getRemainder(this);
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


Signed::~Signed() {
	// TODO Auto-generated destructor stub
}

} /* namespace numb */
} /* namespace coma */
