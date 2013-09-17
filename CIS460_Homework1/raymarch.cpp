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