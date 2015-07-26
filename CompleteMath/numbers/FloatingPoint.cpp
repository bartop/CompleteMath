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


FloatingPoint::FloatingPoint(const Integer *const numerator, const Unsigned *const denominator, const Integer *const power):
	m_numerator(),
	m_denominator(denominator->getAsUnsignedInteger()),
	m_power(power->getAsSignedInteger()){}


//======================================
//-------------ARITHMETIC---------------
//======================================

Number *const FloatingPoint::getSum(const Number *const toAdd) const{
	return static_cast<const coma::core::Arithmetic<FloatingPoint, Number> *const>(toAdd)->getSum(this);
}

Number *const FloatingPoint::getSum(const Complex *const toAdd) const{
	return static_cast<const coma::core::Arithmetic<FloatingPoint, Number> *const>(toAdd)->getSum(this);
}

Number *const FloatingPoint::getSum(const FloatingPoint *const toAdd) const{
	if(this->m_denominator->compare(toAdd->m_denominator) && this->m_power->compare(toAdd->m_power)){
		std::unique_ptr<Number>
			sum { static_cast<const coma::core::Arithmetic<Number> *>(this->m_numerator)->getSum(toAdd->m_numerator) };
	}else{

	}
}

Number *const FloatingPoint::getSum(const Signed *const toAdd) const{
	std::unique_ptr<coma::core::Arithmetic<FloatingPoint, Number> > left { toAdd->getAsFloatingPoint() };
	return left->getSum(this);
}

Number *const FloatingPoint::getSum(const Unsigned *const toAdd) const{
	std::unique_ptr<coma::core::Arithmetic<FloatingPoint, Number> > left { toAdd->getAsFloatingPoint() };
	return left->getSum(this);
}

Number *const FloatingPoint::getDifference(const Number *const toSubtract) const{
	return static_cast<const coma::core::Arithmetic<FloatingPoint, Number> *const>(toSubtract)->getDifferenceNegation(this);
}

Number *const FloatingPoint::getDifference(const Complex *const toSubtract) const{
	return static_cast<const coma::core::Arithmetic<FloatingPoint, Number> *const>(toSubtract)->getDifferenceNegation(this);
}

Number *const FloatingPoint::getDifference(const FloatingPoint *const toSubtract) const{
	//TODO implement
}

Number *const FloatingPoint::getDifference(const Signed *const toSubtract) const{
	std::unique_ptr<coma::core::Arithmetic<FloatingPoint, Number> > left { toSubtract->getAsFloatingPoint() };
	return left->getDifferenceNegation(this);
}

Number *const FloatingPoint::getDifference(const Unsigned *const toSubtract) const{
	std::unique_ptr<coma::core::Arithmetic<FloatingPoint, Number> > left { toSubtract->getAsFloatingPoint() };
	return left->getDifferenceNegation(this);
}

Number *const FloatingPoint::getProduct(const Number *const toMultiply) const{
	return static_cast<const coma::core::Arithmetic<FloatingPoint, Number> *const>(toMultiply)->getProduct(this);
}

Number *const FloatingPoint::getProduct(const Complex *const toMultiply) const{
	return static_cast<const coma::core::Arithmetic<FloatingPoint, Number> *const>(toMultiply)->getProduct(this);
}

Number *const FloatingPoint::getProduct(const FloatingPoint *const toMultiply) const{
	//TODO implement
}

Number *const FloatingPoint::getProduct(const Signed *const toMultiply) const{
	std::unique_ptr<coma::core::Arithmetic<FloatingPoint, Number> > left { toMultiply->getAsFloatingPoint() };
	return left->getProduct(this);
}

Number *const FloatingPoint::getProduct(const Unsigned *const toMultiply) const{
	std::unique_ptr<coma::core::Arithmetic<FloatingPoint, Number> > left { toMultiply->getAsFloatingPoint() };
	return left->getProduct(this);
}

Number *const FloatingPoint::getQuotient(const Number *const toDivide) const{
	return static_cast<const coma::core::Arithmetic<FloatingPoint, Number> *const>(toDivide)->getQuotientInverse(this);
}

Number *const FloatingPoint::getQuotient(const Complex *const toDivide) const{
	return static_cast<const coma::core::Arithmetic<FloatingPoint, Number> *const>(toDivide)->getQuotientInverse(this);
}

Number *const FloatingPoint::getQuotient(const FloatingPoint *const toDivide) const{
	//TODO implement
}

Number *const FloatingPoint::getQuotient(const Signed *const toDivide) const{
	std::unique_ptr<coma::core::Arithmetic<FloatingPoint, Number> > left { toDivide->getAsFloatingPoint() };
	return left->getQuotientInverse(this);
}

Number *const FloatingPoint::getQuotient(const Unsigned *const toDivide) const{
	std::unique_ptr<coma::core::Arithmetic<FloatingPoint, Number> > left { toDivide->getAsFloatingPoint() };
	return left->getQuotientInverse(this);
}

Number *const FloatingPoint::getDifferenceNegation(const Number *const minuend) const{
	return static_cast<const coma::core::Arithmetic<FloatingPoint, Number> *const>(minuend)->getDifference(this);
}

Number *const FloatingPoint::getDifferenceNegation(const Complex *const minuend) const{
	return static_cast<const coma::core::Arithmetic<FloatingPoint, Number> *const>(minuend)->getDifference(this);
}

Number *const FloatingPoint::getDifferenceNegation(const FloatingPoint *const minuend) const{
	return static_cast<const coma::core::Arithmetic<FloatingPoint, Number> *const>(minuend)->getDifference(this);
}

Number *const FloatingPoint::getDifferenceNegation(const Signed *const minuend) const{
	return static_cast<const coma::core::Arithmetic<FloatingPoint, Number> *const>(minuend)->getDifference(this);
}

Number *const FloatingPoint::getDifferenceNegation(const Unsigned *const minuend) const{
	return static_cast<const coma::core::Arithmetic<FloatingPoint, Number> *const>(minuend)->getDifference(this);
}

Number *const FloatingPoint::getQuotientInverse(const Number *const dividend) const{
	return static_cast<const coma::core::Arithmetic<FloatingPoint, Number> *const>(dividend)->getQuotient(this);
}

Number *const FloatingPoint::getQuotientInverse(const Complex *const dividend) const{
	return static_cast<const coma::core::Arithmetic<FloatingPoint, Number> *const>(dividend)->getQuotient(this);
}

Number *const FloatingPoint::getQuotientInverse(const FloatingPoint *const dividend) const{
	return static_cast<const coma::core::Arithmetic<FloatingPoint, Number> *const>(dividend)->getQuotient(this);
}

Number *const FloatingPoint::getQuotientInverse(const Signed *const dividend) const{
	return static_cast<const coma::core::Arithmetic<FloatingPoint, Number> *const>(dividend)->getQuotient(this);
}

Number *const FloatingPoint::getQuotientInverse(const Unsigned *const dividend) const{
	return static_cast<const coma::core::Arithmetic<FloatingPoint, Number> *const>(dividend)->getQuotient(this);
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

FloatingPoint::~FloatingPoint() {
	delete m_numerator;
	delete m_denominator;
	delete m_power;
}

} /* namespace numb */
} /* namespace coma */
