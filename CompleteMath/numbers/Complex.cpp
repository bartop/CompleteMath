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

Pointer<Complex> Complex::fromRealAndImaginary(const Pointer<RealNumber> real, const Pointer<RealNumber> imaginary){
	if(!real || !imaginary) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return std::make_shared<const Complex>(real, imaginary);
}

Complex::Complex(const Pointer<RealNumber> real, const Pointer<RealNumber> imaginary):
	m_real{real},
	m_imaginary{imaginary}{}

Complex::~Complex() noexcept{
}

//======================================
//--------------COPYABLE----------------
//======================================

Pointer<Number> Complex::copy() const{
	return getAsComplex();
}

//======================================
//-------------ARITHMETIC---------------
//======================================

Pointer<Number> Complex::getSum(Pointer<Number> toAdd) const{
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toAdd->getSum(sharedThis());
}

Pointer<Number> Complex::getSum(Pointer<Complex> toAdd) const{
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	Pointer<RealNumber> real = staticPointerCast<RealNumber>(toAdd->m_real->getSum(m_real));
	Pointer<RealNumber> im   = staticPointerCast<RealNumber>(toAdd->m_imaginary->getSum(m_imaginary));
	return fromRealAndImaginary(real, im);
}

Pointer<Number> Complex::getSum(Pointer<FloatingPoint> toAdd) const{
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	Pointer<Complex> left = toAdd->getAsComplex();
	return left->getSum(sharedThis());
}

Pointer<Number> Complex::getSum(Pointer<Signed> toAdd) const{
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	Pointer<Complex> left = toAdd->getAsComplex();
	return left->getSum(sharedThis());
}

Pointer<Number> Complex::getSum(Pointer<Unsigned> toAdd) const{
	if(!toAdd) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	Pointer<Complex> left = toAdd->getAsComplex();
	return left->getSum(sharedThis());
}

Pointer<Number> Complex::getProduct(Pointer<Number> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	return toMultiply->getProduct(sharedThis());
}

Pointer<Number> Complex::getProduct(Pointer<Complex> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	Pointer<RealNumber>
		re1 = staticPointerCast<RealNumber>(m_real->getProduct(toMultiply->m_real)),
		re2 = staticPointerCast<RealNumber>(m_imaginary->getProduct(toMultiply->m_imaginary));
	Pointer<RealNumber>
		im1 = staticPointerCast<RealNumber>(m_real->getProduct(toMultiply->m_imaginary)),
		im2 = staticPointerCast<RealNumber>(m_imaginary->getProduct(toMultiply->m_real));
	re1 = staticPointerCast<RealNumber>(re1->getDifference(re2));
	im1 = staticPointerCast<RealNumber>(im1->getSum(im2));
	return fromRealAndImaginary(re1, im1);
}

Pointer<Number> Complex::getProduct(Pointer<FloatingPoint> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	Pointer<Complex> left = toMultiply->getAsComplex();
	return left->getProduct(sharedThis());
}

Pointer<Number> Complex::getProduct(Pointer<Signed> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	Pointer<Complex> left = toMultiply->getAsComplex();
	return left->getProduct(sharedThis());
}

Pointer<Number> Complex::getProduct(Pointer<Unsigned> toMultiply) const{
	if(!toMultiply) REPORT_ERROR(std::exception("Null pointer exception"), nullptr);
	Pointer<Complex> left = toMultiply->getAsComplex();
	return toMultiply->getProduct(sharedThis());
}

//======================================
//---------------NUMBER-----------------
//======================================

Pointer<Number> Complex::getAbsoluteValue() const{
	Pointer<Number> alpha = FloatingPoint::fromDecimalFloatInString("0.96043387");
	Pointer<Number> beta = FloatingPoint::fromDecimalFloatInString("0.39782473");
	if(m_imaginary->compare(m_real) == core::CompareResult::ThisGreater){
		return alpha->getProduct(m_imaginary)->getSum(beta->getProduct(m_real));
	}else{
		return alpha->getProduct(m_real)->getSum(beta->getProduct(m_imaginary));
	}
}

bool Complex::isZero() const noexcept{
	return m_real->isZero() && m_imaginary->isZero();
}

string Complex::getAsBinary() const{
	return m_real->getAsBinary() + " + " + m_imaginary->getAsBinary() + " * i";
}

string Complex::getAsOctal() const{
	return m_real->getAsOctal() + " + " + m_imaginary->getAsOctal() + " * i";
}

string Complex::getAsDecimal() const{
	return m_real->getAsDecimal() + " + " + m_imaginary->getAsDecimal() + " * i";
}

string Complex::getAsHexadecimal() const{
	return m_real->getAsHexadecimal() + " + " + m_imaginary->getAsHexadecimal() + " * i";
}

Pointer<Unsigned> Complex::getAsUnsignedInteger() const{
	return m_real->getAsUnsignedInteger();
}

Pointer<Signed> Complex::getAsSignedInteger() const{
	return m_real->getAsSignedInteger();
}

Pointer<FloatingPoint> Complex::getAsFloatingPoint() const{
	return m_real->getAsFloatingPoint();
}

Pointer<Complex> Complex::getAsComplex() const{
	return fromRealAndImaginary(m_real, m_imaginary);
}

Pointer<Number> Complex::getNegation() const{
	Pointer<RealNumber> re = staticPointerCast<RealNumber>(m_real->getNegation()) ;
	Pointer<RealNumber> im = staticPointerCast<RealNumber>(m_imaginary->getNegation());
	return fromRealAndImaginary(re, im);
}

Pointer<Number> Complex::getInversion() const{
	Pointer<RealNumber> re = staticPointerCast<RealNumber>(m_real->getProduct(m_real));
	Pointer<RealNumber> im = staticPointerCast<RealNumber>(m_imaginary->getProduct(m_imaginary));
	re = staticPointerCast<RealNumber>(re->getSum(im));
	im = staticPointerCast<RealNumber>(m_imaginary->getQuotient(re));
	re = staticPointerCast<RealNumber>(m_real->getQuotient(re));
	im = staticPointerCast<RealNumber>(im->getNegation());
	return fromRealAndImaginary(re, im);
}

Pointer<Complex> Complex::sharedThis() const{
	return staticPointerCast<Complex>(shared_from_this());
}

} /* namespace numb */
} /* namespace coma */
