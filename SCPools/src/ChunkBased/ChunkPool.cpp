/*
 * ChunkPool.cpp
 *
 *  Created on: Dec 29, 2011
 *      Author: dima39
 */

#include "ChunkPool.h"

ChunkPool::ChunkPool(int o, int initialSize) :
	owner(o),
	atomicStat(new AtomicStatistics()),
	chunkQueue(new MSQueue<SPChunk*>())
{
	for(int i = 0; i < initialSize; i++) {
		putChunk(new SPChunk(owner));
	}
}

ChunkPool::~ChunkPool() {
}

SPChunk* ChunkPool::getChunk() {
	SPChunk* c;
	bool res = chunkQueue->dequeue(c, atomicStat);
	return (res) ? c : NULL;
}

void ChunkPool::putChunk(SPChunk* c) {
	this->chunkQueue->enqueue(c, atomicStat);
}

