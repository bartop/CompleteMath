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
	 * 	New Complex with given real and imaginary part.
	 */
	static Pointer<const Complex> fromRealAndImaginary(const Pointer<const RealNumber> real, const Pointer<const RealNumber> imaginary);

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
	Complex(const Pointer<const RealNumber> real, const Pointer<const RealNumber> imaginary);

	/**
	 * @brief
	 * 	Virtual destructor which frees resources.
	 */
	virtual ~Complex() noexcept;

	//======================================
	//--------------COPYABLE----------------
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

	virtual Pointer<const Number> getAbsoluteValue() const override;
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

private:
	Pointer<const RealNumber> m_real = nullptr;
	Pointer<const RealNumber> m_imaginary = nullptr;


	Pointer<const Complex> sharedThis() const;
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_COMPLEX_H_ */
