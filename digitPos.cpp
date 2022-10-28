#include <cmath>
#include <iostream>


using namespace std;


int getNumsCount(int length) {
	return 9 * length * pow(10, length - 1);
}


int getNumberDigit(int number, int pos) {
	// Gets poses digit in number from end
	for (int count = 0; count < pos; count++)
		number = number / 10;
	return number % 10;
}


int main() {
	int num_pos = 0;
	cin >> num_pos;

	int num_len = 1;
	while (getNumsCount(num_len) <= num_pos) {
		num_pos -= getNumsCount(num_len); num_len++;
	}

	int digit_offset = (num_pos - 1) / num_len;
	int current_number = pow(10, num_len - 1) + digit_offset;

	cout << getNumberDigit(current_number, num_len - (num_pos - 1) % num_len - 1) << endl;

	return 0;
}
