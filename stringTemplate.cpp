#include <fstream>
#include <string>

using namespace std;

const int tmp_len = 100;
const string pattern = "{{name}}";

string readFileTemplate() {
	ifstream template_file("template.txt");

	string template_str, tmp_str;
	while (!template_file.eof()) {
		getline(template_file, tmp_str);
		template_str += tmp_str + "\n";
	}
	template_file.close(); return template_str;
}

string* initTemplate() {
	string template_str = readFileTemplate();
	string* pTemplate = new string[tmp_len];
	
	for (int i = 0; template_str != ""; i++) {
		int pos = template_str.find(pattern);
		pTemplate[i] = template_str.substr(0, pos);
		template_str.erase(0, pos + pattern.length());
	}
	return pTemplate;
}

int main() {
	ifstream users_file("users.txt");
	string* pTemplate = initTemplate();

	string user;
	while (!users_file.eof()) {
		getline(users_file, user, '\n');
		ofstream filled_template("Filled\\" + user + ".txt");

		for (int i = 0; i < tmp_len; i++) {
			if (pTemplate[i] == "") break;
			if (pTemplate[i + 1] == "") filled_template << pTemplate[i];
			else filled_template << pTemplate[i] << user;
		}
		filled_template.close();
	}
	users_file.close();
}
