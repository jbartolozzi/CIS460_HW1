#include "main.h"
using namespace std;

int main(int argc, char** argv) {
	cout << "Please Input File Name: ";

	char* s1 = new char[100];
	cin >> s1;

	fileReader* fr1 = new fileReader(s1);
	Camera* c = fr1->getCameraFromFile();
	
	cout << "MRGB: " << fr1->MRGB.x << ", " << fr1->MRGB.y << ", " << fr1->MRGB.z << endl;
	cout << "RESO: " << fr1->RESO.x << ", " << fr1->RESO.y << endl;
	cout << "VOXEL BUFFER SIZE = " << fr1->voxelDensities[0] << endl;
	cout << "VOXEL BUFFER SIZE = " << fr1->voxelDensities[1] << endl;
	cout << "VOXEL BUFFER SIZE = " << fr1->voxelDensities[2] << endl;
	cout << "VOXEL BUFFER SIZE = " << fr1->voxelDensities[3] << endl;
	system ("PAUSE");
	cout << "Press ENTER to continue... " << flush;
	cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
}