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
using namespace std;
//======================================
//------------FLOATINGPOINT-------------
//======================================

FloatingPoint::FloatingPoint(Pointer<const Integer> numerator,
		Pointer<const Unsigned> denominator,
		Pointer<const Integer> power):
	m_numerator(numerator),
	m_denominator(denominator),
	m_power(power){}

Pointer<const FloatingPoint> FloatingPoint::fromFraction(
		Pointer<const Integer> numerator,
		Pointer<const Integer> denominator,
		Pointer<const Integer> power){
	if(!numerator || !denominator || !power) REPORT_ERROR(exception("Null pointer exception"), nullptr);
	if(denominator->isZero()) REPORT_ERROR(exception("Division by zero exception"), nullptr);
	if(numerator->isZero()) return make_shared<const FloatingPoint>(ZERO(), ONE(), ZERO());
	Pointer<const Integer>
		num = static_pointer_cast<const Integer>(numerator->getAbsoluteValue()),
		den = static_pointer_cast<const Integer>(denominator->getAbsoluteValue()),
		pow = static_pointer_cast<const Integer>(power->copy()),
		num256 = Unsigned::fromDecimalInString("256"),
		rem{},
		GCD = getGCD(numerator, denominator);
	num = static_pointer_cast<const IntegerArithmetic<Pointer<const Integer>>>(num)->getIntegerQuotient(GCD);
	den = static_pointer_cast<const IntegerArithmetic<Pointer<const Integer>>>(den)->getIntegerQuotient(GCD);
	if(numerator->isNegative() != denominator->isNegative()){
		num = static_pointer_cast<const Integer>(num->getNegation());
	}
	while(rem = static_pointer_cast<const IntegerArithmetic<Pointer<const Integer>>>(num)->getRemainder(num256),
			rem->isZero()){
		num = static_pointer_cast<const IntegerArithmetic<Pointer<const Integer>>>(num)->getIntegerQuotient(num256);
		pow = static_pointer_cast<const Integer>(pow->getSum(ONE()));
	}
	while(rem = static_pointer_cast<const IntegerArithmetic<Pointer<const Integer>>>(den)->getRemainder(num256),
			rem->isZero()){
		den = static_pointer_cast<const IntegerArithmetic<Pointer<const Integer>>>(den)->getIntegerQuotient(num256);
		pow = static_pointer_cast<const Integer>(pow->getDifference(ONE()));
	}
	return make_shared<const FloatingPoint>(num, static_pointer_cast<const Unsigned>(den), pow);
}

Pointer<const FloatingPoint> FloatingPoint::fromBinaryFractionInStrings(const string &numerator,
		const string &denominator){
	Pointer<const Integer>
		num { Integer::fromBinaryInString(numerator) },
		den { Integer::fromBinaryInString(denominator) };
	return fromFraction(num, den, ZERO());
}

Pointer<const FloatingPoint> FloatingPoint::fromOctalFractionInStrings(const string &numerator, const string &denominator){
	Pointer<const Integer>
		num { Integer::fromOctalInString(numerator) },
		den { Integer::fromOctalInString(denominator) };
	return fromFraction(num, den, ZERO());
}

Pointer<const FloatingPoint> FloatingPoint::fromDecimalFractionInStrings(const string &numerator, const string &denominator){
	Pointer<const Integer>
		num { Integer::fromDecimalInString(numerator) },
		den { Integer::fromDecimalInString(denominator) };
	return fromFraction(num, den, ZERO());
}

Pointer<const FloatingPoint> FloatingPoint::fromHexadecimalFractionInStrings(const string &numerator, const string &denominator){
	Pointer<const Integer>
		num = Integer::fromHexadecimalInString(numerator),
		den = Integer::fromHexadecimalInString(denominator);
	return fromFraction(num, den, ZERO());
}

Pointer<const FloatingPoint> FloatingPoint::fromFloat(const string &number,
		const string &base,
		const function<Pointer<const Integer> const(const string &)> &numeratorCreator){
	string copy = number;
	auto iter = find(copy.begin(), copy.end(), '.');
	unsigned long long position = iter - copy.begin();
	if(iter == copy.end()) position = 0;
	else{
		position = copy.length() - position - 1;
		copy.erase(iter);
	}
	Pointer<const Integer>
			num = numeratorCreator(copy),
			baseInt = Integer::fromDecimalInString(base),
			den = static_pointer_cast<const Integer>(ONE()->copy());
	for(unsigned long long i = 0; i < position; ++i){
		den = static_pointer_cast<const Integer>(den->getProduct(baseInt));
	}
	return fromFraction(num, den, ZERO());
}

