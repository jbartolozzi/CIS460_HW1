#include "voxelBuffer.h"
using namespace std;

voxelBuffer::voxelBuffer(){
	
}

voxelBuffer::voxelBuffer(int _width, int _height, int _depth) {
	voxelArray = new voxel[_width*_height*_depth];
	width = _width;
	height = _height;
	depth = _depth;
}

voxel voxelBuffer::get(int x, int y, int z) {
	int index = width * y + x + z*(width * height);
	return voxelArray[index];
}