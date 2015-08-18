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
	using size_t = std::size_t;
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
	virtual void *allocate(const size_t size) = 0;

	/**
	 * @brief
	 * 	Deallocates given memory.
	 *
	 * @param toDealloc
	 * 	Pointer to memory to be deallocated.
	 */
	virtual void deallocate(void *toDealloc) = 0;

	/**
	 * @brief
	 * 	Default virtual destructor.
	 */
	virtual ~MemoryPool() = default;
};

} /* namespace tech */
} /* namespace coma */

#endif /* TECHNICAL_MEMORYPOOL_H_ */
