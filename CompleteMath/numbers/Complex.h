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
	static Pointer< Complex> fromRealAndImaginary(const Pointer< RealNumber> real, const Pointer< RealNumber> imaginary);

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
	Complex(const Pointer< RealNumber> real, const Pointer< RealNumber> imaginary);

	/**
	 * @brief
	 * 	Virtual destructor which frees resources.
	 */
	virtual ~Complex() noexcept;

	//======================================
	//--------------COPYABLE----------------
	//======================================

	virtual Pointer< Number> copy() const override;

	//======================================
	//-------------ARITHMETIC---------------
	//======================================
	/**
	 * @{
	 */

	virtual Pointer< Number> getSum(Pointer< Number> toAdd) const override;
	virtual Pointer< Number> getSum(Pointer< Complex> toAdd) const override;
	virtual Pointer< Number> getSum(Pointer< FloatingPoint> toAdd) const override;
	virtual Pointer< Number> getSum(Pointer< Signed> toAdd) const override;
	virtual Pointer< Number> getSum(Pointer< Unsigned> toAdd) const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Pointer< Number> getProduct(Pointer< Number> toMultiply) const override;
	virtual Pointer< Number> getProduct(Pointer< Complex> toMultiply) const override;
	virtual Pointer< Number> getProduct(Pointer< FloatingPoint> toMultiply) const override;
	virtual Pointer< Number> getProduct(Pointer< Signed> toMultiply) const override;
	virtual Pointer< Number> getProduct(Pointer< Unsigned> toMultiply) const override;

	/**
	 * @}
	 */

	//======================================
	//---------------NUMBER-----------------
	//======================================

	virtual Pointer< Number> getAbsoluteValue() const override;
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

	virtual Pointer< Unsigned> getAsUnsignedInteger() const override;
	virtual Pointer< Signed> getAsSignedInteger() const override;
	virtual Pointer< FloatingPoint> getAsFloatingPoint() const override;
	virtual Pointer< Complex> getAsComplex() const override;

	/**
	 * @}
	 */

	/**
	 * @{
	 */

	virtual Pointer< Number> getNegation() const override;
	virtual Pointer< Number> getInversion() const override;

	/**
	 * @}
	 */

private:
	Pointer< RealNumber> m_real = nullptr;
	Pointer< RealNumber> m_imaginary = nullptr;


	Pointer< Complex> sharedThis() const;
};

} /* namespace numb */
} /* namespace coma */

#endif /* NUMBERS_COMPLEX_H_ */
