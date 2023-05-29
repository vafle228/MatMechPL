#include <cmath>
#include "Vector.h"

const double PI = 3.14159265359;

Vector::Vector(double x, double y, double z) 
	: x(x), y(y), z(z)
{ }

Vector Vector::Sum(Vector v1, Vector v2)
{
	return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector Vector::Sub(Vector v1, Vector v2)
{
	return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

double Vector::SclalarMult(Vector v1, Vector v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

Vector Vector::NumMult(Vector v1, int num)
{
	return NumMult(v1, (double)num);
}

Vector Vector::NumMult(Vector v1, float num)
{
	return NumMult(v1, (double)num);
}

Vector Vector::NumMult(Vector v1, double num)
{
	return Vector(v1.x * num, v1.y * num, v1.z * num);
}

Vector Vector::VectorMult(Vector v1, Vector v2)
{
	return Vector(
		(v1.y * v2.z) - (v1.z * v2.y),
		- (v1.x * v2.z) + (v1.z * v2.x),
		(v1.x * v2.y) - (v1.y * v2.x)
	);
}

double Vector::MixedMult(Vector v1, Vector v2, Vector v3)
{
	return SclalarMult(VectorMult(v1, v2), v3);
}

std::string Vector::Print(Vector v1)
{
	return "(" + std::to_string(v1.x) + ", " + std::to_string(v1.y) + ", " + std::to_string(v1.z) + ")";
}

double Vector::Length(Vector v1)
{
	return std::sqrt(SclalarMult(v1, v1));
}

Vector Vector::Normalize(Vector v1)
{
	return NumMult(v1, 1 / Length(v1));
}

Vector Vector::NormalToSurface(Vector v1, Vector v2)
{
	return Normalize(VectorMult(v1, v2));
}

double Vector::Angel(Vector v1, Vector v2)
{
	return std::acos(SclalarMult(v1, v2) / Length(v1) * Length(v2)) * 180 / PI;
}

Vector Vector::RotateVector(Vector b1, Vector b2, double a)
{
	Vector zaxis = NormalToSurface(b1, b2);
	Vector xaxis = VectorMult(zaxis, b1);

	double sin_rot = std::sin(a * PI / 180);
	double cos_rot = std::cos(a * PI / 180);

	return Sum(NumMult(b1, cos_rot), NumMult(xaxis, sin_rot));
}
