/*
 * Arithmetic.h
 *
 *  Created on: 27 cze 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_ARITHMETIC_H_
#define NUMBERS_ARITHMETIC_H_

#include "Subtractable.h"
#include "Dividable.h"

namespace coma {
namespace core {
/**
 * @brief
 * 	Interface for objects for which arithmetical operations are possible.
 */
template<typename T, typename U = T>
class Arithmetic:
	public Subtractable<T, U>,
	public Dividable<T, U>{
public:
	virtual ~Arithmetic(){};
};

} /* namespace core */
} /* namespace coma */

#endif /* NUMBERS_ARITHMETIC_H_ */
