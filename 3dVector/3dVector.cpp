#include <iostream>
#include "Vector.h"

using namespace std;


int const a = 1;

int main()
{
	double px, py, pz;
	cin >> px; cin >> py; cin >> pz;
	Vector position = Vector(px, py, pz);
	
	double vx, vy, vz;
	cin >> vx; cin >> vy; cin >> vz;
	Vector velocity = Vector(vx, vy, vz);


}
