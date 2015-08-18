/*
 * Addable.h
 *
 *  Created on: 25 lip 2015
 *      Author: Bartosz Miera
 */

#ifndef COREINTERFACES_ADDABLE_H_
#define COREINTERFACES_ADDABLE_H_

namespace coma {
namespace core {

/**
 * @brief
 * 	Generic interface for adding objects.
 */
template<class T, class U = T>
class Addable {
public:
	using argument_type = T;
	using return_type = U;

	/**
	 * @brief
	 * 	Adds two objects.
	 *
	 * @param toAdd
	 * 	Pointer to object to be added to @c this.
	 *
	 * @return
	 * 	Pointer to sum of @c *this and @a *toAdd.
	 */
	virtual return_type *getSum(const argument_type *toAdd) const = 0;

	/**
	 * @brief
	 * 	Virtual dummy constructor.
	 */
	virtual ~Addable(){}

	/**
	 * @brief
	 * 	Return neutral element of addition. For example zero for numbers.
	 *
	 * @return
	 * 	Neutral element of addition.
	 */
	static constexpr const argument_type *additionNeutralElement(){ return NEUTRAL_ELEMENT; }

private:
	/**
	 * @brief
	 * 	Neutral element of addition.
	 */
	static const argument_type *NEUTRAL_ELEMENT;
};

} /* namespace core */
} /* namespace coma */

#endif /* COREINTERFACES_ADDABLE_H_ */
