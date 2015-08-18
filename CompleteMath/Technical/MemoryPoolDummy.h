/*
 * MemoryPoolDummy.h
 *
 *  Created on: 3 sie 2015
 *      Author: Bartosz Miera
 */

#ifndef TECHNICAL_MEMORYPOOLDUMMY_H_
#define TECHNICAL_MEMORYPOOLDUMMY_H_

#include "MemoryPool.h"

namespace coma {
namespace tech {

/**
 * @brief
 *	Simple substitute for memory pool.
 */
class MemoryPoolDummy: public MemoryPool {
public:
	/**
	 * @brief
	 * 	Default virtual destructor.
	 */
	virtual ~MemoryPoolDummy();

	virtual void *allocate(const size_t size) override;

	virtual void deallocate(void *toDealloc) override;
};

extern MemoryPoolDummy memoryPoolDummy;

} /* namespace tech */
} /* namespace coma */

#endif /* TECHNICAL_MEMORYPOOLDUMMY_H_ */
