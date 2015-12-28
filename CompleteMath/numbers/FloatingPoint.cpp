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

FloatingPoint::FloatingPoint(Pointer<Integer> numerator,
		Pointer<Integer> denominator,
		Pointer<Integer> power){
	if(!numerator || !denominator || !power){
		REPORT_CONSTRUCTOR_ERROR(exception("Null pointer exception"), makeThisZero());
	}
	if(denominator->isZero()){
		REPORT_CONSTRUCTOR_ERROR(exception("Division by zero exception"), makeThisZero());
	}
	if(numerator->isZero()){
		makeThisZero();
		return;
	}
	bool negative = numerator->isNegative() != denominator->isNegative();//logical XOR
	Pointer<Integer>
		num256 = Unsigned::fromDecimalInString("256"),
		rem{},
		GCD = getGCD(numerator, denominator);
	numerator = staticPointerCast<Integer>(numerator->getAbsoluteValue());
	denominator = staticPointerCast<Integer>(denominator->getAbsoluteValue());
	numerator = staticPointerCast<IntegerArithmetic<Pointer<Integer>>>(numerator)->getIntegerQuotient(GCD);
	denominator = staticPointerCast<IntegerArithmetic<Pointer<Integer>>>(denominator)->getIntegerQuotient(GCD);
	if(negative){
		numerator = staticPointerCast<Integer>(numerator->getNegation());
	}
	while(rem = staticPointerCast<IntegerArithmetic<Pointer<Integer>>>(numerator)->getRemainder(num256),
			rem->isZero()){
		numerator = staticPointerCast<IntegerArithmetic<Pointer<Integer>>>(numerator)->getIntegerQuotient(num256);
		power = staticPointerCast<Integer>(power->getSum(ONE()));
	}
	while(rem = staticPointerCast<IntegerArithmetic<Pointer<Integer>>>(denominator)->getRemainder(num256),
			rem->isZero()){
		denominator = staticPointerCast<IntegerArithmetic<Pointer<Integer>>>(denominator)->getIntegerQuotient(num256);
		power = staticPointerCast<Integer>(power->getDifference(ONE()));
	}
	m_numerator = numerator;
	m_denominator = staticPointerCast<Unsigned>(denominator);
	m_power = power;
}

Pointer<FloatingPoint> FloatingPoint::fromFraction(
		Pointer<Integer> numerator,
		Pointer<Integer> denominator,
		Pointer<Integer> power){
	return make_shared<const FloatingPoint>(numerator, denominator, power);
}

Pointer<FloatingPoint> FloatingPoint::fromBinaryFractionInStrings(const string &numerator,
		const string &denominator){
	Pointer<Integer>
		num { Integer::fromBinaryInString(numerator) },
		den { Integer::fromBinaryInString(denominator) };
	return fromFraction(num, den, ZERO());
}

Pointer<FloatingPoint> FloatingPoint::fromOctalFractionInStrings(const string &numerator, const string &denominator){
	Pointer<Integer>
		num { Integer::fromOctalInString(numerator) },
		den { Integer::fromOctalInString(denominator) };
	return fromFraction(num, den, ZERO());
}

Pointer<FloatingPoint> FloatingPoint::fromDecimalFractionInStrings(const string &numerator, const string &denominator){
	Pointer<Integer>
		num { Integer::fromDecimalInString(numerator) },
		den { Integer::fromDecimalInString(denominator) };
	return fromFraction(num, den, ZERO());
}

Pointer<FloatingPoint> FloatingPoint::fromHexadecimalFractionInStrings(const string &numerator, const string &denominator){
	Pointer<Integer>
		num = Integer::fromHexadecimalInString(numerator),
		den = Integer::fromHexadecimalInString(denominator);
	return fromFraction(num, den, ZERO());
}

