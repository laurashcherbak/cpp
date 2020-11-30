#ifndef _CRT_SECURE_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
#endif // !#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int Count(const string s)
{
	int k = 0;
	size_t pos = 0;

	while ((pos = s.find("SQ", pos)) != -1)	{
		k++;
		pos++;
	}

	pos = 0;
	while ((pos = s.find("QS", pos)) != -1) {
		k++;
		pos++;
	}

	return k;
}

string Change(string& s)
{
	while (s.find("SQ") != -1) {
		s = s.replace(s.find("SQ"), 2, "***");
	}

	while (s.find("QS") != -1) {
		s = s.replace(s.find("QS"), 2, "***");
	}

	return s;
}

int main()
{
	string str;

	cout << "Enter string:";
	cin >> str;

	cout << "String contained " << Count(str) << " groups of 'SQ' or 'QS'" << endl;

	string dest = Change(str);

	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;

	return 0;
}
