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
#include "math.h"

namespace coma {
namespace numb {

//======================================
//------------FLOATINGPOINT-------------
//======================================

FloatingPoint::FloatingPoint(const Integer *const numerator, const Unsigned *const denominator, const Integer *const power):
	m_numerator(static_cast<Integer *>(numerator->copy())),
	m_denominator(static_cast<Unsigned *>(denominator->copy())),
	m_power(static_cast<Integer *>(power->copy())){}

FloatingPoint::~FloatingPoint() {
	if(m_numerator) delete m_numerator;
	if(m_denominator) delete m_denominator;
	if(m_power) delete m_power;
}

//======================================
//--------------COPYABLE----------------
//======================================

Number *const FloatingPoint::copy() const{
	return getAsFloatingPoint();
}

//======================================
//-------------ARITHMETIC---------------
//======================================

Number *const FloatingPoint::getSum(const Number *const toAdd) const{
	return toAdd->getSum(this);
}

Number *const FloatingPoint::getSum(const Complex *const toAdd) const{
	return toAdd->getSum(this);
}

Number *const FloatingPoint::getSum(const FloatingPoint *const toAdd) const{
	if(this->m_denominator->compare(toAdd->m_denominator) && this->m_power->compare(toAdd->m_power)){
		std::unique_ptr<Number>
			sum { static_cast<const coma::core::Arithmetic<Number> *>(this->m_numerator)->getSum(toAdd->m_numerator) };
	}else{
		std::unique_ptr<Integer> GCD { getGCD(this->m_denominator, toAdd->m_denominator) };

	}
}

Number *const FloatingPoint::getSum(const Signed *const toAdd) const{
	std::unique_ptr<coma::numb::FloatingPoint> left { toAdd->getAsFloatingPoint() };
	return left->getSum(this);
}

Number *const FloatingPoint::getSum(const Unsigned *const toAdd) const{
	std::unique_ptr<coma::numb::FloatingPoint> left { toAdd->getAsFloatingPoint() };
	return left->getSum(this);
}

Number *const FloatingPoint::getProduct(const Number *const toMultiply) const{
	return toMultiply->getProduct(this);
}

Number *const FloatingPoint::getProduct(const Complex *const toMultiply) const{
	return toMultiply->getProduct(this);
}

Number *const FloatingPoint::getProduct(const FloatingPoint *const toMultiply) const{
	Integer *numerator  = this->m_numerator->getProduct(toMultiply->m_numerator);
	Unsigned *denominator  = this->m_denominator->getProduct(toMultiply->m_denominator);
	Integer *power = this->m_power->getSum(toMultiply->m_power);
}

Number *const FloatingPoint::getProduct(const Signed *const toMultiply) const{
	std::unique_ptr<coma::numb::FloatingPoint> left { toMultiply->getAsFloatingPoint() };
	return left->getProduct(this);
}

Number *const FloatingPoint::getProduct(const Unsigned *const toMultiply) const{
	std::unique_ptr<coma::numb::FloatingPoint> left { toMultiply->getAsFloatingPoint() };
	return left->getProduct(this);
}

//======================================
//---------------NUMBER-----------------
//======================================

const bool FloatingPoint::isZero() const{
	return m_numerator->isZero();
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
	std::unique_ptr<Integer>
		tmp {static_cast<const coma::numb::IntegerArithmetic<Unsigned, Integer> *>(m_numerator)
			->getIntegerQuotient(m_denominator) };
	return tmp->getAsUnsignedInteger();
}

Signed *const FloatingPoint::getAsSignedInteger() const{
	std::unique_ptr<Integer>
		tmp {static_cast<const coma::numb::IntegerArithmetic<Unsigned, Integer> *>(m_numerator)
			->getIntegerQuotient(m_denominator) };
	return tmp->getAsSignedInteger();
}

FloatingPoint *const FloatingPoint::getAsFloatingPoint() const{
	return new FloatingPoint{m_numerator, m_denominator, m_power};
}

Complex *const FloatingPoint::getAsComplex() const{
	//TODO complete after Complex definition
}

Number *const FloatingPoint::getNegation() const{
	std::unique_ptr<Number> neg { m_numerator->getNegation() };
	return new FloatingPoint{static_cast<const Integer *>(neg.get()) , m_denominator, m_power };
}

Number *const FloatingPoint::getInversion() const{
	if (m_numerator->isZero()) throw 1; //TODO exceptions
	std::unique_ptr<Number> powNum { m_power->getNegation() };
	std::unique_ptr<Signed> powSigned { powNum->getAsSignedInteger() };

}

//======================================
//-------------REALNUMBER---------------
//======================================

const bool FloatingPoint::isNegative() const{
	return m_numerator->isNegative();
}

const bool FloatingPoint::isPositive() const{
	return m_numerator->isPositive();
}


} /* namespace numb */
} /* namespace coma */
