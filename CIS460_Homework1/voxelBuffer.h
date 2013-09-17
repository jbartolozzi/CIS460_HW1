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
	float voxelSize;
	voxelBuffer();
	voxelBuffer(float* input, int _width, int _height, int _depth, float size);
	voxel at(int x, int y, int z);
	voxel get(glm::vec3 v);
	voxel* voxelArray;
};
#endif