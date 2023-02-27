struct Vector
{
	double x;
	double y;
	double z;
};

void print_vector(Vector);

Vector sum(Vector a, Vector b);

Vector diff(Vector a, Vector b);

Vector const_product(Vector a, double d);

double scalar_product(Vector a, Vector b);

Vector Vector_product(Vector a, Vector b);

Vector mixed_product(Vector a, Vector b, Vector c);

double get_length(Vector a);

Vector get_normal(Vector a, Vector b);

Vector Vector_rotation(Vector a, Vector b, double corner);