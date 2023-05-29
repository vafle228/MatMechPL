#pragma once
#include <string>


class Vector {

public:
	double x, y, z;

	Vector(double x, double y, double z);
		
	static Vector Sum(Vector v1, Vector v2);
	static Vector Sub(Vector v1, Vector v2);

	static Vector NumMult(Vector v1, int num);
	static Vector NumMult(Vector v1, float num);
	static Vector NumMult(Vector v1, double num);

	static Vector VectorMult(Vector v1, Vector v2);
	static double SclalarMult(Vector v1, Vector v2);
	static double MixedMult(Vector v1, Vector v2, Vector v3);
		
	static std::string Print(Vector v1);

	static double Length(Vector v1);
	static Vector Normalize(Vector v1);

	static Vector NormalToSurface(Vector v1, Vector v2);

	static double Angel(Vector v1, Vector v2);
	static Vector RotateVector(Vector b1, Vector b2, double a);
};
