/*
 * TriviallyComparable.h
 *
 *  Created on: 28 lip 2015
 *      Author: Bartosz Miera
 */

#ifndef COREINTERFACES_TRIVIALLYCOMPARABLE_H_
#define COREINTERFACES_TRIVIALLYCOMPARABLE_H_

namespace coma {
namespace core {

template<class T>
class TriviallyComparable{
public:
	/**
	 * @brief
	 * 	Default virtual destructor.
	 */
	virtual ~TriviallyComparable(){}

	/**
	 * @brief
	 * 	Checks of @c *this and @a toCompare are equal.
	 *
	 * @param toCompare
	 * 	Object to compare with @c *this.
	 *
	 * @return
	 * 	True if objects are equal. False in other situations.
	 */
	virtual const bool isEqual(const T *toCompare) const = 0;
};

}  // namespace core
}  // namespace coma

#endif /* COREINTERFACES_TRIVIALLYCOMPARABLE_H_ */
