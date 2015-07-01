/*
 * Unsigned.h
 *
 *  Created on: 24 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_UNSIGNED_H_
#define NUMBERS_UNSIGNED_H_

#include "Integer.h"

namespace coma {
namespace numb {
/**
 * @brief
 *  Class representing positive unsigned integer.
 */
class Unsigned: public Integer {
public:
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
	 * @details
	 * For all notations check factory functions:
	 * 	- fromBinaryInString()
	 * 	- fromOctalInString()
	 * 	- fromDecimalInString()
	 * 	- fromHexadecimalInString()
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
	 * @details
	 * For all notations check factory functions:
	 * 	- fromBinaryInString()
	 * 	- fromOctalInString()
	 * 	- fromDecimalInString()
	 * 	- fromHexadecimalInString()
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
	 * @details
	 * For all notations check factory functions:
	 * 	- fromBinaryInString()
	 * 	- fromOctalInString()
	 * 	- fromDecimalInString()
	 * 	- fromHexadecimalInString()
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
	 * @details
	 * For all notations check factory functions:
	 * 	- fromBinaryInString()
	 * 	- fromOctalInString()
	 * 	- fromDecimalInString()
	 * 	- fromHexadecimalInString()
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

	virtual ~Unsigned();
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_UNSIGNED_H_ */
