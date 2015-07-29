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

class Signed final: public Integer {
public:
	//======================================
	//---------------SIGNED-----------------
	//======================================

	/**
	 * @brief
	 * 	Creates new Signed object from big-endian byte array and returns it.
	 *
	 * @param array
	 *	Array of bytes containing long number.
	 *
	 * @return
	 * 	New Signed object containing value stored in array.
	 */
	static Signed *const fromBigEndianArray(const util::RuntimeArray<unsigned char> &array);

	/**
	 * @brief
	 * 	Creates new Signed object from little-endian byte array and returns it.
	 *
	 * @param array
	 *	Array of bytes containing long number.
	 *
	 * @return
	 * 	New Signed object containing value stored in array.
	 */
	static Signed *const fromLittleEndianArray(const util::RuntimeArray<unsigned char> &array);

	/**
	 * @brief
	 * 	Creates new Signed object from binary number stored in string.
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
	 *	New Signed object containing value stored in string.
	 */
	static Signed *const fromBinaryInString(const std::string &binaryInString);

	/**
	 * @brief
	 * 	Creates new Signed object from octal number stored in string.
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
	 *	New Signed object containing value stored in string.
	 */
	static Signed *const fromOctalInString(const std::string &octalInString);

	/**
	 * @brief
	 * 	Creates new Signed object from decimal number stored in string.
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
	 *	New Signed object containing value stored in string.
	 */
	static Signed *const fromDecimalInString(const std::string &decimalInString);

	/**
	 * @brief
	 * 	Creates new Signed object from hexadecimal number stored in string.
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
	 *	New Signed object containing value stored in string.
	 */
	static Signed *const fromHexadecimalInString(const std::string &hexadecimalInString);

	/**
	 * @brief
	 * 	Dummy virtual destructor.
	 */
	virtual ~Signed();
	//======================================
	//-------------ARITHMETIC---------------
	//======================================

	virtual Number *const copy() const override;

	//======================================
	//-------------ARITHMETIC---------------
	//======================================
	/**
	 * @{
	 */

	virtual Number *const getSum(const Number *const toAdd) const override;
	virtual Number *const getSum(const Complex *const toAdd) const override;
	virtual Number *const getSum(const FloatingPoint *const toAdd) const override;
	virtual Number *const getSum(const Signed *const toAdd) const override;
	virtual Number *const getSum(const Unsigned *const toAdd) const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Number *const getProduct(const Number *const toMultiply) const override;
	virtual Number *const getProduct(const Complex *const toMultiply) const override;
	virtual Number *const getProduct(const FloatingPoint *const toMultiply) const override;
	virtual Number *const getProduct(const Signed *const toMultiply) const override;
	virtual Number *const getProduct(const Unsigned *const toMultiply) const override;

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

private:
	/**
	 * @brief
	 * 	Constructs Signed from array of unsigned chars.
	 *
	 * @details
	 * 	The negative numbers are stored using 2-complement.
	 *
	 * @param array
	 *	Array of bytes containing long number.
	 *
	 * @param endianess
	 * 	Enum telling if the number in array is stored in big- or little-endian manner.
	 */
	explicit Signed(const util::RuntimeArray<unsigned char> &array,
			const Endianess endianess = Endianess::Little);
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_SIGNED_H_ */
