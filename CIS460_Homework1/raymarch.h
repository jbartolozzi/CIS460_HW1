#ifndef RAYMARCH
#define RAYMARCH

#include "Camera.h"
#include "voxelBuffer.h"
#include "fileReader.h"

class raymarch {
public:
	fileReader* fr;
	Camera* cam;
	voxelBuffer* vb;
	raymarch();
};

#endif