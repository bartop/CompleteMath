/*
 * FloatingPoint.h
 *
 *  Created on: 27 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_FLOATINGPOINT_H_
#define NUMBERS_FLOATINGPOINT_H_

#include "RealNumber.h"

namespace coma {
namespace numb {

class Signed;
class Unsigned;
class Integer;

class FloatingPoint: public RealNumber {

	const Integer *const m_numerator;
	const Unsigned *const m_denominator;
	const Integer *const m_power;

public:
	/**
	 * @brief
	 * 	Creates floating point number as quotient of two integers.
	 *
	 * @details
	 * 	The number is stored in unusual kind of way: (numerator/denominator) * 256^power.
	 *
	 * @param numerator
	 * 	Numerator of real number.
	 *
	 * @param denominator
	 * 	Denominator of desired real number.
	 *
	 * @param power
	 *	Power in formula given above.
	 */
	FloatingPoint(const Integer *const numerator, const Unsigned *const denominator, const Integer *const power);

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
	 *
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

	//======================================
	//-------------REALNUMBER---------------
	//======================================

	/**
	 * @{
	 */

	virtual const bool isNegative() const override;
	virtual const bool isPositive() const override;

	/**
	 * @}
	 */

	virtual ~FloatingPoint();
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_FLOATINGPOINT_H_ */