Pointer<const FloatingPoint> FloatingPoint::fromBinaryFloatInString(const string &number){
	return fromFloat(number, "2", Integer::fromBinaryInString);
}

Pointer<const FloatingPoint> FloatingPoint::fromOctalFloatInString(const string &number){
	return fromFloat(number, "8", Integer::fromOctalInString);
}

Pointer<const FloatingPoint> FloatingPoint::fromDecimalFloatInString(const string &number){
	return fromFloat(number, "10", Integer::fromDecimalInString);
}

Pointer<const FloatingPoint> FloatingPoint::fromHexadecimalFloatInString(const string &number){
	return fromFloat(number, "16", Integer::fromHexadecimalInString);
}

FloatingPoint::~FloatingPoint() noexcept{
}

//======================================
//--------------COPYABLE----------------
//======================================

Pointer<const Number> FloatingPoint::copy() const{
	return getAsFloatingPoint();
}

//======================================
//-------------ARITHMETIC---------------
//======================================

Pointer<const Number> FloatingPoint::getSum(Pointer<const Number> toAdd) const{
	if(!toAdd) REPORT_ERROR(exception("Null pointer exception"), nullptr);
	return toAdd->getSum(sharedThis());
}

Pointer<const Number> FloatingPoint::getSum(Pointer<const Complex> toAdd) const{
	if(!toAdd) REPORT_ERROR(exception("Null pointer exception"), nullptr);
	return toAdd->getSum(sharedThis());
}

Pointer<const Number> FloatingPoint::getSum(Pointer<const FloatingPoint> toAdd) const{
	if(!toAdd) REPORT_ERROR(exception("Null pointer exception"), nullptr);
	if(m_denominator->compare(toAdd->m_denominator) && this->m_power->compare(toAdd->m_power)){
		Pointer<const Number> sum = m_numerator->getSum(toAdd->m_numerator);
		return fromFraction(static_pointer_cast<const Integer>(sum), m_denominator, m_power);
	}else{
		Pointer<const Integer> GCD = getGCD(this->m_denominator, toAdd->m_denominator);
		Pointer<const Integer>
			multiplicand1 = static_pointer_cast<const IntegerArithmetic<Pointer<const Integer>>>(
					toAdd->m_denominator)->getIntegerQuotient(GCD),
			multiplicand2 = static_pointer_cast<const IntegerArithmetic<Pointer<const Integer>>>(
					m_denominator)->getIntegerQuotient(GCD);
		Pointer<const Integer>
			numerator1 = static_pointer_cast<const Integer>(multiplicand1->getProduct(m_numerator)),
			numerator2 = static_pointer_cast<const Integer>(multiplicand2->getProduct(toAdd->m_numerator)),
			denominator = getLCM(m_denominator, toAdd->m_denominator);
		Pointer<const Integer>
			powerDiff { static_pointer_cast<const Integer>(m_power->getDifference(toAdd->m_power)) };
		Pointer<const Number> num256 { Unsigned::fromDecimalInString("256") };
		while(!(powerDiff->isZero())){
			if(powerDiff->isNegative()){
				numerator2 = static_pointer_cast<const Integer>(numerator2->getProduct(num256));
				powerDiff = static_pointer_cast<const Integer>(powerDiff->getSum(ONE()));
			}
			else{
				numerator1 = static_pointer_cast<const Integer>(numerator1->getProduct(num256));
				powerDiff = static_pointer_cast<const Integer>(powerDiff->getDifference(ONE()));
			}
		}
		Pointer<const Integer> sum = static_pointer_cast<const Integer>(numerator1->getSum(numerator2));
		return fromFraction(sum,
				denominator,
				min(this->m_power, toAdd->m_power, [](const Pointer<const RealNumber>  ptr1,
														const Pointer<const RealNumber>  ptr2){
			return ptr1->compare(ptr2) == CompareResult::ThisLesser;
		}));
	}
}

Pointer<const Number> FloatingPoint::getSum(Pointer<const Signed> toAdd) const{
	if(!toAdd) REPORT_ERROR(exception("Null pointer exception"), nullptr);
	Pointer<const FloatingPoint> left = toAdd->getAsFloatingPoint();
	return left->getSum(sharedThis());
}

Pointer<const Number> FloatingPoint::getSum(Pointer<const Unsigned> toAdd) const{
	if(!toAdd) REPORT_ERROR(exception("Null pointer exception"), nullptr);
	Pointer<const FloatingPoint> left = toAdd->getAsFloatingPoint();
	return left->getSum(sharedThis());
}

