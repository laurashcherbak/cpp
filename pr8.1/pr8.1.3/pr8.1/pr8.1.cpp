#ifndef _CRT_SECURE_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
#endif // !#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int Count(char* s)
{
	char* t = s;
	int k = 0;
	int pos = 0;

	while ((t = strpbrk(t, "SQ")) != NULL)
	{
		if ((t[pos] == 'S' && t[pos + 1] == 'Q') || (t[pos] == 'Q' && t[pos + 1] == 'S')) {
			k++;
		}
		t++;
	}

	return k;
}

char* Change(char* s)
{
	char* r = s;
	int pos = 0;
	char* t = new char[256];

	while ((s = strpbrk(s + pos, "SQ")) != NULL)
	{
		pos = 0;
		if ((s[pos] == 'S' && s[pos + 1] == 'Q') || (s[pos] == 'Q' && s[pos + 1] == 'S')) {
			strcpy(t, s + 2);
			s[0] = '\0';
			strcat(s, "***");
			strcat(s, t);
		}
		else
			pos++;
	}

	return r;
}

int main()
{
	char str[128];

	cout << "Enter string : ";
	cin.getline(str, 128);

	cout << "String contained " << Count(str) << " groups of 'SQ' or 'QS'" << endl;

	char* dest1 = new char[128];

	dest1 = Change(str);

	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest1 << endl;

	return 0;
}
