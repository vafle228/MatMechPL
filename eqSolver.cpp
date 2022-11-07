#include <cmath>
#include <iostream>


using namespace std;

double a, b, c;
const double epsilon = pow(10, -8);

double equtation(double x) {
	return a * pow(x, 2) + b * x + c;
}

double equtationSolver(double left_end, double right_end) {
	if (right_end - left_end < epsilon)
		return (left_end + right_end) / 2;

	if (equtation(left_end) == 0) return left_end;
	
	if (equtation(right_end) == 0) return right_end;

	double new_x = (left_end + right_end) / 2;
	if (equtation(left_end) * equtation(new_x) < 0)
		return equtationSolver(left_end, new_x);
	return equtationSolver(new_x, right_end);
}

int main() {
	cin >> a >> b >> c;

	double left_end, rigth_end;
	cin >> left_end >> rigth_end;

	if (equtation(left_end) * equtation(rigth_end) > 0) {
		cout << "Error" << endl; return 0;
	}
	cout << equtationSolver(left_end, rigth_end) << endl;

	return 0;
}
