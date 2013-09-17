#include "voxelBuffer.h"
using namespace std;

voxelBuffer::voxelBuffer(float* input, int _width, int _height, int _depth, float size){
	voxelArray = new voxel[sizeof(input)];
	width = _width;
	height = _height;
	depth = _depth;
	voxelSize = size;
	for(int i = 0; i < sizeof(input); i++) {
		voxel vIn;
		vIn.density = input[i];
		voxelArray[i] = vIn;
	}
}

// get voxel at index
voxel voxelBuffer::at(int x, int y, int z) {
	int index = width * y + x + z*(width * height);
	return voxelArray[index];
}

// get closest voxel to float values
voxel voxelBuffer::get(glm::vec3 v){
	float x = v.x;
	float y = v.y;
	float z = v.z;

	return at(glm::floor(x/voxelSize),glm::floor(y/voxelSize),glm::floor(z/voxelSize));
}