#include "raymarch.h"
using namespace std;

int main(int argc, char** argv) {
	char* arg;
	arg = argv[1];
	if (argc < 2) {
		cout << "Invalid File Name Please Try Again: ";
		cin >> arg;
	}
	raymarch* rm = new raymarch(arg);
	rm->calculateValues();
	// Close console
	char input = 'y';
	while (input == 'y' || input == 'Y') {
		cout << "Create Another? (Y for Yes): ";
		cin >> input;
		if (input == 'Y' || input == 'y') {
			cout << "Input File Name: ";
			cin >> arg;
			raymarch* rm = new raymarch(arg);
			rm->calculateValues();
		}
	}
}