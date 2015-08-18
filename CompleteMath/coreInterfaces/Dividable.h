/*
 * Dividable.h
 *
 *  Created on: 26 lip 2015
 *      Author: Bartosz Miera
 */

#ifndef COREINTERFACES_DIVIDABLE_H_
#define COREINTERFACES_DIVIDABLE_H_

#include "Multiplyable.h"

namespace coma {
namespace core {

/**
 * @brief
 * 	Generic interface for division and multiplication.
 */
template<class T, class U = T>
class Dividable: public Multiplyable<T, U> {
public:
	typedef T return_type;
	typedef U argument_type;

	/**
	 * @brief
	 * 	Creates object inversion and returns it.
	 *
	 * @return
	 * 	Inversion of @c *this.
	 */
	virtual return_type *getInversion() const = 0;

	/**
	 * @brief
	 * 	Method for dividing objects.
	 *
	 * @param toDivide
	 * 	Object by which @c *this is supposed to be divided by.
	 *
	 * @return
	 * 	Quotient of @c *this and @a toDivide.
	 */
	virtual return_type *getQuotient(const argument_type *toDivide) const = 0;

	/**
	 * @brief
	 * 	Default virtual destructor.
	 */
	virtual ~Dividable() {}
};

} /* namespace core */
} /* namespace coma */

#endif /* COREINTERFACES_DIVIDABLE_H_ */
