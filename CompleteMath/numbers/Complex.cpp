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
	}

	Number *const Complex::getSum(const Complex *const toAdd) const{
	}

	Number *const Complex::getSum(const FloatingPoint *const toAdd) const{
	}

	Number *const Complex::getSum(const Signed *const toAdd) const{
	}

	Number *const Complex::getSum(const Unsigned *const toAdd) const{
	}

	Number *const Complex::getProduct(const Number *const toMultiply) const{
	}

	Number *const Complex::getProduct(const Complex *const toMultiply) const{
	}

	Number *const Complex::getProduct(const FloatingPoint *const toMultiply) const{
	}

	Number *const Complex::getProduct(const Signed *const toMultiply) const{
	}

	Number *const Complex::getProduct(const Unsigned *const toMultiply) const{
	}

	//======================================
	//---------------NUMBER-----------------
	//======================================

	const bool Complex::isZero() const{
	}

	const std::string Complex::getAsBinary() const{
	}

	const std::string Complex::getAsOctal() const{
	}

	const std::string Complex::getAsDecimal() const{
	}

	const std::string Complex::getAsHexadecimal() const{

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
