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

	virtual Number *const getSum(const FloatingPoint *const toAdd) const override;
	virtual Number *const getDifference(const FloatingPoint *const toSubtract) const override;
	virtual Number *const getProduct(const FloatingPoint *const toMultiply) const override;
	virtual Number *const getQuotient(const FloatingPoint *const toDivide) const override;
	virtual Number *const getDifferenceNegation(const FloatingPoint *const minuend) const override;
	virtual Number *const getQuotientInverse(const FloatingPoint *const dividend) const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Number *const getSum(const Signed *const toAdd) const override;
	virtual Number *const getDifference(const Signed *const toSubtract) const override;
	virtual Number *const getProduct(const Signed *const toMultiply) const override;
	virtual Number *const getQuotient(const Signed *const toDivide) const override;
	virtual Number *const getDifferenceNegation(const Signed *const minuend) const override;
	virtual Number *const getQuotientInverse(const Signed *const dividend) const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Number *const getSum(const Unsigned *const toAdd) const override;
	virtual Number *const getDifference(const Unsigned *const toSubtract) const override;
	virtual Number *const getProduct(const Unsigned *const toMultiply) const override;
	virtual Number *const getQuotient(const Unsigned *const toDivide) const override;
	virtual Number *const getDifferenceNegation(const Unsigned *const minuend) const override;
	virtual Number *const getQuotientInverse(const Unsigned *const dividend) const override;

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

	virtual const std::string getAsBinary() const override;
	virtual const std::string getAsOctal() const override;
	virtual const std::string getAsDecimal() const override;
	virtual const std::string getAsHexadecimal() const override;

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
