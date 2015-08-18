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
#include "../coreInterfaces/TriviallyComparable.h"
#include "../Technical/MemoryPoolObject.h"
#include "../defines.h"

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
	public core::Copyable<Number>,
	public core::TriviallyComparable<Number>,
	public tech::MemoryPoolObject{
public:
	/**
	 * @brief
	 * 	Default virtual destructor.
	 */
	virtual ~Number() noexcept = default;

	/**
	 * @brief
	 * 	Gets absolute value of @c *this.
	 *
	 * @return
	 * 	Absolute value of @c *this.
	 */
	virtual Number *getAbsoluteValue() const = 0;

	/**
	 * @brief
	 * 	Checks if stored value is equal to zero.
	 *
	 * @return
	 * 	True if stored value equals 0. Else returns false.
	 */
	virtual const bool isZero() const noexcept = 0;

	virtual const bool isEqual(const Number *toCompare) const override;

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
	virtual Unsigned *getAsUnsignedInteger() const = 0;

	/**
	 * @brief
	 *	Returns @c *this as Signed object.
	 *
	 * @copydetails getAsUnsignedInteger
	 *
	 * @return
	 * 	Signed representation of @c *this object.
	 */
	virtual Signed *getAsSignedInteger() const = 0;

	/**
	 * @brief
	 *	Returns @c *this as FloatingPoint object.
	 *
	 * @copydetails getAsUnsignedInteger
	 *
	 * @return
	 * 	FloatingPoint representation of @c *this object.
	 */
	virtual FloatingPoint *getAsFloatingPoint() const = 0;

	/**
	 * @brief
	 *	Returns @c *this as Complex object.
	 *
	 * @copydetails getAsUnsignedInteger
	 *
	 * @return
	 * 	Complex representation of @c *this object.
	 */
	virtual Complex *getAsComplex() const = 0;

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
	virtual Number *getSum(const Complex *toAdd) const = 0;

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
	virtual Number *getSum(const FloatingPoint *toAdd) const = 0;

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
	virtual Number *getSum(const Signed *toAdd) const = 0;

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
	virtual Number *getSum(const Unsigned *toAdd) const = 0;

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
	virtual Number *getProduct(const Complex *toMultiply) const = 0;

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
	virtual Number *getProduct(const FloatingPoint *toMultiply) const = 0;

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
	virtual Number *getProduct(const Signed *toMultiply) const = 0;

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
	virtual Number *getProduct(const Unsigned *toMultiply) const = 0;

	virtual Number *getDifference(const Number *toSubtract) const override;

	virtual Number *getQuotient(const Number *toDivide) const override;

	/**
	 * @brief
	 * 	Returns zero as pointer to Unsigned object.
	 *
	 * @return
	 * 	Pointer to Unsigned storing zero.
	 */
	static const Unsigned *ZERO() noexcept;

	/**
	 * @brief
	 * 	Returns one as pointer to Unsigned object.
	 *
	 * @return
	 * 	Pointer to Unsigned storing one.
	 */
	static const Unsigned *ONE() noexcept;

};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_NUMBER_H_ */
