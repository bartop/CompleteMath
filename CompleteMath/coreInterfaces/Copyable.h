/*
 * Copyable.h
 *
 *  Created on: 25 lip 2015
 *      Author: Bartosz Miera
 */

#ifndef COREINTERFACES_COPYABLE_H_
#define COREINTERFACES_COPYABLE_H_

namespace coma {
namespace core {

/**
 * @brief
 * 	Generic interface for copying classes.
 */
template<class T>
class Copyable {
public:
	/**
	 * @brief
	 * 	Function to copy @c this object.
	 *
	 * @return
	 * 	Pointer to copy of @c *this.
	 */
	virtual T *copy() const = 0;

	/**
	 * @brief
	 * 	Default virtual destructor.
	 */
	virtual ~Copyable() {}
};

} /* namespace core */
} /* namespace coma */

#endif /* COREINTERFACES_COPYABLE_H_ */
