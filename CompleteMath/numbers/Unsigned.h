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
	static Pointer<Unsigned> fromBigEndianArray(const tech::RuntimeArray<unsigned char> &array);

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
	static Pointer<Unsigned> fromLittleEndianArray(const tech::RuntimeArray<unsigned char> &array);

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
	static Pointer<Unsigned> fromBinaryInString(const std::string &binaryInString);

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
	static Pointer<Unsigned> fromOctalInString(const std::string &octalInString);

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
	static Pointer<Unsigned> fromDecimalInString(const std::string &decimalInString);

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
	static Pointer<Unsigned> fromHexadecimalInString(const std::string &hexadecimalInString);

	/**
	 * @brief
	 * 	Constructs Unsigned from array of unsigned chars.
	 *
	 * @details
	 * 	Constructor should NOT be used at all! It is public due to problems with cpp standard library.
	 * 	The constructor will work just fine but it lacks some of useful features like caching.
	 *
	 * @param array
	 *	Array of bytes containing long number.
	 *
	 * @param endianess
	 * 	Enum telling if the number in array is stored in big- or little-endian manner.
	 */
	explicit Unsigned(const tech::RuntimeArray<unsigned char> &array,
			const Endianess endianess = Endianess::Little);

	/**
	 * @brief
	 * 	Default virtual destructor.
	 */
	virtual ~Unsigned() noexcept = default;

	//======================================
	//--------------COPYABLE----------------
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

	virtual std::string getAsBinary() const override;
	virtual std::string getAsOctal() const override;
	virtual std::string getAsDecimal() const override;
	virtual std::string getAsHexadecimal() const override;

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
	Pointer<Unsigned> sharedThis() const;
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_UNSIGNED_H_ */
