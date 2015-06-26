/*
 * Unsigned.h
 *
 *  Created on: 24 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_UNSIGNED_H_
#define NUMBERS_UNSIGNED_H_

#include "Integer.h"

namespace cm {
namespace numb {
/**
 * @brief
 *  Class representing unsigned positive integer.
 */
class Unsigned: public Integer {
private:
	static const unsigned char *const arrayFromHexadecimal(const NumberInString &hex);

	static const unsigned long long sizeFromHexadecimal(const NumberInString &hex);

public:
	/**
	 * @brief
	 * 	Constructs Unsigned from hexadecimal number stored in string.
	 *
	 * @details
	 * 	This constructor does NOT check if there is a valid integer value stored in string due to O(2^n) complexity of this
	 * 	task. \n For all notations check factory functions:
	 * 	- fromBinaryInString()
	 * 	- fromOctalInString()
	 * 	- fromDecimalInString()
	 * 	- fromHexadecimalInString()
	 *
	 * @param hexadecimalInString
	 * 	Hexadecimal integer value stored in string.
	 */
	explicit Unsigned(const NumberInString &hexadecimalInString);

	/**
	 * @brief
	 * 	Constructs Unsigned from array of unsigned chars.
	 *
	 * @param numbersArray
	 *	Array of bytes containing long number.
	 *
	 * @param arrayLenght
	 * 	Length of the given array.
	 *
	 * @param endianess
	 * 	Enum telling if the number in array is stored in big- or little-endian manner.
	 */
	explicit Unsigned(const unsigned char *const numbersArray = nullptr,
			const unsigned long long arrayLenght = 0,
			const Endianess endianess = Endianess::Little);

	/**
	 * @brief
	 * 	Creates new Unsigned object from big-endian byte array and returns it.
	 *
	 * @param numbersArray
	 *	Array of bytes containing long number.
	 *
	 * @param arrayLenght
	 * 	Length of the given array.
	 *
	 * @return
	 * 	New Unsigned object containing value stored in array.
	 */
	static Unsigned *const fromBigEndianArray(const unsigned char *const numbersArray = nullptr,
			const unsigned long long arrayLenght = 0);

	/**
	 * @brief
	 * 	Creates new Unsigned object from little-endian byte array and returns it.
	 *
	 * @param numbersArray
	 *	Array of bytes containing long number.
	 *
	 * @param arrayLenght
	 * 	Length of the given array.
	 *
	 * @return
	 * 	New Unsigned object containing value stored in array.
	 */
	static Unsigned *const fromLittleEndianArray(const unsigned char *const numbersArray = nullptr,
			const unsigned long long arrayLenght = 0);

	/**
	 * @brief
	 * 	Creates new Unsigned object from binary number stored in string.
	 *
	 * @param binaryInString
	 * 	Binary number stored in string.
	 *
	 * @return
	 *	New Unsigned object containing value stored in string.
	 */
	static Unsigned *const fromBinaryInString(const NumberInString &binaryInString);

	/**
	 * @brief
	 * 	Creates new Unsigned object from octal number stored in string.
	 *
	 * @param octalInString
	 *	Octal number stored in string.
	 *
	 * @return
	 *	New Unsigned object containing value stored in string.
	 */
	static Unsigned *const fromOctalInString(const NumberInString &octalInString);

	/**
	 * @brief
	 * 	Creates new Unsigned object from decimal number stored in string.
	 *
	 * @param decimalInString
	 * 	Decimal number stored in string.
	 *
	 * @return
	 *	New Unsigned object containing value stored in string.
	 */
	static Unsigned *const fromDecimalInString(const NumberInString &decimalInString);

	/**
	 * @brief
	 * 	Creates new Unsigned object from hexadecimal number stored in string.
	 *
	 * @param hexadecimalInString
	 * 	Hexadecimal number stored in string.
	 *
	 * @return
	 *	New Unsigned object containing value stored in string.
	 */
	static Unsigned *const fromHexadecimalInString(const NumberInString &hexadecimalInString);

	//======================================
	//-------------COMPARABLE---------------
	//======================================
	/**
	 * @brief
	 * 	Method used to compare objects.
	 *
	 * @param toCompare
	 *	Pointer to object with which @c *this is supposed to be compared.
	 *
	 * @return
	 * 	#CompareResult adequate to result of the comparison.
	 */
	virtual const CompareResult compare(const RealNumber *const toCompare) const override;

	//======================================
	//---------------NUMBER-----------------
	//======================================

