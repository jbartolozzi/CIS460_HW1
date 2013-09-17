#include "raymarch.h"

using namespace std;

raymarch::raymarch() {
	fr = new fileReader();
	cam = fr->getCameraFromFile();
	vb = new voxelBuffer(fr->voxelDensities,fr->XYZC.x,fr->XYZC.y,fr->XYZC.z,fr->DELT);
	char* outname = fr->FILE;
	cam->printImage(outname);
	cout << "Successfully output file named: " << outname << endl;
}

// Ray = Eye + t (P-E)/|P-E|  glm::normalize(getDirectionFromCoordinate(i,j)-eye))
// r = xe + n*s

void raymarch::calculateValues() {
	float step = fr->STEP;
	for (int sx = 0; sx < fr->RESO.x; sx++) {
		for(int sy = 0; sy < fr->RESO.y; sy++) {
			glm::vec3 outColor(0,0,0);
			for(float t; t < 100; t+=step) {
				glm::vec3 ray = cam->eye + glm::normalize(cam->getDirectionFromCoordinate(sx,sy)) * t;
				glm::vec3 G = fr->MRGB * (vb->get(ray)).density;

			}
		}
	}
}