Pointer<const Number> FloatingPoint::getProduct(Pointer<const Number> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(exception("Null pointer exception"), nullptr);
	return toMultiply->getProduct(sharedThis());
}

Pointer<const Number> FloatingPoint::getProduct(Pointer<const Complex> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(exception("Null pointer exception"), nullptr);
	return toMultiply->getProduct(sharedThis());
}

Pointer<const Number> FloatingPoint::getProduct(Pointer<const FloatingPoint> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(exception("Null pointer exception"), nullptr);
	Pointer<const Integer>
		numerator = static_pointer_cast<const Integer>(m_numerator->getProduct(toMultiply->m_numerator)),
		denominator = static_pointer_cast<const Integer>(m_denominator->getProduct(toMultiply->m_denominator)),
		power = static_pointer_cast<const Integer>(m_power->getSum(toMultiply->m_power));
	return fromFraction(numerator, denominator, power);
}

Pointer<const Number> FloatingPoint::getProduct(Pointer<const Signed> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(exception("Null pointer exception"), nullptr);
	Pointer<const FloatingPoint> left = toMultiply->getAsFloatingPoint();
	return left->getProduct(sharedThis());
}

Pointer<const Number> FloatingPoint::getProduct(Pointer<const Unsigned> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(exception("Null pointer exception"), nullptr);
	Pointer<const FloatingPoint> left = toMultiply->getAsFloatingPoint();
	return left->getProduct(sharedThis());
}

//======================================
//---------------NUMBER-----------------
//======================================

bool FloatingPoint::isZero() const noexcept{
	return m_numerator->isZero();
}

string FloatingPoint::getAsBinary() const{
	string result { m_numerator->getAsBinary() };
	result += "/" + m_denominator->getAsBinary();
	result += " * 100000000^" + m_power->getAsBinary();
	return result;
}

string FloatingPoint::getAsOctal() const{
	string result { m_numerator->getAsOctal() };
	result += "/" + m_denominator->getAsOctal();
	result += " * 400^" + m_power->getAsOctal();
	return result;
}

string FloatingPoint::getAsDecimal() const{
	string result { m_numerator->getAsDecimal() };
	result += "/" + m_denominator->getAsDecimal();
	result += " * 256^" + m_power->getAsDecimal();
	return result;
}

string FloatingPoint::getAsHexadecimal() const{
	string result { m_numerator->getAsHexadecimal() };
	result += "/" + m_denominator->getAsHexadecimal();
	result += " * 100^" + m_power->getAsHexadecimal();
	return result;
}

Pointer<const Unsigned> FloatingPoint::getAsUnsignedInteger() const{
	Pointer<const Integer>
		tmp = static_pointer_cast<const coma::numb::IntegerArithmetic<Pointer<const Unsigned>, Pointer<const Integer>>>(
				m_numerator)->getIntegerQuotient(m_denominator);
	return tmp->getAsUnsignedInteger();
}

Pointer<const Signed> FloatingPoint::getAsSignedInteger() const{
	Pointer<const Integer>
		tmp = static_pointer_cast<const coma::numb::IntegerArithmetic<Pointer<const Unsigned>, Pointer<const Integer>>>(
			m_numerator)->getIntegerQuotient(m_denominator);
	return tmp->getAsSignedInteger();
}

Pointer<const FloatingPoint> FloatingPoint::getAsFloatingPoint() const{
	return sharedThis();
}

Pointer<const Complex> FloatingPoint::getAsComplex() const{
	//TODO complete after Complex definition
}

Pointer<const Number> FloatingPoint::getNegation() const{
	return make_shared<FloatingPoint>(
			static_pointer_cast<const Integer>(m_numerator->getNegation()),
			m_denominator,
			m_power);
}

Pointer<const Number> FloatingPoint::getInversion() const{
	if (m_numerator->isZero()) throw 1; //TODO exceptions
	return fromFraction(m_denominator, m_numerator,
			static_pointer_cast<const Integer>(m_power->getNegation()));
}

//======================================
//-------------REALNUMBER---------------
//======================================

bool FloatingPoint::isNegative() const noexcept{
	return m_numerator->isNegative();
}

bool FloatingPoint::isPositive() const noexcept{
	return m_numerator->isPositive();
}

Pointer<const FloatingPoint> FloatingPoint::sharedThis() const{
	return static_pointer_cast<const FloatingPoint>(shared_from_this());
}

} /* namespace numb */
} /* namespace coma */
