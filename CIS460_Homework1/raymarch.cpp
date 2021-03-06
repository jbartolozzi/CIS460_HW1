#include "raymarch.h"

using namespace std;

raymarch::raymarch(char* filename) {
	kValue = -1;
	fr = new fileReader(filename);
	cam = fr->getCameraFromFile();
	int size = ((int)fr->XYZC.x*(int)fr->XYZC.y*(int)fr->XYZC.z);
	vb = new voxelBuffer(fr->voxelDensities,size,fr->XYZC.x,fr->XYZC.y,fr->XYZC.z,fr->DELT);
	vb->origin = fr->ORIG;
}

// Ray = Eye + t (P-E)/|P-E|  glm::normalize(getDirectionFromCoordinate(i,j)-eye))
// r = xe + n*s

//transmittance 0 = opaque
void raymarch::calculateValues() {
	// set up output BMP
	cout << "Rendering..." << endl;
	BMP output;
	output.SetSize((int)fr->RESO.x,(int)fr->RESO.y);
	output.SetBitDepth(24);
	char* filename = fr->FILE;
	float step = fr->STEP;
	// for each x
	for (int sx = 0; sx < fr->RESO.x; sx++) {
		if (sx % 100 == 0) {
			cout << 100*((float)sx/fr->RESO.x) << "%, ";
		}
		// for each y
		for(int sy = 0; sy < fr->RESO.y; sy++) {
			glm::vec3 outColor(0.0,0.0,0.0);
			glm::vec3 direction = glm::normalize(cam->getDirectionFromCoordinate(sx,sy)-cam->eye);
			float T = 1.0;
			glm::vec3 Nrml(0,0,1);
			glm::vec3 Pnt(1,1,0);
			// for each step
			// camera z + depth of buffer / step size
			float a2 = -1 * glm::dot(direction,Nrml);
			float a1 = glm::dot(cam->eye,Nrml);
			int a3 = glm::floor(a1/a2);
			if (a3 > 0) {
				cout << "break" << endl;
			}
			for(int t = a3; t < ((cam->eye.z + vb->depth) / (fr->STEP)); t++) {

				glm::vec3 ray = cam->eye + (direction * (t * step));
				voxel* currentV = vb->get(ray);
				if (currentV != NULL && currentV->density > 0) {
					float deltaT = exp(kValue * step * (currentV->density));
					T *= deltaT;
					if (currentV->lightValue == -1) {
						glm::vec3* loc = vb->locationOfVoxel(ray);
						currentV->lightValue = computeLightValue(loc);
					}
					outColor += (1-deltaT) * fr->MRGB * T * (currentV->lightValue * fr->LCOL);
				}
			}
			outColor += T*fr->BRGB;
			output(sx,(fr->RESO.y - 1) - sy)->Red = outColor.x * 255;
			output(sx,(fr->RESO.y - 1) - sy)->Green = outColor.y * 255;
			output(sx,(fr->RESO.y - 1) - sy)->Blue = outColor.z * 255;
		}
	}
	cout << "100%" << endl;
	output.WriteToFile(filename);
	cout << "Successfully wrote file named: " << filename << endl;
	cout << endl;
}

float raymarch::computeLightValue(glm::vec3* currentVoxel) {
	
	if (currentVoxel != NULL) {
		glm::vec3 voxelPosition(currentVoxel->x,currentVoxel->y,currentVoxel->z);
		glm::vec3 lightDir = (fr->LPOS - voxelPosition);
		glm::vec3 normalizedLightDir = glm::normalize(lightDir);
		int steps = glm::length(lightDir)/fr->STEP;
		float T = 1.0;
		for(int i = 0; i <= steps; i++) {
			glm::vec3 getVec = voxelPosition + (normalizedLightDir * (i * fr->STEP));
			voxel* voxelAtStep = vb->get(getVec);
			if (voxelAtStep != NULL && voxelAtStep->density > 0) {
				T *= exp(kValue * fr->STEP * (voxelAtStep->density));
			}
		}
		return T;
	}
	else {
		return -1.0;
	}
}