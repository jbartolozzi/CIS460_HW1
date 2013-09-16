#include "main.h"
using namespace std;

int main(int argc, char** argv) {
	voxel v1 = voxel(3.14,10.65);
	voxelBuffer *vb1 = new voxelBuffer(5,5,5);
	vb1->voxelArray[8] = v1;

	cout << vb1->get(3,1,0).density << endl;
	cout << "Press ENTER to continue... " << flush;
	cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
}