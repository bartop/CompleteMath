/*
 * typedefs.h
 *
 *  Created on: 18 gru 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_TYPEDEFS_H_
#define NUMBERS_TYPEDEFS_H_

#include <memory>

namespace coma {
namespace numb {

template<class T>
using Pointer = std::shared_ptr<const T>;

using String = std::string;

template<class T, class U>
Pointer<T> staticPointerCast(const Pointer<U> &toCast){
	return std::static_pointer_cast<const T>(toCast);
}

}  // namespace numb
}  // namespace coma

#endif /* NUMBERS_TYPEDEFS_H_ */
