/*
 * Number.h
 *
 *  Created on: 23 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_NUMBER_H_
#define NUMBERS_NUMBER_H_

#include <string>
#include "Arithmetic.h"

namespace coma {
namespace numb {

typedef std::string NumberInString;

class Complex;
class FloatingPoint;
class Signed;
class Unsigned;

/**
 * @brief
 *	Polymorphic interface for all numbers.
 */
class Number :
	public Arithmetic<Number>,
	public Arithmetic<Complex, Number>,
	public Arithmetic<FloatingPoint, Number>,
	public Arithmetic<Signed, Number>,
	public Arithmetic<Unsigned, Number>{
public:
	/**
	 * @brief
	 * 	Method to get opposite value.
	 *
	 * @return
	 * 	Negation of the number stored in @c *this.
	 */
	virtual Number *const getNegation() const = 0;

	/**
	 * @brief
	 * 	Method to get inverse value.
	 *
	 * @return
	 * 	Inverse of the value stored in @c *this.
	 */
	virtual Number *const getInversion() const = 0;

	/**
	 * @brief
	 * 	Checks if stored value is equal to zero.
	 *
	 * @return
	 * 	True if stored value equals 0. Else returns false.
	 */
	virtual const bool isZero() const = 0;

	/**
	 * @{
	 */

	/**
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
	 */
	virtual const NumberInString getAsHexadecimal() const = 0;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	/**
	 *
	 * @brief
	 *	Returns @c *this as Unsigned object.
	 *
	 * @details
	 * 	It is worth mentioning that casting from simpler type to more complex one causes no data loss, while casting in
	 * 	the opposite direction may cause rounding and/or truncating data. Use carefully. \n
	 * 	Number subtypes listed from the most to the least complex:
	 * 		- Complex
	 * 		- FloatingPoint
	 * 		- Signed
	 * 		- Unsigned
	 *
	 * @return
	 * 	Unsigned representation of @c *this object.
	 */
	virtual Unsigned *const getAsUnsignedInteger() const = 0;

	/**
	 * @brief
	 *	Returns @c *this as Signed object.
	 *
	 * @copydetails getAsUnsignedInteger
	 *
	 * @return
	 * 	Signed representation of @c *this object.
	 */
	virtual Signed *const getAsSignedInteger() const = 0;

	/**
	 * @brief
	 *	Returns @c *this as FloatingPoint object.
	 *
	 * @copydetails getAsUnsignedInteger
	 *
	 * @return
	 * 	FloatingPoint representation of @c *this object.
	 */
	virtual FloatingPoint *const getAsFloatingPoint() const = 0;

	/**
	 * @brief
	 *	Returns @c *this as Complex object.
	 *
	 * @copydetails getAsUnsignedInteger
	 *
	 * @return
	 * 	Complex representation of @c *this object.
	 */
	virtual Complex *const getAsComplex() const = 0;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	/**
	 * @brief
	 * 	Method used to subtract numbers.
	 *
	 * @param minuend
	 * 	Number from which @c *this is subtracted.
	 *
	 * @return
	 * 	Difference between @c minuend and @c *this.
	 */
	virtual Number *const getDifferenceNegation(const Number *const minuend) const;

	/**
	 * @brief
	 * 	Method used to divide numbers.
	 *
	 * @param dividend
	 *  Number which is supposed to be divided by @c *this.
	 *
	 * @return
	 *	Quotient of @c dividend and @c *this.
	 */
	virtual Number *const getQuotientInverse(const Number *const dividend) const;

	/**
	 * @brief
	 * 	Method used to subtract numbers.
	 *
	 * @param minuend
	 * 	Number from which @c *this is subtracted.
	 *
	 * @return
	 * 	Difference between @c minuend and @c *this.
	 */
	virtual Number *const getDifferenceNegation(const Complex *const minuend) const;

	/**
	 * @brief
	 * 	Method used to divide numbers.
	 *
	 * @param dividend
	 *  Number which is supposed to be divided by @c *this.
	 *
	 * @return
	 *	Quotient of @c dividend and @c *this.
	 */
	virtual Number *const getQuotientInverse(const Complex *const dividend) const;

	/**
	 * @brief
	 * 	Method used to subtract numbers.
	 *
	 * @param minuend
	 * 	Number from which @c *this is subtracted.
	 *
	 * @return
	 * 	Difference between @c minuend and @c *this.
	 */
	virtual Number *const getDifferenceNegation(const FloatingPoint *const minuend) const;

	/**
	 * @brief
	 * 	Method used to divide numbers.
	 *
	 * @param dividend
	 *  Number which is supposed to be divided by @c *this.
	 *
	 * @return
	 *	Quotient of @c dividend and @c *this.
	 */
	virtual Number *const getQuotientInverse(const FloatingPoint *const dividend) const;

	/**
	 * @brief
	 * 	Method used to subtract numbers.
	 *
	 * @param minuend
	 * 	Number from which @c *this is subtracted.
	 *
	 * @return
	 * 	Difference between @c minuend and @c *this.
	 */
	virtual Number *const getDifferenceNegation(const Signed *const minuend) const;

	/**
	 * @brief
	 * 	Method used to divide numbers.
	 *
	 * @param dividend
	 *  Number which is supposed to be divided by @c *this.
	 *
	 * @return
	 *	Quotient of @c dividend and @c *this.
	 */
	virtual Number *const getQuotientInverse(const Signed *const dividend) const;

	/**
	 * @brief
	 * 	Method used to subtract numbers.
	 *
	 * @param minuend
	 * 	Number from which @c *this is subtracted.
	 *
	 * @return
	 * 	Difference between @c minuend and @c *this.
	 */
	virtual Number *const getDifferenceNegation(const Unsigned *const minuend) const;

	/**
	 * @brief
	 * 	Method used to divide numbers.
	 *
	 * @param dividend
	 *  Number which is supposed to be divided by @c *this.
	 *
	 * @return
	 *	Quotient of @c dividend and @c *this.
	 */
	virtual Number *const getQuotientInverse(const Unsigned *const dividend) const;

	/**
	 * @}
	 */

	/**
	 * @brief
	 * 	Dummy virtual destructor.
	 */
	virtual ~Number(){}
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_NUMBER_H_ */
