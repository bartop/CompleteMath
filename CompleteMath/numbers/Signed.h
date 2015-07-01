/*
 * Signed.h
 *
 *  Created on: 27 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_SIGNED_H_
#define NUMBERS_SIGNED_H_

#include "Integer.h"

namespace coma {
namespace numb {

class Signed: public Integer {
public:
	Signed();

	//======================================
	//-------------COMPARABLE---------------
	//======================================

	virtual const CompareResult compare(const Integer *const toCompare) const override;
	virtual const CompareResult compare(const Signed *const toCompare) const override;
	virtual const CompareResult compare(const Unsigned *const toCompare) const override;

	//======================================
	//-------------ARITHMETIC---------------
	//======================================
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

	virtual const NumberInString getAsBinary() const override;
	virtual const NumberInString getAsOctal() const override;
	virtual const NumberInString getAsDecimal() const override;
	virtual const NumberInString getAsHexadecimal() const override;

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

	//======================================
	//---------INTEGERARITHMETIC------------
	//======================================

	/**
	 * @{
	 */

	virtual Integer *const getIntegerQuotient(const Integer *const toDivide) const override;
	virtual Integer *const getRemainder(const Integer *const toDivide) const override;
	virtual Integer *const getIntegerQuotientInverse(const Integer *const dividend) const override;
	virtual Integer *const getInverseRemainder(const Integer *const dividend) const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Integer *const getIntegerQuotient(const Signed *const toDivide) const override;
	virtual Integer *const getRemainder(const Signed *const toDivide) const override;
	virtual Integer *const getIntegerQuotientInverse(const Signed *const dividend) const override;
	virtual Integer *const getInverseRemainder(const Signed *const dividend) const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Integer *const getIntegerQuotient(const Unsigned *const toDivide) const override;
	virtual Integer *const getRemainder(const Unsigned *const toDivide) const override;
	virtual Integer *const getIntegerQuotientInverse(const Unsigned *const dividend) const override;
	virtual Integer *const getInverseRemainder(const Unsigned *const dividend) const override;

	/**
	 * @}
	 */

	virtual ~Signed();
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_SIGNED_H_ */
