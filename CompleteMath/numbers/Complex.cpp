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

Pointer<const Complex> Complex::fromRealAndImaginary(const Pointer<const RealNumber> real, const Pointer<const RealNumber> imaginary){
	if(!real || !imaginary) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return std::make_shared<const Complex>(real, imaginary);
}

Complex::Complex(const Pointer<const RealNumber> real, const Pointer<const RealNumber> imaginary):
	m_real{real},
	m_imaginary{imaginary}{}

Complex::~Complex() noexcept{
}

//======================================
//--------------COPYABLE----------------
//======================================

Pointer<const Number> Complex::copy() const{
	return getAsComplex();
}

//======================================
//-------------ARITHMETIC---------------
//======================================

Pointer<const Number> Complex::getSum(Pointer<const Number> toAdd) const{
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toAdd->getSum(sharedThis());
}

Pointer<const Number> Complex::getSum(Pointer<const Complex> toAdd) const{
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	Pointer<const RealNumber> real = std::static_pointer_cast<const RealNumber>(toAdd->m_real->getSum(m_real));
	Pointer<const RealNumber> im   = std::static_pointer_cast<const RealNumber>(toAdd->m_imaginary->getSum(m_imaginary));
	return fromRealAndImaginary(real, im);
}

Pointer<const Number> Complex::getSum(Pointer<const FloatingPoint> toAdd) const{
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	Pointer<const Complex> left = toAdd->getAsComplex();
	return left->getSum(sharedThis());
}

Pointer<const Number> Complex::getSum(Pointer<const Signed> toAdd) const{
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	Pointer<const Complex> left = toAdd->getAsComplex();
	return left->getSum(sharedThis());
}

Pointer<const Number> Complex::getSum(Pointer<const Unsigned> toAdd) const{
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	Pointer<const Complex> left = toAdd->getAsComplex();
	return left->getSum(sharedThis());
}

Pointer<const Number> Complex::getProduct(Pointer<const Number> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toMultiply->getProduct(sharedThis());
}

Pointer<const Number> Complex::getProduct(Pointer<const Complex> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	Pointer<const RealNumber>
		re1 = std::static_pointer_cast<const RealNumber>(m_real->getProduct(toMultiply->m_real)),
		re2 = std::static_pointer_cast<const RealNumber>(m_imaginary->getProduct(toMultiply->m_imaginary));
	Pointer<const RealNumber>
		im1 = std::static_pointer_cast<const RealNumber>(m_real->getProduct(toMultiply->m_imaginary)),
		im2 = std::static_pointer_cast<const RealNumber>(m_imaginary->getProduct(toMultiply->m_real));
	re1 = std::static_pointer_cast<const RealNumber>(re1->getDifference(re2));
	im1 = std::static_pointer_cast<const RealNumber>(im1->getSum(im2));
	return fromRealAndImaginary(re1, im1);
}

Pointer<const Number> Complex::getProduct(Pointer<const FloatingPoint> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	Pointer<const Complex> left = toMultiply->getAsComplex();
	return left->getProduct(sharedThis());
}

Pointer<const Number> Complex::getProduct(Pointer<const Signed> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	Pointer<const Complex> left = toMultiply->getAsComplex();
	return left->getProduct(sharedThis());
}

Pointer<const Number> Complex::getProduct(Pointer<const Unsigned> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	Pointer<const Complex> left = toMultiply->getAsComplex();
	return toMultiply->getProduct(sharedThis());
}

//======================================
//---------------NUMBER-----------------
//======================================

Pointer<const Number> Complex::getAbsoluteValue() const{
}

bool Complex::isZero() const noexcept{
	return m_real->isZero() && m_imaginary->isZero();
}

string Complex::getAsBinary() const{
	return m_real->getAsBinary() + m_imaginary->getAsBinary() + " * i";
}

string Complex::getAsOctal() const{
	return m_real->getAsOctal() + m_imaginary->getAsOctal() + " * i";
}

string Complex::getAsDecimal() const{
	return m_real->getAsDecimal() + m_imaginary->getAsDecimal() + " * i";
}

string Complex::getAsHexadecimal() const{
	return m_real->getAsHexadecimal() + m_imaginary->getAsHexadecimal() + " * i";
}

Pointer<const Unsigned> Complex::getAsUnsignedInteger() const{
	return m_real->getAsUnsignedInteger();
}

Pointer<const Signed> Complex::getAsSignedInteger() const{
	return m_real->getAsSignedInteger();
}

Pointer<const FloatingPoint> Complex::getAsFloatingPoint() const{
	return m_real->getAsFloatingPoint();
}

Pointer<const Complex> Complex::getAsComplex() const{
	return fromRealAndImaginary(m_real, m_imaginary);
}

Pointer<const Number> Complex::getNegation() const{
	Pointer<const RealNumber> re = std::static_pointer_cast<const RealNumber>(m_real->getNegation()) ;
	Pointer<const RealNumber> im = std::static_pointer_cast<const RealNumber>(m_imaginary->getNegation());
	return fromRealAndImaginary(re, im);
}

Pointer<const Number> Complex::getInversion() const{
	Pointer<const RealNumber> re = std::static_pointer_cast<const RealNumber>(m_real->getProduct(m_real));
	Pointer<const RealNumber> im = std::static_pointer_cast<const RealNumber>(m_imaginary->getProduct(m_imaginary));
	re = std::static_pointer_cast<const RealNumber>(re->getSum(im));
	im = std::static_pointer_cast<const RealNumber>(m_imaginary->getQuotient(re));
	re = std::static_pointer_cast<const RealNumber>(m_real->getQuotient(re));
	im = std::static_pointer_cast<const RealNumber>(im->getNegation());
	return fromRealAndImaginary(re, im);
}

Pointer<const Complex> Complex::sharedThis() const{
	return std::static_pointer_cast<const Complex>(shared_from_this());
}

} /* namespace numb */
} /* namespace coma */
