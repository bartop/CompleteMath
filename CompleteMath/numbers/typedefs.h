/*
 * typedefs.h
 *
 *  Created on: 18 gru 2015
 *      Author: Bartosz Miera
 */

#ifndef NUMBERS_TYPEDEFS_H_
#define NUMBERS_TYPEDEFS_H_

namespace coma {
namespace numb {

template<class T>
using Pointer = std::shared_ptr<const T>;

using String = std::string;

}  // namespace numb
}  // namespace coma

#endif /* NUMBERS_TYPEDEFS_H_ */
