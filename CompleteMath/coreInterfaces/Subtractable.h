/*
 * Subtractable.h
 *
 *  Created on: 25 lip 2015
 *      Author: Bartosz Miera
 */

#ifndef COREINTERFACES_SUBTRACTABLE_H_
#define COREINTERFACES_SUBTRACTABLE_H_

#include "Addable.h"
#include <type_traits>
#include <memory>

namespace coma {
namespace core {

/**
 * @brief
 * 	Generic interface for subtracting and adding.
 */
template<class T, class U = T>
class Subtractable: public Addable<T, U> {
public:
	typedef T return_type;
	typedef U argument_type;

	/**
	 * @brief
	 * 	Default virtual destructor.
	 */
	virtual ~Subtractable() {}

	/**
	 * @brief
	 * 	Creates object negation and returns it.
	 *
	 * @return
	 * 	Negation of @c *this.
	 */
	virtual return_type *getNegation() const = 0;

	/**
	 * @brief
	 *	Subtracts two numbers.
	 *
	 * @param toSubtract
	 * 	Object to be subtracted form @c *this.
	 *
	 * @return
	 * 	Difference of @c *this and @a *toSubtract.
	 */
	virtual return_type *getDifference(const argument_type *toSubtract) const = 0;
};

} /* namespace core */
} /* namespace coma */

#endif /* COREINTERFACES_SUBTRACTABLE_H_ */
