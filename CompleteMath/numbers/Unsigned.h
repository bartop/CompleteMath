/*
 * Unsigned.h
 *
 *  Created on: 24 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_UNSIGNED_H_
#define NUMBERS_UNSIGNED_H_

#include "Integer.h"
#include <type_traits>

namespace coma {
namespace numb {

/**
 * @brief
 *  Class representing positive unsigned integer.
 */
class Unsigned final: public Integer{
public:
	//======================================
	//--------------UNSIGNED----------------
	//======================================

	/**
	 * @brief
	 * 	Creates new Unsigned object from big-endian byte array and returns it.
	 *
	 * @param array
	 *	Array of bytes containing long number.
	 *
	 * @return
	 * 	New Unsigned object containing value stored in array.
	 */
	static Unsigned *fromBigEndianArray(const util::RuntimeArray<unsigned char> &array);

	/**
	 * @brief
	 * 	Creates new Unsigned object from little-endian byte array and returns it.
	 *
	 * @param array
	 *	Array of bytes containing long number.
	 *
	 * @return
	 * 	New Unsigned object containing value stored in array.
	 */
	static Unsigned *fromLittleEndianArray(const util::RuntimeArray<unsigned char> &array);

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
	static Unsigned *fromBinaryInString(const std::string &binaryInString);

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
	static Unsigned *fromOctalInString(const std::string &octalInString);

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
	static Unsigned *fromDecimalInString(const std::string &decimalInString);

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
	static Unsigned *fromHexadecimalInString(const std::string &hexadecimalInString);

	/**
	 * @brief
	 * 	Default virtual destructor.
	 */
	virtual ~Unsigned() noexcept = default;

	//======================================
	//--------------COPYABLE----------------
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
	 * 	Constructs Unsigned from array of unsigned chars.
	 *
	 * @param array
	 *	Array of bytes containing long number.

	 *
	 * @param endianess
	 * 	Enum telling if the number in array is stored in big- or little-endian manner.
	 */
	explicit Unsigned(const util::RuntimeArray<unsigned char> &array,
			const Endianess endianess = Endianess::Little);
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_UNSIGNED_H_ */
