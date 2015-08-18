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

using namespace std;

//======================================
//--------------COMPLEX-----------------
//======================================

Complex *Complex::fromRealAndImaginary(const RealNumber *real, const RealNumber *imaginary){
	return new Complex{real, imaginary};
}

Complex::Complex(const RealNumber *real, const RealNumber *imaginary):
	m_real{static_cast<const RealNumber *>(real->copy())},
	m_imaginary{static_cast<const RealNumber *>(imaginary->copy())}{}

Complex::~Complex(){
	if(m_imaginary) delete m_imaginary;
	if(m_real) delete m_real;
}

//======================================
//--------------COPYABLE----------------
//======================================

Number *Complex::copy() const{
	return getAsComplex();
}

//======================================
//-------------ARITHMETIC---------------
//======================================

Number *Complex::getSum(const Number *toAdd) const{
	return toAdd->getSum(this);
}

Number *Complex::getSum(const Complex *toAdd) const{
	unique_ptr<RealNumber> real { static_cast<RealNumber *>(toAdd->m_real->getSum(this->m_real)) };
	unique_ptr<RealNumber> im   { static_cast<RealNumber *>(toAdd->m_imaginary->getSum(this->m_imaginary)) };
	return fromRealAndImaginary(real.get(), im.get());
}

Number *Complex::getSum(const FloatingPoint *toAdd) const{
	unique_ptr<Complex> left { toAdd->getAsComplex() };
	return left->getSum(this);
}

Number *Complex::getSum(const Signed *toAdd) const{
	unique_ptr<Complex> left { toAdd->getAsComplex() };
	return left->getSum(this);
}

Number *Complex::getSum(const Unsigned *toAdd) const{
	unique_ptr<Complex> left { toAdd->getAsComplex() };
	return left->getSum(this);
}

Number *Complex::getProduct(const Number *toMultiply) const{
	return toMultiply->getProduct(this);
}

Number *Complex::getProduct(const Complex *toMultiply) const{
	unique_ptr<RealNumber>
		re1{ static_cast<RealNumber *>(m_real->getProduct(toMultiply->m_real)) },
		re2{ static_cast<RealNumber *>(m_imaginary->getProduct(toMultiply->m_imaginary)) };
	unique_ptr<RealNumber>
		im1{ static_cast<RealNumber *>(m_real->getProduct(toMultiply->m_imaginary)) },
		im2{ static_cast<RealNumber *>(m_imaginary->getProduct(toMultiply->m_real)) };
	re1.reset(static_cast<RealNumber *>(re1->getDifference(re2.get())));
	im1.reset(static_cast<RealNumber *>(im1->getSum(im2.get())));
	return fromRealAndImaginary(re1.get(), im1.get());
}

Number *Complex::getProduct(const FloatingPoint *toMultiply) const{
	unique_ptr<Complex> left { toMultiply->getAsComplex() };
	return left->getProduct(this);
}

Number *Complex::getProduct(const Signed *toMultiply) const{
	unique_ptr<Complex> left { toMultiply->getAsComplex() };
	return left->getProduct(this);
}

Number *Complex::getProduct(const Unsigned *toMultiply) const{
	unique_ptr<Complex> left { toMultiply->getAsComplex() };
	return toMultiply->getProduct(this);
}

//======================================
//---------------NUMBER-----------------
//======================================

Number *Complex::getAbsoluteValue() const{
}

const bool Complex::isZero() const{
	return m_real->isZero() && m_imaginary->isZero();
}

const string Complex::getAsBinary() const{
	return m_real->getAsBinary() + m_imaginary->getAsBinary() + " * i";
}

const string Complex::getAsOctal() const{
	return m_real->getAsOctal() + m_imaginary->getAsOctal() + " * i";
}

const string Complex::getAsDecimal() const{
	return m_real->getAsDecimal() + m_imaginary->getAsDecimal() + " * i";
}

const string Complex::getAsHexadecimal() const{
	return m_real->getAsHexadecimal() + m_imaginary->getAsHexadecimal() + " * i";
}

Unsigned *Complex::getAsUnsignedInteger() const{
	return m_real->getAsUnsignedInteger();
}

Signed *Complex::getAsSignedInteger() const{
	return m_real->getAsSignedInteger();
}

FloatingPoint *Complex::getAsFloatingPoint() const{
	return m_real->getAsFloatingPoint();
}

Complex *Complex::getAsComplex() const{
	return fromRealAndImaginary(m_real, m_imaginary);
}

Number *Complex::getNegation() const{
	unique_ptr<RealNumber> re{ static_cast<RealNumber *>(m_real->getNegation()) };
	unique_ptr<RealNumber> im{ static_cast<RealNumber *>(m_imaginary->getNegation()) };
	return fromRealAndImaginary(re.get(), im.get());
}

Number *Complex::getInversion() const{
	unique_ptr<RealNumber> re{ static_cast<RealNumber *>(m_real->getProduct(m_real)) };
	unique_ptr<RealNumber> im{ static_cast<RealNumber *>(m_imaginary->getProduct(m_imaginary)) };
	re.reset(static_cast<RealNumber *>(re->getSum(im.get())));
	im.reset(static_cast<RealNumber *>(m_imaginary->getQuotient(re.get())));
	re.reset(static_cast<RealNumber *>(m_real->getQuotient(re.get())));
	im.reset(static_cast<RealNumber *>(im->getNegation()));
	return fromRealAndImaginary(re.get(), im.get());
}

} /* namespace numb */
} /* namespace coma */
