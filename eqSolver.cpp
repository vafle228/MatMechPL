#include <cmath>
#include <iostream>


using namespace std;

double eq(double a, double b, double c, double x) {
	return a * pow(x, 2) + b * x + c;
}

int main() {
	double a, b, c;
	cin >> a >> b >> c;

	double left_end, rigth_end;
	cin >> left_end >> rigth_end;

	double epsilon = pow(10, -8);
	
	if (eq(a, b, c, left_end) * eq(a, b, c, rigth_end) > 0){
		cout << "Error" << endl; return 0;
	}
	
	if (eq(a, b, c, left_end) == 0){
		cout << left_end << endl; return 0;
	}
	
	if (eq(a, b, c, rigth_end) == 0){
		cout << rigth_end << endl; return 0;
	}

	while (rigth_end - left_end > epsilon) {
		double new_x = (left_end + rigth_end) / 2;

		if (eq(a, b, c, left_end) * eq(a, b, c, new_x) < 0)
			rigth_end = new_x;
		else
			left_end = new_x;
	}

	cout << (left_end + rigth_end) / 2 << endl;
	
	system("pause");
	
	return 0;
}
