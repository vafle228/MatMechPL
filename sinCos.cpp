#include <cmath>
#include <iostream>


using namespace std;


double mySin(double angle) {
	double epsilon = pow(10, -6);
	
	double last_added = angle;
	double current_result = angle;

	for (int count = 1; abs(last_added) > epsilon; count++) {
		int divisor = (2 * count) * (2 * count + 1);
		last_added *= -1 * pow(angle, 2) / divisor;
		current_result += last_added;
	}

	return current_result;
}

double myCos(double angle) {
	double epsilon = pow(10, -6);

	double last_added = 1;
	double current_result = 1;

	for (int count = 1; abs(last_added) > epsilon; count++) {
		int divisor = (2 * count) * (2 * count - 1);
		last_added *= -1 * pow(angle, 2) / divisor;
		current_result += last_added;
	}

	return current_result;
}


int main() {
	const double PI = acos(-1.0);

	char func; cin >> func;
	int angle; cin >> angle;

	switch (func) {
		case 'c':
			cout << "myCos: " << myCos(angle / PI) << endl;
			cout << "cos: " << cos(angle / PI) << endl;
			break;
		
		case 's':
			cout << "mySin: " << mySin(angle / PI) << endl;
			cout << "sin: " << sin(angle / PI) << endl;
			break;
	}
	
	return 0;
}