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
	static Pointer<const Signed> fromBigEndianArray(const tech::RuntimeArray<unsigned char> &array);

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
	static Pointer<const Signed> fromLittleEndianArray(const tech::RuntimeArray<unsigned char> &array);

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
	static Pointer<const Signed> fromBinaryInString(const std::string &binaryInString);

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
	static Pointer<const Signed> fromOctalInString(const std::string &octalInString);

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
	static Pointer<const Signed> fromDecimalInString(const std::string &decimalInString);

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
	static Pointer<const Signed> fromHexadecimalInString(const std::string &hexadecimalInString);

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
	explicit Signed(const tech::RuntimeArray<unsigned char> &array,
			const Endianess endianess = Endianess::Little);
	/**
	 * @brief
	 * 	Default virtual destructor.
	 */
	virtual ~Signed() noexcept = default;
	//======================================
	//-------------ARITHMETIC---------------
	//======================================

	virtual Pointer<const Number> copy() const override;

	//======================================
	//-------------ARITHMETIC---------------
	//======================================
	/**
	 * @{
	 */

	virtual Pointer<const Number> getSum(Pointer<const Number> toAdd) const override;
	virtual Pointer<const Number> getSum(Pointer<const Complex> toAdd) const override;
	virtual Pointer<const Number> getSum(Pointer<const FloatingPoint> toAdd) const override;
	virtual Pointer<const Number> getSum(Pointer<const Signed> toAdd) const override;
	virtual Pointer<const Number> getSum(Pointer<const Unsigned> toAdd) const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Pointer<const Number> getProduct(Pointer<const Number> toMultiply) const override;
	virtual Pointer<const Number> getProduct(Pointer<const Complex> toMultiply) const override;
	virtual Pointer<const Number> getProduct(Pointer<const FloatingPoint> toMultiply) const override;
	virtual Pointer<const Number> getProduct(Pointer<const Signed> toMultiply) const override;
	virtual Pointer<const Number> getProduct(Pointer<const Unsigned> toMultiply) const override;

	/**
	 * @}
	 */

	//======================================
	//---------------NUMBER-----------------
	//======================================

	virtual bool isZero() const noexcept override;

	/**
	 * @{
	 */

	virtual std::string getAsBinary() const noexcept override;
	virtual std::string getAsOctal() const noexcept override;
	virtual std::string getAsDecimal() const noexcept override;
	virtual std::string getAsHexadecimal() const noexcept override;

	/**
	 * @}
	 */

	/**
	 * @{
	 *
	 */

	virtual Pointer<const Unsigned> getAsUnsignedInteger() const override;
	virtual Pointer<const Signed> getAsSignedInteger() const override;
	virtual Pointer<const FloatingPoint> getAsFloatingPoint() const override;
	virtual Pointer<const Complex> getAsComplex() const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Pointer<const Number> getNegation() const override;
	virtual Pointer<const Number> getInversion() const override;

	/**
	 * @}
	 */

	//======================================
	//-------------REALNUMBER---------------
	//======================================

	/**
	 * @{
	 */

	virtual bool isNegative() const noexcept override;
	virtual bool isPositive() const noexcept override;

	/**
	 * @}
	 */

	//======================================
	//---------INTEGERARITHMETIC------------
	//======================================

	/**
	 * @{
	 */

	virtual Pointer<const Integer> getIntegerQuotient(Pointer<const Integer> toDivide) const override;
	virtual Pointer<const Integer> getRemainder(Pointer<const Integer> toDivide) const override;
	virtual Pointer<const Integer> getIntegerQuotientInverse(Pointer<const Integer> dividend) const override;
	virtual Pointer<const Integer> getInverseRemainder(Pointer<const Integer> dividend) const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Pointer<const Integer> getIntegerQuotient(Pointer<const Signed> toDivide) const override;
	virtual Pointer<const Integer> getRemainder(Pointer<const Signed> toDivide) const override;
	virtual Pointer<const Integer> getIntegerQuotientInverse(Pointer<const Signed> dividend) const override;
	virtual Pointer<const Integer> getInverseRemainder(Pointer<const Signed> dividend) const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Pointer<const Integer> getIntegerQuotient(Pointer<const Unsigned> toDivide) const override;
	virtual Pointer<const Integer> getRemainder(Pointer<const Unsigned> toDivide) const override;
	virtual Pointer<const Integer> getIntegerQuotientInverse(Pointer<const Unsigned> dividend) const override;
	virtual Pointer<const Integer> getInverseRemainder(Pointer<const Unsigned> dividend) const override;

	/**
	 * @}
	 */
private:
	Pointer<const Signed> sharedThis() const;
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_SIGNED_H_ */
