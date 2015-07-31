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

FloatingPoint *const FloatingPoint::fromFraction(const Integer *const numerator,
		const Integer *const denominator,
		const Integer *const power){
	if(denominator->isZero()) throw 1; //TODO exceptions
	if(numerator->isZero()) return new FloatingPoint { ZERO(), ONE(), ZERO()};
	std::unique_ptr<Integer>
		num{ static_cast<Integer *>(numerator->getAbsoluteValue()) },
		den{ static_cast<Integer *>(denominator->getAbsoluteValue()) },
		pow{ static_cast<Integer *>(power->copy()) },
		num256{ Unsigned::fromDecimalInString("256") },
		rem{};
	std::unique_ptr<Integer> GCD { getGCD(numerator, denominator) };
	num.reset(static_cast<IntegerArithmetic<Integer> *>(num.get())->getIntegerQuotient(GCD.get()));
	den.reset(static_cast<IntegerArithmetic<Integer> *>(den.get())->getIntegerQuotient(GCD.get()));
	if(numerator->isNegative() != denominator->isNegative()) num.reset(static_cast<Integer *>(num->getNegation()));
	while(rem.reset(static_cast<IntegerArithmetic<Integer> *>(num.get())->getRemainder(num256.get())), rem->isZero()){
		num.reset(static_cast<IntegerArithmetic<Integer> *>(num.get())->getIntegerQuotient(num256.get()));
		pow.reset(static_cast<Integer *>(pow->getSum(multiplicationNeutralElement())));
	}
	while(rem.reset(static_cast<IntegerArithmetic<Integer> *>(den.get())->getRemainder(num256.get())), rem->isZero()){
		den.reset(static_cast<IntegerArithmetic<Integer> *>(num.get())->getIntegerQuotient(num256.get()));
		pow.reset(static_cast<Integer *>(pow->getDifference(multiplicationNeutralElement())));
	}
	return new FloatingPoint{ num.get(), static_cast<Unsigned *>(den.get()), pow.get() };
}

FloatingPoint *const FloatingPoint::fromFractionInStrings(const std::string &numerator, const std::string &denominator){
	std::unique_ptr<Integer>
		num { Integer::fromDecimalInString(numerator) },
		den { Integer::fromDecimalInString(denominator) };
	return fromFraction(num.get(), den.get(), static_cast<const Integer *>(additionNeutralElement()));
}

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
		return fromFraction(static_cast<Integer *>(sum.get()), this->m_denominator, this->m_power);
	}else{
		std::unique_ptr<Integer> GCD { getGCD(this->m_denominator, toAdd->m_denominator) };
		std::unique_ptr<Integer>
			multiplicand1 { static_cast<const coma::numb::IntegerArithmetic<Integer> *>(toAdd->m_denominator)->
				getIntegerQuotient(GCD.get()) },
			multiplicand2 { static_cast<const coma::numb::IntegerArithmetic<Integer> *>(this->m_denominator)->
				getIntegerQuotient(GCD.get()) };
		std::unique_ptr<Integer>
			numerator1 { static_cast<Integer *>(multiplicand1->getProduct(this->m_numerator)) },
			numerator2 { static_cast<Integer *>(multiplicand2->getProduct(toAdd->m_numerator)) },
			denominator{ getLCM(this->m_denominator, toAdd->m_denominator) };
		std::unique_ptr<Integer>
			powerDiff { static_cast<Integer *>(this->m_power->getDifference(toAdd->m_power)) };
		std::unique_ptr<Number> num256 { Unsigned::fromDecimalInString("256") };
		while(!additionNeutralElement()->isEqual(powerDiff.get())){
			if(powerDiff->isNegative()){
				numerator2.reset(static_cast<Integer *>(numerator2->getProduct(num256.get())));
				powerDiff.reset(static_cast<Integer *>(powerDiff->getSum(multiplicationNeutralElement())));
			}
			else{
				numerator1.reset(static_cast<Integer *>(numerator1->getProduct(num256.get())));
				powerDiff.reset(static_cast<Integer *>(powerDiff->getDifference(multiplicationNeutralElement())));
			}
		}
		std::unique_ptr<Integer> sum { static_cast<Integer *>(numerator1->getSum(numerator2.get())) };
		return fromFraction(sum.get(),
				denominator.get(),
				std::min(this->m_power, toAdd->m_power, [](const RealNumber *const ptr1,
														const RealNumber *const ptr2){
			return ptr1->compare(ptr2) == CompareResult::ThisGreater;
		}));
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
	std::unique_ptr<Integer>
		numerator { static_cast<Integer *>(this->m_numerator->getProduct(toMultiply->m_numerator)) },
		denominator { static_cast<Integer *>(this->m_denominator->getProduct(toMultiply->m_denominator)) },
		power { static_cast<Integer *>(this->m_power->getSum(toMultiply->m_power)) };
	return fromFraction(numerator.get(), denominator.get(), power.get());
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
	std::string result { m_numerator->getAsBinary() };
	result += "/" + m_denominator->getAsBinary();
	result += " * 256^" + m_power->getAsBinary();
	return result;
}

const std::string FloatingPoint::getAsOctal() const{
	std::string result { m_numerator->getAsOctal() };
	result += "/" + m_denominator->getAsOctal();
	result += " * 256^" + m_power->getAsOctal();
	return result;
}

const std::string FloatingPoint::getAsDecimal() const{
	std::string result { m_numerator->getAsDecimal() };
	result += "/" + m_denominator->getAsDecimal();
	result += " * 256^" + m_power->getAsDecimal();
	return result;
}

const std::string FloatingPoint::getAsHexadecimal() const{
	std::string result { m_numerator->getAsHexadecimal() };
	result += "/" + m_denominator->getAsHexadecimal();
	result += " * 256^" + m_power->getAsHexadecimal();
	return result;
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
	std::unique_ptr<Integer> powNum { static_cast<Integer *>(m_power->getNegation()) };
	return fromFraction(m_denominator, m_numerator, powNum.get());
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
