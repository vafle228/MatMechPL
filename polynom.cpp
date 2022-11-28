#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

const string polynom_power = "^";
const string polynom_var = "x";

struct PolynomMember {
	double coeff; int power;

	PolynomMember() {
		this->coeff = 0;
		this->power = 0;
	}

	PolynomMember(double coeff, int power) {
		this->coeff = coeff;
		this->power = power;
	}
};

int count(string str, string symb_to_count) {
	int result = 0;

	int last_symb = str.find(symb_to_count, 0);
	while (last_symb != string::npos) {
		result++; last_symb = str.find(symb_to_count, last_symb + 1);
	}
	return result;
}

string* split(string str, string delim) {
	int delim_count = count(str, delim);
	string* pSplited = new string[delim_count + 1];

	int last_symb = 0;
	for (int i = 0; i < delim_count; i++) {
		int pos = str.find(delim, last_symb);
		pSplited[i] = str.substr(last_symb, pos - last_symb);
		last_symb = pos + delim.length();
	}
	pSplited[delim_count] = str.substr(last_symb); return pSplited;
}

string* parseArgs(string arg_str) {
	if (arg_str.rfind("+") != string::npos)
		return split(arg_str, "+");
	return split(arg_str, "-");
}

PolynomMember* polynomParser(string polynom, int args_count) {
	PolynomMember* pMembers = new PolynomMember[args_count];
	string* pArgs = split(polynom, polynom_var + polynom_power);
	
	double coeff = stod(pArgs[0]); int power;
	for (int i = 1; i < args_count; i++) {
		string* pParsed_args = parseArgs(pArgs[i]);
		
		power = stoi(pParsed_args[0]);
		pMembers[i - 1] = PolynomMember(coeff, power);
		
		coeff = pArgs[i].rfind("-") == string::npos
			? stod(pParsed_args[1]) : -stod(pParsed_args[1]);
		delete[] pParsed_args;
	}
	power = stoi(pArgs[args_count]);
	pMembers[args_count - 1] = PolynomMember(coeff, power);
	delete[] pArgs;  return pMembers;
}

double countPolynom(double x, PolynomMember* polynom, int polynom_len) {
	double result = 0;
	for (int i = 0; i < polynom_len; i++)
		result += (&polynom[i])->coeff * pow(x, (&polynom[i])->power);
	return result;
}

int main() {
	ofstream out("out/points.txt");

	string polynom = "0.5x^1";
	int polynom_len = count(polynom, polynom_var);
	PolynomMember* pPolynom_args = polynomParser(polynom, polynom_len);

	double left, right, count;
	cin >> left; cin >> right; cin >> count;

	double step = (right - left) / count;
	for (double point = left; point <= right; point += step)
		out << countPolynom(point, pPolynom_args, polynom_len) << endl;
	out.close(); delete[] pPolynom_args;
}
