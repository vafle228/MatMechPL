#include <iostream>
#include "Vector.h"


int main()
{
    Vector v1 = Vector(1, 2, 3);
    Vector v2 = Vector(4, 5, 6);

    std::cout << Vector::Print(Vector::NumMult(v1, 10));
}
