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
	static Signed *fromBigEndianArray(const util::RuntimeArray<unsigned char> &array);

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
	static Signed *fromLittleEndianArray(const util::RuntimeArray<unsigned char> &array);

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
	static Signed *fromBinaryInString(const std::string &binaryInString);

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
	static Signed *fromOctalInString(const std::string &octalInString);

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
	static Signed *fromDecimalInString(const std::string &decimalInString);

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
	static Signed *fromHexadecimalInString(const std::string &hexadecimalInString);

	/**
	 * @brief
	 * 	Default virtual destructor.
	 */
	virtual ~Signed() noexcept = default;
	//======================================
	//-------------ARITHMETIC---------------
	//======================================

	virtual Number *copy() const override;

	//======================================
	//-------------ARITHMETIC---------------
	//======================================
	/**
	 * @{
	 */

	virtual Number *getSum(const Number *toAdd) const override;
	virtual Number *getSum(const Complex *toAdd) const override;
	virtual Number *getSum(const FloatingPoint *toAdd) const override;
	virtual Number *getSum(const Signed *toAdd) const override;
	virtual Number *getSum(const Unsigned *toAdd) const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Number *getProduct(const Number *toMultiply) const override;
	virtual Number *getProduct(const Complex *toMultiply) const override;
	virtual Number *getProduct(const FloatingPoint *toMultiply) const override;
	virtual Number *getProduct(const Signed *toMultiply) const override;
	virtual Number *getProduct(const Unsigned *toMultiply) const override;

	/**
	 * @}
	 */

	//======================================
	//---------------NUMBER-----------------
	//======================================

	virtual const bool isZero() const noexcept override;

	/**
	 * @{
	 */

	virtual const std::string getAsBinary() const noexcept override;
	virtual const std::string getAsOctal() const noexcept override;
	virtual const std::string getAsDecimal() const noexcept override;
	virtual const std::string getAsHexadecimal() const noexcept override;

	/**
	 * @}
	 */

	/**
	 * @{
	 *
	 */

	virtual Unsigned *getAsUnsignedInteger() const override;
	virtual Signed *getAsSignedInteger() const override;
	virtual FloatingPoint *getAsFloatingPoint() const override;
	virtual Complex *getAsComplex() const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Number *getNegation() const override;
	virtual Number *getInversion() const override;

	/**
	 * @}
	 */

	//======================================
	//-------------REALNUMBER---------------
	//======================================

	/**
	 * @{
	 */

	virtual const bool isNegative() const noexcept override;
	virtual const bool isPositive() const noexcept override;

	/**
	 * @}
	 */

	//======================================
	//---------INTEGERARITHMETIC------------
	//======================================

	/**
	 * @{
	 */

	virtual Integer *getIntegerQuotient(const Integer *toDivide) const override;
	virtual Integer *getRemainder(const Integer *toDivide) const override;
	virtual Integer *getIntegerQuotientInverse(const Integer *dividend) const override;
	virtual Integer *getInverseRemainder(const Integer *dividend) const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Integer *getIntegerQuotient(const Signed *toDivide) const override;
	virtual Integer *getRemainder(const Signed *toDivide) const override;
	virtual Integer *getIntegerQuotientInverse(const Signed *dividend) const override;
	virtual Integer *getInverseRemainder(const Signed *dividend) const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Integer *getIntegerQuotient(const Unsigned *toDivide) const override;
	virtual Integer *getRemainder(const Unsigned *toDivide) const override;
	virtual Integer *getIntegerQuotientInverse(const Unsigned *dividend) const override;
	virtual Integer *getInverseRemainder(const Unsigned *dividend) const override;

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
