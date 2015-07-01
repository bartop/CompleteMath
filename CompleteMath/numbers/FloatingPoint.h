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

class FloatingPoint: public coma::numb::RealNumber {
public:
	FloatingPoint();

	//======================================
	//-------------COMPARABLE---------------
	//======================================

	/**
	 * @{
	 */

	virtual const CompareResult compare(const RealNumber *const toCompare) const override;
	virtual const CompareResult compare(const FloatingPoint *const toCompare) const override;
	virtual const CompareResult compare(const Integer *const toCompare) const override;

	/**
	 * @}
	 */

	//======================================
	//-------------ARITHMETIC---------------
	//======================================

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

	virtual Number *const getSum(const Integer *const toAdd) const override;
	virtual Number *const getDifference(const Integer *const toSubtract) const override;
	virtual Number *const getProduct(const Integer *const toMultiply) const override;
	virtual Number *const getQuotient(const Integer *const toDivide) const override;
	virtual Number *const getDifferenceNegation(const Integer *const minuend) const override;
	virtual Number *const getQuotientInverse(const Integer *const dividend) const override;

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
