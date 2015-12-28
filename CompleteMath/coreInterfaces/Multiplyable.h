/*
 * Multiplyable.h
 *
 *  Created on: 26 lip 2015
 *      Author: Bartosz Miera
 */

#ifndef COREINTERFACES_MULTIPLYABLE_H_
#define COREINTERFACES_MULTIPLYABLE_H_

namespace coma {
namespace core {

/**
 * @brief
 * 	Generic interface for multiplying.
 */
template<class T, class U = T>
class Multiplyable {
public:
	using argument_type = T;
	using return_type = U;

	/**
	 * @brief
	 * 	Default virtual destructor.
	 */
	virtual ~Multiplyable() noexcept = default;

	/**
	 * @brief
	 * 	Method used to multiply objects.
	 *
	 * @param toMultiply
	 *	Object that is supposed to be multiplied by @c *this.
	 *
	 * @return
	 * 	Product of @c *this and @a toMultiply.
	 */
	virtual return_type getProduct(argument_type toMultiply) const = 0;

	/**
	 * @brief
	 * 	Method to get neutral element of multiplication. For example one for numbers.
	 *
	 * @return
	 * 	Neutral element of multiplication.
	 */
	static constexpr argument_type multiplicationNeutralElement()noexcept{ return MULTIPLICATION_NEUTRAL_ELEMENT; }

private:
	/**
	 * @brief
	 * 	Neutral element of multiplication.
	 */
	static argument_type MULTIPLICATION_NEUTRAL_ELEMENT;
};

} /* namespace core */
} /* namespace coma */

#endif /* COREINTERFACES_MULTIPLYABLE_H_ */
