/*
 * Complex.h
 *
 *  Created on: 27 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_COMPLEX_H_
#define NUMBERS_COMPLEX_H_

#include "Number.h"

namespace coma {
namespace numb {

class Complex:
		public Number {
public:
	Complex();

	//======================================
	//-------------ARITHMETIC---------------
	//======================================

	/**
	 * @{
	 */

	virtual Number *const getSum(const Number *const toAdd) const override;
	virtual Number *const getDifference(const Number *const toSubtract) const override;
	virtual Number *const getProduct(const Number *const toMultiply) const override;
	virtual Number *const getQuotient(const Number *const toDivide) const override;
	virtual Number *const getDifferenceNegation(const Number *const minuend) const override;
	virtual Number *const getQuotientInverse(const Number *const dividend) const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Number *const getSum(const Complex *const toAdd) const override;
	virtual Number *const getDifference(const Complex *const toSubtract) const override;
	virtual Number *const getProduct(const Complex *const toMultiply) const override;
	virtual Number *const getQuotient(const Complex *const toDivide) const override;
	virtual Number *const getDifferenceNegation(const Complex *const minuend) const override;
	virtual Number *const getQuotientInverse(const Complex *const dividend) const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Number *const getSum(const RealNumber *const toAdd) const override;
	virtual Number *const getDifference(const RealNumber *const toSubtract) const override;
	virtual Number *const getProduct(const RealNumber *const toMultiply) const override;
	virtual Number *const getQuotient(const RealNumber *const toDivide) const override;
	virtual Number *const getDifferenceNegation(const RealNumber *const minuend) const override;
	virtual Number *const getQuotientInverse(const RealNumber *const dividend) const override;

	/**
	 * @}
	 */

	//======================================
	//---------------NUMBER-----------------
	//======================================

	virtual const bool isZero() const override;

	/**
	 * @{
	 */

	virtual const NumberInString getAsBinary() const override;
	virtual const NumberInString getAsOctal() const override;
	virtual const NumberInString getAsDecimal() const override;
	virtual const NumberInString getAsHexadecimal() const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Unsigned *const getAsUnsignedInteger() const override;
	virtual Signed *const getAsSignedInteger() const override;
	virtual FloatingPoint *const getAsFloatingPoint() const override;
	virtual Complex *const getAsComplex() const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Number *const getNegation() const override;
	virtual Number *const getInversion() const override;

	/**
	 * @}
	 */

	virtual ~Complex();
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_COMPLEX_H_ */
