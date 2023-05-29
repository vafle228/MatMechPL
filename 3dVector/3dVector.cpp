#include <iostream>
#include "Vector.h"

using namespace std;

int const a = 1;

double CountAxisWayTime(double axis_vel, double axis_dest) 
{
	if (axis_vel == 0) return INT_MAX;
	
	if (axis_vel > 0) 
		return (a - axis_dest) / axis_vel;
	return -axis_dest / axis_vel;
}

Vector GetSurfaceNormal(Vector position) 
{
	Vector surface_normal = Vector(0, 0, 0);

	if (position.x == 0 || position.x == 1) 
		surface_normal = Vector::Sum(surface_normal, { -1, 0, 0 });
	if (position.y == 0 || position.y == 1) 
		surface_normal = Vector::Sum(surface_normal, { 0, 1, 0 });
	if (position.z == 0 || position.z == 1) 
		surface_normal = Vector::Sum(surface_normal, { 0, 0, -1 });

	return surface_normal;
}

int main()
{
	double px, py, pz;
	cin >> px; cin >> py; cin >> pz;
	Vector position = Vector(px, py, pz);
	
	double vx, vy, vz;
	cin >> vx; cin >> vy; cin >> vz;
	Vector velocity = Vector(vx, vy, vz);

	double time; cin >> time;

	while (true) 
	{
		double x_time = CountAxisWayTime(velocity.x, position.x);
		double y_time = CountAxisWayTime(velocity.y, position.y);
		double z_time = CountAxisWayTime(velocity.z, position.z);

		double actual_time = std::min(std::min(x_time, y_time), z_time);

		if (time - actual_time <= 0) break;

		time -= actual_time;
		position = Vector::Sum(position, Vector::NumMult(velocity, actual_time));
		
		Vector normal = GetSurfaceNormal(position);
		double fall_angle = Vector::Angel(velocity, normal);

		if (2 * fall_angle - 180 <= std::pow(10, -8)) fall_angle = 180;

		if (180 - fall_angle <= std::pow(10, -8) || fall_angle <= std::pow(10, -8))
			velocity = Vector::NumMult(velocity, -1);
		else velocity = Vector::RotateVector(velocity, normal, 2 * fall_angle - 180);
	}

	std::cout << Vector::Print(Vector::Sum(position, Vector::NumMult(velocity, time))) << endl;
}
