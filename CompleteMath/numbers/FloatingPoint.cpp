/*
 * FloatingPoint.cpp
 *
 *  Created on: 27 cze 2015
 *      Author: Bartosz Miera
 */

#include <memory>
#include "Complex.h"
#include "FloatingPoint.h"
#include "Signed.h"
#include "Unsigned.h"

namespace coma {
namespace numb {
//TODO imlement all stuff
FloatingPoint::~FloatingPoint() {
	// TODO Auto-generated destructor stub
}

	//======================================
	//-------------COMPARABLE---------------
	//======================================


	const CompareResult FloatingPoint::compare(const RealNumber *const toCompare) const{
		return invertComparison(static_cast<const coma::numb::Comparable<FloatingPoint> *const >(toCompare)->compare(this));
	}

	const CompareResult FloatingPoint::compare(const FloatingPoint *const toCompare) const{
		return invertComparison(static_cast<const coma::numb::Comparable<FloatingPoint> *const >(toCompare)->compare(this));
	}

	const CompareResult FloatingPoint::compare(const Signed *const toCompare) const{
		return invertComparison(static_cast<const coma::numb::Comparable<FloatingPoint> *const >(toCompare)->compare(this));
	}

	const CompareResult FloatingPoint::compare(const Unsigned *const toCompare) const{
	}

	//======================================
	//-------------ARITHMETIC---------------
	//======================================

	Number *const FloatingPoint::getSum(const Number *const toAdd) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(toAdd)->getSum(this);
	}

	Number *const FloatingPoint::getSum(const Complex *const toAdd) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(toAdd)->getSum(this);
	}

	Number *const FloatingPoint::getSum(const FloatingPoint *const toAdd) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(toAdd)->getSum(this);
	}

	Number *const FloatingPoint::getSum(const Signed *const toAdd) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(toAdd)->getSum(this);
	}

	Number *const FloatingPoint::getSum(const Unsigned *const toAdd) const{
	}

	Number *const FloatingPoint::getDifference(const Number *const toSubtract) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(toSubtract)->getDifferenceNegation(this);
	}

	Number *const FloatingPoint::getDifference(const Complex *const toSubtract) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(toSubtract)->getDifferenceNegation(this);
	}

	Number *const FloatingPoint::getDifference(const FloatingPoint *const toSubtract) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(toSubtract)->getDifferenceNegation(this);
	}

	Number *const FloatingPoint::getDifference(const Signed *const toSubtract) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(toSubtract)->getDifferenceNegation(this);
	}

	Number *const FloatingPoint::getDifference(const Unsigned *const toSubtract) const{
		std::unique_ptr<coma::numb::Arithmetic<FloatingPoint, Number> > left { toSubtract->getAsSignedInteger() };
		return left->getDifferenceNegation(this);
	}

	Number *const FloatingPoint::getProduct(const Number *const toMultiply) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(toMultiply)->getProduct(this);
	}

	Number *const FloatingPoint::getProduct(const Complex *const toMultiply) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(toMultiply)->getProduct(this);
	}

	Number *const FloatingPoint::getProduct(const FloatingPoint *const toMultiply) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(toMultiply)->getProduct(this);
	}

	Number *const FloatingPoint::getProduct(const Signed *const toMultiply) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(toMultiply)->getProduct(this);
	}

	Number *const FloatingPoint::getProduct(const Unsigned *const toMultiply) const{
	}

	Number *const FloatingPoint::getQuotient(const Number *const toDivide) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(toDivide)->getQuotientInverse(this);
	}

	Number *const FloatingPoint::getQuotient(const Complex *const toDivide) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(toDivide)->getQuotientInverse(this);
	}

	Number *const FloatingPoint::getQuotient(const FloatingPoint *const toDivide) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(toDivide)->getQuotientInverse(this);
	}

	Number *const FloatingPoint::getQuotient(const Signed *const toDivide) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(toDivide)->getQuotientInverse(this);
	}

	Number *const FloatingPoint::getQuotient(const Unsigned *const toDivide) const{
		std::unique_ptr<coma::numb::Arithmetic<FloatingPoint, Number> > left { toDivide->getAsFloatingPoint() };
		return left->getQuotientInverse(this);
	}

	Number *const FloatingPoint::getDifferenceNegation(const Number *const minuend) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(minuend)->getDifference(this);
	}

	Number *const FloatingPoint::getDifferenceNegation(const Complex *const minuend) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(minuend)->getDifference(this);
	}

	Number *const FloatingPoint::getDifferenceNegation(const FloatingPoint *const minuend) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(minuend)->getDifference(this);
	}

	Number *const FloatingPoint::getDifferenceNegation(const Signed *const minuend) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(minuend)->getDifference(this);
	}

	Number *const FloatingPoint::getDifferenceNegation(const Unsigned *const minuend) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(minuend)->getDifference(this);
	}

	Number *const FloatingPoint::getQuotientInverse(const Number *const dividend) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(dividend)->getQuotient(this);
	}

	Number *const FloatingPoint::getQuotientInverse(const Complex *const dividend) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(dividend)->getQuotient(this);
	}

	Number *const FloatingPoint::getQuotientInverse(const FloatingPoint *const dividend) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(dividend)->getQuotient(this);
	}

	Number *const FloatingPoint::getQuotientInverse(const Signed *const dividend) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(dividend)->getQuotient(this);
	}

	Number *const FloatingPoint::getQuotientInverse(const Unsigned *const dividend) const{
		return static_cast<const coma::numb::Arithmetic<FloatingPoint, Number> *const>(dividend)->getQuotient(this);
	}

	//======================================
	//---------------NUMBER-----------------
	//======================================

	const bool FloatingPoint::isZero() const{
	}

	const std::string FloatingPoint::getAsBinary() const{
	}

	const std::string FloatingPoint::getAsOctal() const{
	}

	const std::string FloatingPoint::getAsDecimal() const{
	}

	const std::string FloatingPoint::getAsHexadecimal() const{

	}

	Unsigned *const FloatingPoint::getAsUnsignedInteger() const{
	}

	Signed *const FloatingPoint::getAsSignedInteger() const{
		//TODO complete after Signed definition
	}

	FloatingPoint *const FloatingPoint::getAsFloatingPoint() const{
		//TODO complete after FloatingPoint definition
	}

	Complex *const FloatingPoint::getAsComplex() const{
		//TODO complete after Complex definition
	}

	Number *const FloatingPoint::getNegation() const{
		//TODO finish after Signed definition
	}

	Number *const FloatingPoint::getInversion() const{
		//TODO finish after FloatingPoint definition
	}

	//======================================
	//-------------REALNUMBER---------------
	//======================================

	const bool FloatingPoint::isNegative() const{
		return false;
	}

	const bool FloatingPoint::isPositive() const{
		return !isZero();
	}

FloatingPoint::FloatingPoint() {
	// TODO Auto-generated constructor stub

}

} /* namespace numb */
} /* namespace coma */
