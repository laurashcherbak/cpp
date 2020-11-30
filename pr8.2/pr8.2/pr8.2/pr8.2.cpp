#ifndef _CRT_SECURE_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
#endif // !#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

string Trim(string& s)
{
	const string& f = " ";
	const string& sp = " \t";

	// replace sub ranges
	auto beginSpace = s.find_first_of(sp);
	while (beginSpace != string::npos)
	{
		const auto endSpace = s.find_first_not_of(sp, beginSpace);
		const auto range = endSpace - beginSpace;

		s.replace(beginSpace, range, f);

		const auto newStart = beginSpace + f.length();
		beginSpace = s.find_first_of(sp, newStart);
	}

	// trim trailing spaces
	size_t endpos = s.find_last_not_of(f);
	size_t startpos = s.find_first_not_of(f);
	if (std::string::npos != endpos)
	{
		s = s.substr(0, endpos + 1);
		s = s.substr(startpos);
	}
	else {
		s.erase(std::remove(begin(s), end(s), ' '), end(s));
	}

	return s;
}

int main()
{
	string str = "  \t Remove  leading    and\ttrailing    spaces   \t\t";

	cout << "Source string: ";
	cout << "["<< str << "]" << endl;

	cout << "Result string: ";
	cout << "[" << Trim(str) << "]" << endl;

	return 0;
}
