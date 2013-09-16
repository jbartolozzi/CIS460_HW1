#include "fileReader.h"
using namespace std;

fileReader::fileReader(string filename) {
	std::string line;
	ifstream file(filename);
	if (!file.good()) {
		cout << "Invalid File Name" << endl;
	}
	else {
		while(!file.eof()) {
			char line[100];
			file.getline(line,100);
			if (
			std::istringstream tokens(line);
			while (tokens >> token) {

			}
		}
	}
}

Camera fileReader::getCameraFromFile() {
}

/*
pass in string line
char* attribute = strtok(line, " ");

if (strcmp(attribute, "DELT")==0) {
}

char* readCharsToken () {
	char* token = strtok(NULL, " ");
	return token;
}

for converting to int
atoi(readCharsToken);

for converting to float
return (float) atof(readCharsToken());

to get the voxel densities
parse(char* line) {
VoxelDensities[index] = (float) atof(line)
index++
}