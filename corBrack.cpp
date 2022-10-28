#include <stack>
#include <iostream>


using namespace std;


int main() {
	char bracket;
	int max_deepth = 0;
	const int STR_LENGTH = 7;
	
	int top = 0;
	char brackets_order[STR_LENGTH];
	
	for (int i = 0; i <= STR_LENGTH; i++) {
		if (i == STR_LENGTH) {
			if (top == 0) {
				cout << "Correct! Max deepth: " << max_deepth << endl; break;
			}
			cout << "Error" << endl; break;
		}
		
		cin >> bracket;

		if (bracket != '(' && bracket != ')' && bracket != '[' && bracket != ']')
			continue;

		if (bracket == '(' || bracket == '[') {
			brackets_order[top] = bracket; top++;
			max_deepth = max(max_deepth, top); 
			continue;
		}

		if (top == 0) {
			cout << "Error" << endl; break;
		}
		
		if (brackets_order[top - 1] == '(' && bracket != ')') {
			cout << "Error" << endl; break;
		}

		if (brackets_order[top - 1] == '[' && bracket != ']') {
			cout << "Error" << endl; break;
		}
		brackets_order[top - 1] = ' '; top--;
	}
	
	return 0;
}