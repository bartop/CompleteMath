/*
 * Number.h
 *
 *  Created on: 23 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_NUMBER_H_
#define NUMBERS_NUMBER_H_

#include <string>

namespace cm {
namespace numb {

typedef std::string NumberInString;

/**
 * @brief
 *	Polymorphic interface for all numbers.
 */
class Number {
public:
	/**
	 * @{
	 *
	 * @brief
	 * 	Method to get opposite value.
	 *
	 * @return
	 * 	Negation of the number stored in @c *this.
	 */
	virtual const Number *const getNegation() const = 0;

	/**
	 * @brief
	 * 	Method to get inverse value.
	 *
	 * @return
	 * 	Inverse of the value stored in @c *this.
	 */
	virtual const Number *const getInversion() const = 0;


	/**
	 * @brief
	 * 	Method used to add numbers.
	 *
	 * @param toAdd
	 *	Number that is supposed to be added to @c *this.
	 *
	 * @return
	 * 	Sum of @c *this and @c toAdd.
	 */
	virtual const Number *const getSum(const Number *const toAdd) const = 0;

	/**
	 * @brief
	 * 	Method used to subtract numbers.
	 *
	 * @details
	 *	By default it is defined as @c this->(toSubtract->negate()), which may not be the most efficient but is
	 *	the most universal way of defining subtraction.
	 *
	 * @param toAdd
	 *	Number that is supposed to be subtracted from @c *this.
	 *
	 * @return
	 * 	Difference between @c *this and @c toSubtract.
	 */
	virtual const Number *const getDifference(const Number *const toSubtract) const = 0;

	/**
	 * @brief
	 * 	Method used to multiply numbers.
	 *
	 * @param toMultiply
	 *	Number that is supposed to be multiplied by @c *this.
	 *
	 * @return
	 * 	Product of @c *this and @c toMultiply.
	 */
	virtual const Number *const getProduct(const Number *const toMultiply) const = 0;

	/**
	 * @brief
	 * 	Method used to divide numbers.
	 *
	 * @details
	 *	By default it is defined as @c this->(toDivide->invert()), which may not be the most efficient but is
	 *	the most universal way of defining division.
	 *
	 * @param toDivide
	 * 	Number by which @c *this is supposed to be divided.
	 *
	 * @return
	 *	Quotient of @c *this and @c toDivide.
	 *
	 *	@}
	 */
	virtual const Number *const getQuotient(const Number *const toDivide) const = 0;

	/**
	 * @{
	 *
	 * @brief
	 * 	Method used to get stored value.
	 *
	 * @return
	 * 	Binary representation of the stored value.
	 */
	virtual const NumberInString getAsBinary() const = 0;

	/**
	 * @brief
	 * 	Method used to get stored value.
	 *
	 * @return
	 * 	Octal representation of the stored value.
	 */
	virtual const NumberInString getAsOctal() const = 0;

	/**
	 * @brief
	 * 	Method used to get stored value.
	 *
	 * @return
	 *	Decimal representation of the stored value.
	 */
	virtual const NumberInString getAsDecimal() const = 0;

	/**
	 * @brief
	 * 	Method used to get stored value.
	 *
	 * @return
	 *	Hexadecimal representation of the stored value.
	 *
	 * @}
	 */
	virtual const NumberInString getAsHexadecimal() const = 0;

	/**
	 * @brief
	 * 	Dummy virtual destructor.
	 */
	virtual ~Number(){}
};

} /* namespace numb */
} /* namespace cm */

#endif /* NUMBERS_NUMBER_H_ */
