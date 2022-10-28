#include <cmath>
#include <iostream>


using namespace std;


struct Point {
	public:
		double x, y;

		Point() {
			cin >> this->x; cin >> this->y;
		}

		double getDistance(Point target_point) {
			return sqrt(
				pow(this->x - target_point.x, 2) +
				pow(this->y - target_point.y, 2)
			);
		}
};


bool compareDouble(double num1, double num2) {
	// Returns if num1 == num2
	double epsilon = pow(10, -8);
	return abs(num1 - num2) < epsilon;
}


double hypotenuseSquare(Point p1, Point p2) {
	return pow(p1.getDistance(p2), 2);
}


double cathetsSquareSum(Point p1, Point p2, Point p3) {
	// p1 = hypotenuse, p2 and p3 = cathets
	return pow(p3.getDistance(p1), 2) + pow(p3.getDistance(p2), 2);
}


int main() {
	Point point1 = Point();
	Point point2 = Point();
	Point point3 = Point();

	Point possible_sides[3][3] = {
		{point1, point2, point3},
		{point2, point3, point1},
		{point3, point1, point2},
	};

	for (int i = 0; i < 3; i++) {
		double hypotenuse = hypotenuseSquare(
			possible_sides[i][0], possible_sides[i][1]);
		
		double cathets_sum = cathetsSquareSum(
			possible_sides[i][0], possible_sides[i][1], possible_sides[i][2]);
		
		if (compareDouble(hypotenuse, cathets_sum)) {
			double
				vector1_x = possible_sides[i][1].x - possible_sides[i][2].x,
				vector1_y = possible_sides[i][1].y - possible_sides[i][2].y;

			double 
				vector2_x = possible_sides[i][0].x - possible_sides[i][2].x,
				vector2_y = possible_sides[i][0].y - possible_sides[i][2].y;

			cout 
				<< "(" << 
					(vector1_x + vector2_x) + possible_sides[i][2].x
				<< ", " << 
					(vector1_y + vector2_y) + possible_sides[i][2].y 
				<< ")" << 
			endl;
		}
	}

	return 0;
}