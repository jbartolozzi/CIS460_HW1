#include "raymarch.h"
using namespace std;

int main(int argc, char** argv) {
	
	raymarch* rm = new raymarch();

	// Close console
	
	system("pause");
	cout << "Press ENTER to continue... " << flush;
	cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
}