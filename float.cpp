#include <iostream>


using namespace std;


const int DOUBLE_LEN = 100;

bool contains(int* arr, int element) {
	for (int i = 0; i < DOUBLE_LEN; i++)
		if (arr[i] == element) return true;
	return false;
}

int* initStartArray() {
	int* init_arr = new int[DOUBLE_LEN];
	for (int i = 0; i < DOUBLE_LEN; i++)
		init_arr[i] = -1;
	return init_arr;
}

void printDoublePart(int* arr, int divisor, int start) {
	for (int i = start; i < DOUBLE_LEN; i++) {
		if (arr[i] == -1) break;
		cout << arr[i] / divisor;
	}
}

int main() {
	int m, n; 
	cin >> m >> n;

	int int_part = m / n;
	int* division_rems = initStartArray();

	int remain = (m % n) * 10;
	for (int i = 0; i < DOUBLE_LEN; i++) {
		if (contains(division_rems, remain)) break;
		division_rems[i] = remain; remain = (remain % n) * 10;
	}

	cout << int_part << ".";

	if (remain == 0)
		printDoublePart(division_rems, n, 0);

	else if (remain != 0) {
		int count = 0;
		while (remain != division_rems[count]) {
			cout << division_rems[count] / n; count++;
		}
		cout << "("; printDoublePart(division_rems, n, count); cout << ")";
	}

	return 0;
}
