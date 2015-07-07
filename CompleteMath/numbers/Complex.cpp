/*
 * Complex.cpp
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

Complex::Complex() {
	// TODO Auto-generated constructor stub

}

	//======================================
	//-------------ARITHMETIC---------------
	//======================================

	Number *const Complex::getSum(const Number *const toAdd) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(toAdd)->getSum(this);
	}

	Number *const Complex::getSum(const Complex *const toAdd) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(toAdd)->getSum(this);
	}

	Number *const Complex::getSum(const FloatingPoint *const toAdd) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(toAdd)->getSum(this);
	}

	Number *const Complex::getSum(const Signed *const toAdd) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(toAdd)->getSum(this);
	}

	Number *const Complex::getSum(const Unsigned *const toAdd) const{
	}

	Number *const Complex::getDifference(const Number *const toSubtract) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(toSubtract)->getDifferenceNegation(this);
	}

	Number *const Complex::getDifference(const Complex *const toSubtract) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(toSubtract)->getDifferenceNegation(this);
	}

	Number *const Complex::getDifference(const FloatingPoint *const toSubtract) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(toSubtract)->getDifferenceNegation(this);
	}

	Number *const Complex::getDifference(const Signed *const toSubtract) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(toSubtract)->getDifferenceNegation(this);
	}

	Number *const Complex::getDifference(const Unsigned *const toSubtract) const{
		std::unique_ptr<coma::numb::Arithmetic<Complex, Number> > left { toSubtract->getAsSignedInteger() };
		return left->getDifferenceNegation(this);
	}

	Number *const Complex::getProduct(const Number *const toMultiply) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(toMultiply)->getProduct(this);
	}

	Number *const Complex::getProduct(const Complex *const toMultiply) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(toMultiply)->getProduct(this);
	}

	Number *const Complex::getProduct(const FloatingPoint *const toMultiply) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(toMultiply)->getProduct(this);
	}

	Number *const Complex::getProduct(const Signed *const toMultiply) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(toMultiply)->getProduct(this);
	}

	Number *const Complex::getProduct(const Unsigned *const toMultiply) const{
	}

	Number *const Complex::getQuotient(const Number *const toDivide) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(toDivide)->getQuotientInverse(this);
	}

	Number *const Complex::getQuotient(const Complex *const toDivide) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(toDivide)->getQuotientInverse(this);
	}

	Number *const Complex::getQuotient(const FloatingPoint *const toDivide) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(toDivide)->getQuotientInverse(this);
	}

	Number *const Complex::getQuotient(const Signed *const toDivide) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(toDivide)->getQuotientInverse(this);
	}

	Number *const Complex::getQuotient(const Unsigned *const toDivide) const{
		std::unique_ptr<coma::numb::Arithmetic<Complex, Number> > left { toDivide->getAsFloatingPoint() };
		return left->getQuotientInverse(this);
	}

	Number *const Complex::getDifferenceNegation(const Number *const minuend) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(minuend)->getDifference(this);
	}

	Number *const Complex::getDifferenceNegation(const Complex *const minuend) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(minuend)->getDifference(this);
	}

	Number *const Complex::getDifferenceNegation(const FloatingPoint *const minuend) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(minuend)->getDifference(this);
	}

	Number *const Complex::getDifferenceNegation(const Signed *const minuend) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(minuend)->getDifference(this);
	}

	Number *const Complex::getDifferenceNegation(const Unsigned *const minuend) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(minuend)->getDifference(this);
	}

	Number *const Complex::getQuotientInverse(const Number *const dividend) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(dividend)->getQuotient(this);
	}

	Number *const Complex::getQuotientInverse(const Complex *const dividend) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(dividend)->getQuotient(this);
	}

	Number *const Complex::getQuotientInverse(const FloatingPoint *const dividend) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(dividend)->getQuotient(this);
	}

	Number *const Complex::getQuotientInverse(const Signed *const dividend) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(dividend)->getQuotient(this);
	}

	Number *const Complex::getQuotientInverse(const Unsigned *const dividend) const{
		return static_cast<const coma::numb::Arithmetic<Complex, Number> *const>(dividend)->getQuotient(this);
	}

	//======================================
	//---------------NUMBER-----------------
	//======================================

	const bool Complex::isZero() const{
	}

	const NumberInString Complex::getAsBinary() const{
	}

	const NumberInString Complex::getAsOctal() const{
	}

	const NumberInString Complex::getAsDecimal() const{
	}

	const NumberInString Complex::getAsHexadecimal() const{

	}

	Unsigned *const Complex::getAsUnsignedInteger() const{
	}

	Signed *const Complex::getAsSignedInteger() const{
		//TODO complete after Signed definition
	}

	FloatingPoint *const Complex::getAsFloatingPoint() const{
		//TODO complete after FloatingPoint definition
	}

	Complex *const Complex::getAsComplex() const{
		//TODO complete after Complex definition
	}

	Number *const Complex::getNegation() const{
		//TODO finish after Signed definition
	}

	Number *const Complex::getInversion() const{
		//TODO finish after FloatingPoint definition
	}

Complex::~Complex() {
	// TODO Auto-generated destructor stub
}

} /* namespace numb */
} /* namespace coma */
