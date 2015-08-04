/*
 * MemoryPool.h
 *
 *  Created on: 3 sie 2015
 *      Author: Bartosz Miera
 */

#ifndef TECHNICAL_MEMORYPOOL_H_
#define TECHNICAL_MEMORYPOOL_H_

#include <vector>

namespace coma {
namespace tech {

/**
 * @brief
 *	Interface for memory pool.
 */
class MemoryPool {
public:
	typedef std::size_t size_t;
	/**
	 * @brief
	 * 	Allocates given amount of memory.
	 *
	 * @param size
	 * 	Size of allocated memory.
	 *
	 * @return
	 * 	Pointer to allocated memory.
	 */
	virtual void *const allocate(const size_t size) = 0;

	/**
	 * @brief
	 * 	Deallocates given memory.
	 *
	 * @param toDealloc
	 * 	Pointer to memory to be deallocated.
	 */
	virtual void deallocate(void *const toDealloc) = 0;

	/**
	 * @brief
	 * 	Dummy virtual destructor.
	 */
	virtual ~MemoryPool(){}
};

} /* namespace tech */
} /* namespace coma */

#endif /* TECHNICAL_MEMORYPOOL_H_ */