Pointer<FloatingPoint> FloatingPoint::fromFloat(const string &number,
		const string &base,
		const function<Pointer<Integer> const(const string &)> &numeratorCreator){
	string copy = number;
	auto iter = find(copy.begin(), copy.end(), '.');
	unsigned long long position = iter - copy.begin();
	if(iter == copy.end()) position = 0;
	else{
		position = copy.length() - position - 1;
		copy.erase(iter);
	}
	Pointer<Integer>
			num = numeratorCreator(copy),
			baseInt = Integer::fromDecimalInString(base),
			den = staticPointerCast<Integer>(ONE()->copy());
	for(unsigned long long i = 0; i < position; ++i){
		den = staticPointerCast<Integer>(den->getProduct(baseInt));
	}
	return fromFraction(num, den, ZERO());
}

Pointer<FloatingPoint> FloatingPoint::fromBinaryFloatInString(const string &number){
	return fromFloat(number, "2", Integer::fromBinaryInString);
}

Pointer<FloatingPoint> FloatingPoint::fromOctalFloatInString(const string &number){
	return fromFloat(number, "8", Integer::fromOctalInString);
}

Pointer<FloatingPoint> FloatingPoint::fromDecimalFloatInString(const string &number){
	return fromFloat(number, "10", Integer::fromDecimalInString);
}

Pointer<FloatingPoint> FloatingPoint::fromHexadecimalFloatInString(const string &number){
	return fromFloat(number, "16", Integer::fromHexadecimalInString);
}

FloatingPoint::~FloatingPoint() noexcept{
}

//======================================
//--------------COPYABLE----------------
//======================================

Pointer<Number> FloatingPoint::copy() const{
	return getAsFloatingPoint();
}

//======================================
//-------------ARITHMETIC---------------
//======================================

Pointer<Number> FloatingPoint::getSum(Pointer<Number> toAdd) const{
	if(!toAdd) REPORT_ERROR(exception("Null pointer exception"), nullptr);
	return toAdd->getSum(sharedThis());
}

Pointer<Number> FloatingPoint::getSum(Pointer<Complex> toAdd) const{
	if(!toAdd) REPORT_ERROR(exception("Null pointer exception"), nullptr);
	return toAdd->getSum(sharedThis());
}

Pointer<Number> FloatingPoint::getSum(Pointer<FloatingPoint> toAdd) const{
	if(!toAdd)
		REPORT_ERROR(exception("Null pointer exception"), nullptr);
	if(m_denominator->compare(toAdd->m_denominator) && this->m_power->compare(toAdd->m_power)){
		Pointer<Number> sum = m_numerator->getSum(toAdd->m_numerator);
		return fromFraction(staticPointerCast<Integer>(sum), m_denominator, m_power);
	}else{
		Pointer<Integer> GCD = getGCD(this->m_denominator, toAdd->m_denominator);
		Pointer<Integer>
			multiplicand1 = staticPointerCast<IntegerArithmetic<Pointer<Integer>>>(
					toAdd->m_denominator)->getIntegerQuotient(GCD),
			multiplicand2 = staticPointerCast<IntegerArithmetic<Pointer<Integer>>>(
					m_denominator)->getIntegerQuotient(GCD);
		Pointer<Integer>
			numerator1 = staticPointerCast<Integer>(multiplicand1->getProduct(m_numerator)),
			numerator2 = staticPointerCast<Integer>(multiplicand2->getProduct(toAdd->m_numerator)),
			denominator = getLCM(m_denominator, toAdd->m_denominator);
		Pointer<Integer>
			powerDiff { staticPointerCast<Integer>(m_power->getDifference(toAdd->m_power)) };
		Pointer<Number> num256 { Unsigned::fromDecimalInString("256") };
		while(!(powerDiff->isZero())){
			if(powerDiff->isNegative()){
				numerator2 = staticPointerCast<Integer>(numerator2->getProduct(num256));
				powerDiff = staticPointerCast<Integer>(powerDiff->getSum(ONE()));
			}
			else{
				numerator1 = staticPointerCast<Integer>(numerator1->getProduct(num256));
				powerDiff = staticPointerCast<Integer>(powerDiff->getDifference(ONE()));
			}
		}
		Pointer<Integer> sum = staticPointerCast<Integer>(numerator1->getSum(numerator2));
		return fromFraction(sum,
				denominator,
				m_power->compare(toAdd->m_power) == CompareResult::ThisLesser ? m_power :
						toAdd->m_power
		);
	}
}

