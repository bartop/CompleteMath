/*
 * Number.h
 *
 *  Created on: 23 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_NUMBER_H_
#define NUMBERS_NUMBER_H_

#include <string>
#include "../coreInterfaces/Arithmetic.h"
#include "../coreInterfaces/Copyable.h"

namespace coma {
namespace numb {

class Complex;
class FloatingPoint;
class Signed;
class Unsigned;

/**
 * @brief
 *	Polymorphic interface for all numbers.
 */
class Number:
	public core::Arithmetic<Number>,
	public core::Copyable<Number>{
public:
	/**
	 * @brief
	 * 	Dummy virtual destructor.
	 */
	virtual ~Number(){}

	/**
	 * @brief
	 * 	Gets absolute value of @c *this.
	 *
	 * @return
	 * 	Absolute value of @c *this.
	 */
	virtual Number *const getAbsoluteValue() const = 0;

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
	virtual const std::string getAsBinary() const = 0;

	/**
	 * @brief
	 * 	Method used to get stored value.
	 *
	 * @return
	 * 	Octal representation of the stored value.
	 */
	virtual const std::string getAsOctal() const = 0;

	/**
	 * @brief
	 * 	Method used to get stored value.
	 *
	 * @return
	 *	Decimal representation of the stored value.
	 */
	virtual const std::string getAsDecimal() const = 0;

	/**
	 * @brief
	 * 	Method used to get stored value.
	 *
	 * @return
	 *	Hexadecimal representation of the stored value.
	 *
	 */
	virtual const std::string getAsHexadecimal() const = 0;

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

	using core::Addable<Number>::getSum;

	/**
	 * @brief
	 * 	Helper method, used to perform double dispatch.
	 *
	 * @param toAdd
	 * 	Number to add to @c *this.
	 *
	 * @return
	 * 	Sum of @a *toAdd and @c *this.
	 */
	virtual Number *const getSum(const Complex *const toAdd) const = 0;

	/**
	 * @brief
	 * 	Helper method, used to perform double dispatch.
	 *
	 * @param toAdd
	 * 	Number to add to @c *this.
	 *
	 * @return
	 * 	Sum of @a *toAdd and @c *this.
	 */
	virtual Number *const getSum(const FloatingPoint *const toAdd) const = 0;

	/**
	 * @brief
	 * 	Helper method, used to perform double dispatch.
	 *
	 * @param toAdd
	 * 	Number to add to @c *this.
	 *
	 * @return
	 * 	Sum of @a *toAdd and @c *this.
	 */
	virtual Number *const getSum(const Signed *const toAdd) const = 0;

	/**
	 * @brief
	 * 	Helper method, used to perform double dispatch.
	 *
	 * @param toAdd
	 * 	Number to add to @c *this.
	 *
	 * @return
	 * 	Sum of @a *toAdd and @c *this.
	 */
	virtual Number *const getSum(const Unsigned *const toAdd) const = 0;

	using core::Multiplyable<Number>::getProduct;

	/**
	 * @brief
	 * 	Helper method, used to perform double dispatch.
	 *
	 * @param toMultiply
	 * 	Number to multiply by @c *this.
	 *
	 * @return
	 * 	Product of @a *toMultiply and @c *this.
	 */
	virtual Number *const getProduct(const Complex *const toMultiply) const = 0;

	/**
	 * @brief
	 * 	Helper method, used to perform double dispatch.
	 *
	 * @param toMultiply
	 * 	Number to multiply by @c *this.
	 *
	 * @return
	 * 	Product of @a *toMultiply and @c *this.
	 */
	virtual Number *const getProduct(const FloatingPoint *const toMultiply) const = 0;

	/**
	 * @brief
	 * 	Helper method, used to perform double dispatch.
	 *
	 * @param toMultiply
	 * 	Number to multiply by @c *this.
	 *
	 * @return
	 * 	Product of @a *toMultiply and @c *this.
	 */
	virtual Number *const getProduct(const Signed *const toMultiply) const = 0;

	/**
	 * @brief
	 * 	Helper method, used to perform double dispatch.
	 *
	 * @param toMultiply
	 * 	Number to multiply by @c *this.
	 *
	 * @return
	 * 	Product of @a *toMultiply and @c *this.
	 */
	virtual Number *const getProduct(const Unsigned *const toMultiply) const = 0;

	virtual Number *const getDifference(const Number *const toSubtract) const override;

	virtual Number *const getQuotient(const Number *const toDivide) const override;
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_NUMBER_H_ */
