#include "fileReader.h"


fileReader::fileReader(string filename) {
	std::string line;
	ifstream file;
	file.open(filename);
	if (!file.good()) {
		cout << "Invalid File Name" << endl;
	}
	else {
		while(getline(file,line)) {
			string token;
			std::istringstream tokens(line);
			while (tokens >> token) {

			}
		}
	}
}

Camera fileReader::getCameraFromFile() {
}