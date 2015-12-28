/*
 * Complex.h
 *
 *  Created on: 27 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_COMPLEX_H_
#define NUMBERS_COMPLEX_H_

#include "Number.h"

namespace coma {
namespace numb {

class RealNumber;

/**
 * @brief
 * 	Concrete class representing complex number.
 */
class Complex final:
		public Number {
public:
	//======================================
	//--------------COMPLEX-----------------
	//======================================
	/**
	 * @brief
	 * 	Factory function creating Complex from real and imaginary part.
	 *
	 * @param real
	 * 	Real part of created Complex.
	 *
	 * @param imaginary
	 * 	Imaginary part of created Complex.
	 *
	 * @return
	 * 	Shared pointer to new Complex with given real and imaginary part.
	 */
	static Pointer<Complex> fromRealAndImaginary(const Pointer<RealNumber> real,
			const Pointer<RealNumber> imaginary);

	/**
	 * @brief
	 * 	Factory function creating Complex from string.
	 *
	 * @param complex
	 * 	String containing complex number in given pattern:
	 * 	real_part + imaginary_part * i
	 * 	Note that spaces placement is not meaningless.
	 *
	 * @return
	 * 	Shared pointer to new Complex containing value given in string.
	 */
	static Pointer<Complex> fromBinaryInString(const String &complex);

	/**
	 * @brief
	 * 	Factory function creating Complex from string.
	 *
	 * @param complex
	 * 	String containing complex number in given pattern:
	 * 	real_part + imaginary_part * i
	 * 	Note that spaces placement is not meaningless.
	 *
	 * @return
	 * 	Shared pointer to new Complex containing value given in string.
	 */
	static Pointer<Complex> fromOctalInString(const String &complex);

	/**
	 * @brief
	 * 	Factory function creating Complex from string.
	 *
	 * @param complex
	 * 	String containing complex number in given pattern:
	 * 	real_part + imaginary_part * i
	 * 	Note that spaces placement is not meaningless.
	 *
	 * @return
	 * 	Shared pointer to new Complex containing value given in string.
	 */
	static Pointer<Complex> fromDecimalInString(const String &complex);

	/**
	 * @brief
	 * 	Factory function creating Complex from string.
	 *
	 * @param complex
	 * 	String containing complex number in given pattern:
	 * 	real_part + imaginary_part * i
	 * 	Note that spaces placement is not meaningless.
	 *
	 * @return
	 * 	Shared pointer to new Complex containing value given in string.
	 */
	static Pointer<Complex> fromHexadecimalInString(const String &complex);

	/**
	 * @brief
	 * 	Constructor copying @a real as real part and @a imaginary as imaginary part.
	 *
	 * @param real
	 * 	Real part of created Complex number.
	 *
	 * @param imaginary
	 * 	Imaginary part of created Complex number.
	 */
	Complex(const Pointer<RealNumber> real, const Pointer<RealNumber> imaginary);

	/**
	 * @brief
	 * 	Virtual destructor which frees resources.
	 */
	virtual ~Complex() noexcept;

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

	virtual Pointer<Number> getAbsoluteValue() const override;
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

private:
	/**
	 * @brief
	 * 	Real part of complex number.
	 */
	Pointer<RealNumber> m_real = nullptr;

	/**
	 * @brief
	 * 	Imaginary part of complex number.
	 */
	Pointer<RealNumber> m_imaginary = nullptr;

	/**
	 * @brief
	 * 	Getter of shared pointer to *this.
	 *
	 * @return
	 * 	Shared pointer to *this.
	 */
	Pointer<Complex> sharedThis() const;
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_COMPLEX_H_ */
