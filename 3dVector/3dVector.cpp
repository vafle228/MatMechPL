#include <iostream>
#include "Vector.h"


int main()
{
    Vector v1 = Vector(-2, 0, 2);
    Vector v2 = Vector(-3, -3, -3);
    Vector v3 = Vector(-3, -1, 1);

    std::cout << Vector::Print(Vector::RotateVector(v1, v2, v3, 60));
}
