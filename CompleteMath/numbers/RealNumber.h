/*
 * RealNumber.h
 *
 *  Created on: 24 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_REALNUMBER_H_
#define NUMBERS_REALNUMBER_H_

#include "Comparable.h"
#include "Number.h"

namespace coma {
namespace numb {

class FloatingPoint;
class Integer;

/**
 * @brief
 * 	Interface for real numbers.
 */
class RealNumber:
		public Number,
		public Comparable<RealNumber>,
		public Comparable<FloatingPoint>,
		public Arithmetic<FloatingPoint, Number>,
		public Comparable<Integer>,
		public Arithmetic<Integer, Number>{
public:
	/**
	 * @brief
	 * 	Method to check if stored value is positive or negative.
	 *
	 * @details
	 * 	0 (zero) is treated as neither positive nor negative value.
	 *
	 * @return
	 * 	True if stored value is negative.
	 * 	False if stored value is non-negative.
	 */
	virtual const bool isNegative() const = 0;

	/**
	 * @brief
	 * 	Method to check if stored value is positive or positive.
	 *
	 * @copydetails isNegative()
	 *
	 * @return
	 * 	True if stored value is positive.
	 * 	False if stored value is non-positive.
	 */
	virtual const bool isPositive() const = 0;

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
	 * @brief
	 * 	Dummy virtual destructor.
	 */
	virtual ~RealNumber(){}
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_REALNUMBER_H_ */
