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

/**
 * @brief
 * 	Concrete class representing signed integer.
 */
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
	static Pointer<Signed> fromBigEndianArray(const tech::RuntimeArray<unsigned char> &array);

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
	static Pointer<Signed> fromLittleEndianArray(const tech::RuntimeArray<unsigned char> &array);

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
	static Pointer<Signed> fromBinaryInString(const std::string &binaryInString);

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
	static Pointer<Signed> fromOctalInString(const std::string &octalInString);

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
	static Pointer<Signed> fromDecimalInString(const std::string &decimalInString);

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
	static Pointer<Signed> fromHexadecimalInString(const std::string &hexadecimalInString);

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

	virtual Pointer<Number> copy() const override;

	//======================================
	//-------------ARITHMETIC---------------
	//======================================
	/**
	 * @{
	 */

	virtual Pointer<Number> getSum(Pointer<Number> toAdd) const override;
	virtual Pointer<Number> getSum(Pointer<Complex> toAdd) const override;
	virtual Pointer<Number> getSum(Pointer<FloatingPoint> toAdd) const override;
	virtual Pointer<Number> getSum(Pointer<Signed> toAdd) const override;
	virtual Pointer<Number> getSum(Pointer<Unsigned> toAdd) const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Pointer<Number> getProduct(Pointer<Number> toMultiply) const override;
	virtual Pointer<Number> getProduct(Pointer<Complex> toMultiply) const override;
	virtual Pointer<Number> getProduct(Pointer<FloatingPoint> toMultiply) const override;
	virtual Pointer<Number> getProduct(Pointer<Signed> toMultiply) const override;
	virtual Pointer<Number> getProduct(Pointer<Unsigned> toMultiply) const override;

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

	virtual Pointer<Unsigned> getAsUnsignedInteger() const override;
	virtual Pointer<Signed> getAsSignedInteger() const override;
	virtual Pointer<FloatingPoint> getAsFloatingPoint() const override;
	virtual Pointer<Complex> getAsComplex() const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Pointer<Number> getNegation() const override;
	virtual Pointer<Number> getInversion() const override;

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

	virtual Pointer<Integer> getIntegerQuotient(Pointer<Integer> toDivide) const override;
	virtual Pointer<Integer> getRemainder(Pointer<Integer> toDivide) const override;
	virtual Pointer<Integer> getIntegerQuotientInverse(Pointer<Integer> dividend) const override;
	virtual Pointer<Integer> getInverseRemainder(Pointer<Integer> dividend) const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Pointer<Integer> getIntegerQuotient(Pointer<Signed> toDivide) const override;
	virtual Pointer<Integer> getRemainder(Pointer<Signed> toDivide) const override;
	virtual Pointer<Integer> getIntegerQuotientInverse(Pointer<Signed> dividend) const override;
	virtual Pointer<Integer> getInverseRemainder(Pointer<Signed> dividend) const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Pointer<Integer> getIntegerQuotient(Pointer<Unsigned> toDivide) const override;
	virtual Pointer<Integer> getRemainder(Pointer<Unsigned> toDivide) const override;
	virtual Pointer<Integer> getIntegerQuotientInverse(Pointer<Unsigned> dividend) const override;
	virtual Pointer<Integer> getInverseRemainder(Pointer<Unsigned> dividend) const override;

	/**
	 * @}
	 */
private:
	Pointer<Signed> sharedThis() const;
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_SIGNED_H_ */
