/*
 * ConstantSizedMemoryPool.h
 *
 *  Created on: 3 sie 2015
 *      Author: Bartosz Miera
 */

#ifndef TECHNICAL_CONSTANTSIZEDMEMORYPOOL_H_
#define TECHNICAL_CONSTANTSIZEDMEMORYPOOL_H_

#include "MemoryPool.h"
#include <list>

namespace coma {
namespace tech {

/**
 * @brief
 *	Memory pool which is not resizable after creation.
 */
class ConstantSizedMemoryPool: public MemoryPool {
public:
	typedef std::size_t size_t;
	/**
	 * @brief
	 * 	Constructs memory pool.
	 *
	 * @param chunkSize
	 * 	Size (in bytes) of single memory chunk in memory pool.
	 *
	 * @param chunkNumber
	 * 	Number of chunks inside memory pool.
	 */
	ConstantSizedMemoryPool(const size_t chunkSize, const size_t chunkNumber) noexcept;

	/**
	 * @brief
	 * 	Copy constructor performing deep copy of memory pool;
	 *
	 * @param toCopy
	 * 	Object to be copied.
	 */
	ConstantSizedMemoryPool(const ConstantSizedMemoryPool &toCopy);

	/**
	 * @brief
	 * 	Frees memory.
	 */
	virtual ~ConstantSizedMemoryPool() noexcept;

	/**
	 * @brief
	 * 	Assign operator.
	 *
	 * @param toCopy
	 * 	Object to copy into @c *this.
	 *
	 * @return
	 * 	@c *this after assignment.
	 */
	ConstantSizedMemoryPool &operator=(ConstantSizedMemoryPool toCopy);

	virtual void *allocate(const size_t size) override;
	virtual void deallocate(void *toDealloc) override;

private:
	size_t m_chunkSize;
	size_t m_chunkNumber;
	void *m_storedMemory = nullptr;
	std::list<void *> m_freeChunks;
	std::list<void *> m_usedChunks;

	void initalize();
	void swap(ConstantSizedMemoryPool &toSwap);
};

} /* namespace tech */
} /* namespace coma */
#endif /* TECHNICAL_CONSTANTSIZEDMEMORYPOOL_H_ */
