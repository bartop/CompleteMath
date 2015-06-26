/*
 * Comparable.h
 *
 *  Created on: 23 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_COMPARABLE_H_
#define NUMBERS_COMPARABLE_H_

namespace cm {
namespace numb {
/**
 * @brief
 * 	Enum defining result of comparison.
 */
enum CompareResult{
	ThisGreater = 1,//!< ThisGreater @c *this object is greater than @c toCompare
	Equal = 0,      //!< Equal @c *this object is equal to @c toCompare
	ThisLesser = -1  //!< ThisLesser @c *this object is lesser than @c toCompare
};

/**
 * @brief
 * 	Interface for comparing objects.
 */
template<typename T>
class Comparable{
public:
	/**
	 * @brief
	 * 	Method used to compare objects.
	 *
	 * @param toCompare
	 *	Object with which @c *this is supposed to be compared.
	 *
	 * @return
	 * 	#CompareResult adequate to result of the comparison.
	 */
	virtual const CompareResult compare(const T &toCompare) const = 0;

	/**
	 * @brief
	 * 	Dummy virtual destructor.
	 */
	virtual ~Comparable(){}
};

} /* namespace numb */
} /* namespace cm */

#endif /* NUMBERS_COMPARABLE_H_ */
