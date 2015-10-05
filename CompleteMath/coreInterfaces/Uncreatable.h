/*
 * Uncreatable.h
 *
 *  Created on: 5 paü 2015
 *      Author: Bartosz Miera
 */

#ifndef COREINTERFACES_UNCREATABLE_H_
#define COREINTERFACES_UNCREATABLE_H_

namespace coma {
namespace numb {

/**
 * @brief
 *	Object that is impossible to create.
 */
class Uncreatable {
public:
	Uncreatable() = delete;
	Uncreatable(const Uncreatable &) = delete;
	Uncreatable(Uncreatable &&) = delete;
	Uncreatable &operator=(const Uncreatable &) = delete;
	Uncreatable &operator=(Uncreatable &&) = delete;
	~Uncreatable() = delete;
};

} /* namespace numb */
} /* namespace coma */

#endif /* COREINTERFACES_UNCREATABLE_H_ */
