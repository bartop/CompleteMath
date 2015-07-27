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
	typedef T argument_type;
	typedef U return_type;

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
	virtual return_type *const getSum(const argument_type *const toAdd) const = 0;

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
	static constexpr const argument_type *const additionNeutralElement(){ return NEUTRAL_ELEMENT; }

private:
	/**
	 * @brief
	 * 	Neutral element of addition.
	 */
	static const argument_type *const NEUTRAL_ELEMENT;
};

} /* namespace core */
} /* namespace coma */

#endif /* COREINTERFACES_ADDABLE_H_ */