	/**
	 * @brief
	 * 	Checks if stored value is equal to zero.
	 *
	 * @return
	 * 	True if stored value equals 0. Else returns false.
	 */
	virtual const bool isZero() const override;

	/**
	 * @{
	 */

	/**
	 * @brief
	 * 	Method to get opposite value.
	 *
	 * @return
	 * 	Negation of the number stored in @c *this.
	 */
	virtual Number *const getNegation() const override;

	/**
	 * @brief
	 * 	Method to get inverse value.
	 *
	 * @return
	 * 	Inverse of the value stored in @c *this.
	 */
	virtual Number *const getInversion() const override;


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
	virtual Number *const getSum(const Number *const toAdd) const override;

	/**
	 * @brief
	 * 	Method used to subtract numbers.
	 *
	 * @details
	 *	By default it is defined as @c this->(toSubtract->negate()), which may not be the most efficient but is
	 *	the most universal way of defining subtraction.
	 *
	 * @param toSubtract
	 *	Number that is supposed to be subtracted from @c *this.
	 *
	 * @return
	 * 	Difference between @c *this and @c toSubtract.
	 */
	virtual Number *const getDifference(const Number *const toSubtract) const override;

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
	virtual Number *const getProduct(const Number *const toMultiply) const override;

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
	 */
	virtual Number *const getQuotient(const Number *const toDivide) const override;

	/**
	 * @}
	 */

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
	virtual const NumberInString getAsBinary() const override;

	/**
	 * @brief
	 * 	Method used to get stored value.
	 *
	 * @return
	 * 	Octal representation of the stored value.
	 */
	virtual const NumberInString getAsOctal() const override;

	/**
	 * @brief
	 * 	Method used to get stored value.
	 *
	 * @return
	 *	Decimal representation of the stored value.
	 */
	virtual const NumberInString getAsDecimal() const override;

	/**
	 * @brief
	 * 	Method used to get stored value.
	 *
	 * @return
	 *	Hexadecimal representation of the stored value.
	 */
	virtual const NumberInString getAsHexadecimal() const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	/**
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
	virtual Unsigned *const getAsUnsignedInteger() const override;

	/**
	 * @brief
	 *	Returns @c *this as Signed object.
	 *
	 * @copydetails getAsUnsignedInteger
	 *
	 * @return
	 * 	Signed representation of @c *this object.
	 */
	virtual Signed *const getAsSignedInteger() const override;

	/**
	 * @brief
	 *	Returns @c *this as FloatingPoint object.
	 *
	 * @copydetails getAsUnsignedInteger
	 *
	 * @return
	 * 	FloatingPoint representation of @c *this object.
	 */
	virtual FloatingPoint *const getAsFloatingPoint() const override;

	/**
	 * @brief
	 *	Returns @c *this as Complex object.
	 *
	 * @copydetails getAsUnsignedInteger
	 *
	 * @return
	 * 	Complex representation of @c *this object.
	 *
	 */
	virtual Complex *const getAsComplex() const override;

	/**
	 * @}
	 */

	//======================================
	//-------------REALNUMBER---------------
	//======================================

	/**
	 * @{
	 */

	/**
	 * @brief
	 * 	Method to check if stored value is positive or negative.
	 *
	 * @details
	 * 	0 (zero) is NOT treated as neither positive nor negative value.
	 *
	 * @return
	 * 	True if stored value is negative.
	 * 	False if stored value is non-negative.
	 */
	virtual const bool isNegative() const override;

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
	virtual const bool isPositive() const override;

	/**
	 * @}
	 */

	//======================================
	//---------------INTEGER----------------
	//======================================

	/**
	 * @{
	 */

	/**
	 * @brief
	 * 	Function to perform integer division.
	 *
	 * @param toDivide
	 * 	Integer by which @c *this is supposed to be divided by.
	 *
	 * @return
	 * 	Quotient of @c *this and @c toDivide.
	 */
	virtual Integer *const getIntegerQuotient(const Integer *const toDivide) const override;

	/**
	 * @brief
	 * 	Function to perform mod operation.
	 *
	 * @param toDivide
	 * 	Integer by which @c *this is supposed to be divided by.
	 *
	 * @return
	 * 	Remainder of @c *this and @c toDivide division.
	 */
	virtual Integer *const getRemainder(const Integer *const toDivide) const override;

	/**
	 * @}
	 */

	virtual ~Unsigned();
};

} /* namespace numb */
} /* namespace cm */

#endif /* NUMBERS_UNSIGNED_H_ */