Pointer<Number> FloatingPoint::getSum(Pointer<Signed> toAdd) const{
	if(!toAdd) REPORT_ERROR(exception("Null pointer exception"), nullptr);
	Pointer<FloatingPoint> left = toAdd->getAsFloatingPoint();
	return left->getSum(sharedThis());
}

Pointer<Number> FloatingPoint::getSum(Pointer<Unsigned> toAdd) const{
	if(!toAdd) REPORT_ERROR(exception("Null pointer exception"), nullptr);
	Pointer<FloatingPoint> left = toAdd->getAsFloatingPoint();
	return left->getSum(sharedThis());
}

Pointer<Number> FloatingPoint::getProduct(Pointer<Number> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(exception("Null pointer exception"), nullptr);
	return toMultiply->getProduct(sharedThis());
}

Pointer<Number> FloatingPoint::getProduct(Pointer<Complex> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(exception("Null pointer exception"), nullptr);
	return toMultiply->getProduct(sharedThis());
}

Pointer<Number> FloatingPoint::getProduct(Pointer<FloatingPoint> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(exception("Null pointer exception"), nullptr);
	Pointer<Integer>
		numerator = staticPointerCast<Integer>(m_numerator->getProduct(toMultiply->m_numerator)),
		denominator = staticPointerCast<Integer>(m_denominator->getProduct(toMultiply->m_denominator)),
		power = staticPointerCast<Integer>(m_power->getSum(toMultiply->m_power));
	return fromFraction(numerator, denominator, power);
}

Pointer<Number> FloatingPoint::getProduct(Pointer<Signed> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(exception("Null pointer exception"), nullptr);
	Pointer<FloatingPoint> left = toMultiply->getAsFloatingPoint();
	return left->getProduct(sharedThis());
}

Pointer<Number> FloatingPoint::getProduct(Pointer<Unsigned> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(exception("Null pointer exception"), nullptr);
	Pointer<FloatingPoint> left = toMultiply->getAsFloatingPoint();
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

Pointer<Unsigned> FloatingPoint::getAsUnsignedInteger() const{
	Pointer<Integer>
		tmp = staticPointerCast<coma::numb::IntegerArithmetic<Pointer<Unsigned>, Pointer<Integer>>>(
				m_numerator)->getIntegerQuotient(m_denominator);
	return tmp->getAsUnsignedInteger();
}

Pointer<Signed> FloatingPoint::getAsSignedInteger() const{
	Pointer<Integer>
		tmp = staticPointerCast<coma::numb::IntegerArithmetic<Pointer<Unsigned>, Pointer<Integer>>>(
			m_numerator)->getIntegerQuotient(m_denominator);
	return tmp->getAsSignedInteger();
}

Pointer<FloatingPoint> FloatingPoint::getAsFloatingPoint() const{
	return sharedThis();
}

Pointer<Complex> FloatingPoint::getAsComplex() const{
	//TODO complete after Complex definition
}

Pointer<Number> FloatingPoint::getNegation() const{
	return make_shared<FloatingPoint>(
			staticPointerCast<Integer>(m_numerator->getNegation()),
			m_denominator,
			m_power);
}

Pointer<Number> FloatingPoint::getInversion() const{
	if (m_numerator->isZero()) throw 1; //TODO exceptions
	return fromFraction(m_denominator, m_numerator,
			staticPointerCast<Integer>(m_power->getNegation()));
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

Pointer<FloatingPoint> FloatingPoint::sharedThis() const{
	return staticPointerCast<FloatingPoint>(shared_from_this());
}

void FloatingPoint::makeThisZero(){
	m_numerator = ZERO();
	m_denominator = ONE();
	m_power = ZERO();
}

} /* namespace numb */
} /* namespace coma */
