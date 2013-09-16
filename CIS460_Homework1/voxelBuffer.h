#ifndef VOXELBUFFER
#define VOXELBUFFER
#include "voxel.h"
#include <vector>

class voxelBuffer {
private:
	int depth;
	int width;
	int height;

public:
	voxelBuffer();
	voxelBuffer(int width, int height, int depth);
	voxel get(int x, int y, int z);
	voxel* voxelArray;
};
#endif