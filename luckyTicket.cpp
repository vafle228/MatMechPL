#include <cmath>
#include <iostream>


using namespace std;


int sum1(int number[]) {
	int sum1 = 0;
	for (int i = 0; i < 3; i++)
		sum1 += number[i];
	return sum1;
}


int sum2(int number[]) {
	int sum2 = 0;
	for (int i = 3; i < 6; i++)
		sum2 += number[i];
	return sum2;
}


int delta(int number[]) {
	return abs(sum1(number) - sum2(number));
}


void printNumber(int number[]) {
	for (int i = 0; i < 6; i++)
		cout << number[i];
	cout << endl;
}


void printUpperLuckyTicket1(int number[]) {
	// Print nearest upper ticket if s1 > s2
	for (int i = 5; i >= 0; i--) {
		if (number[i] + delta(number) <= 9) {
			number[i] += delta(number);
			printNumber(number); return;
		}
		number[i] = 9;
	}
}


void printLowerLuckyTicket1(int number[]) {
	// Print nearest lower ticket if s1 < s2
	for (int i = 5; i >= 0; i--) {
		if (number[i] - delta(number) >= 0) {
			number[i] -= delta(number);
			printNumber(number); return;
		}
		number[i] = 0;
	}
}


void printUpperLuckyTicket2(int number[]) {
	// Print nearest upper ticket if s1 < s2
	for (int i = 4; i >= 0; i--) {
		if (number[i] == 9) continue;

		number[i] += 1;
		for (int j = i + 1; j < 6; j++)
			number[j] = 0;

		if (sum1(number) >= sum2(number))
			return printUpperLuckyTicket1(number);
	}
}


void printLowerLuckyTicket2(int number[]) {
	// Print nearest upper ticket if s1 > s2
	for (int i = 4; i >= 0; i--) {
		if (number[i] == 0) continue;

		number[i] -= 1;
		for (int j = i + 1; j < 6; j++)
			number[j] = 9;

		if (sum1(number) <= sum2(number))
			return printLowerLuckyTicket1(number);
	}
}


int main() {
	int number[6];
	for (int i = 0; i < 6; i++)
		cin >> number[i];

	if (sum1(number) == sum2(number))
		printNumber(number);
	else if (sum1(number) > sum2(number)) {
		printUpperLuckyTicket1(number);
		printLowerLuckyTicket2(number);
	}
	else if (sum1(number) < sum2(number)) {
		printUpperLuckyTicket2(number);
		printLowerLuckyTicket1(number);
	}
}
