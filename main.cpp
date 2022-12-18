#include <string>
#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;


const int hash_base = 7;


struct MaxString
{
	int pos, len;

	MaxString(int len, int pos)
	{
		this->len = len;
		this->pos = pos;
	}
};


long long hashRubyKarp(string str)
{
	long long hash = 0;
	for (int i = 0; i < str.length(); i++)
		hash += (int)str[i] * pow(hash_base, str.length() - i - 1);
	return hash;
}


long long recurentRubyKarp(long long last_hash, int length, char prev_char, char new_char)
{
	long long hash_delta = pow(hash_base, length - 1) * (int)prev_char;
	return hash_base * (last_hash - hash_delta) + (int)new_char;
}


bool checkStrings(long long str_hash, string str, int start_pos, long long substr_hash, string substr)
{
	if (str_hash != substr_hash) return false;

	for (int j = 0; j < substr.length(); j++)
		if (substr[j] != str[start_pos + j]) return false;
	return true;
}


bool isSubstring(string str, string substr)
{
	long long substr_hash = hashRubyKarp(substr);
	long long str_substr_hash = hashRubyKarp(str.substr(0, substr.length()));

	for (int i = 0; i < str.length() - substr.length(); i++)
	{
		if (checkStrings(str_substr_hash, str, i, substr_hash, substr)) return true;
		str_substr_hash = recurentRubyKarp(str_substr_hash, substr.length(), str[i], str[i + substr.length()]);
	}
	return checkStrings(str_substr_hash, str, str.length() - substr.length(), substr_hash, substr);
}


string findBiggestSubstr(string str, string substr)
{
	int left = 0;
	int right = substr.length();

	if (isSubstring(str, substr.substr(0, right))) return substr;

	MaxString max_str = MaxString(0, 0);
	while (right - left > 1)
	{
		int middle_len = (right + left) / 2;
		for (int i = 0; i <= substr.length() - middle_len; i++)
		{
			if (isSubstring(str, substr.substr(i, middle_len)))
			{
				if (max_str.len < middle_len)
					max_str = MaxString(middle_len, i);
				left = middle_len; break;
			}
		}
		if (left != middle_len) right = middle_len;
	}
	return substr.substr(max_str.pos, max_str.len);
}


int main()
{
	setlocale(0, "rus");

	ifstream string_file("string.txt");
	ifstream substring_file("substring.txt");

	string str; string_file >> str;
	string substr; substring_file >> substr;

	cout << findBiggestSubstr(str, substr) << endl;

	return 0;
}