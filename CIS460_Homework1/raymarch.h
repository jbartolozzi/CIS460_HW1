#ifndef RAYMARCH
#define RAYMARCH

#include "Camera.h"
#include "voxelBuffer.h"
#include "fileReader.h"

class raymarch {
public:
	float kValue;
	fileReader* fr;
	Camera* cam;
	voxelBuffer* vb;
	raymarch(char* filename);
	void calculateValues();
	float computeLightValue(glm::vec3* currentVoxel);
};

#endif