/*
 * SPChunk.h
 *
 *  Single producer chunk
 *  Created on: Dec 29, 2011
 */

#ifndef SPCHUNK_H_
#define SPCHUNK_H_

#include "Chunk.h"


class SPChunk : public Chunk {
public:
	SPChunk(int owner);
	virtual ~SPChunk();

	virtual OpResult insertTask(const Task& t, bool& isLastTask);
	virtual OpResult getTask(Task*& t);

	virtual int getMaxSize();
};

class SPChunkFactory : public ChunkFactory {
public:
	SPChunkFactory() {}
	virtual SPChunk* createChunk(int owner) {
		return new SPChunk(owner);
	}
};

#endif /* SPCHUNK_H_ */