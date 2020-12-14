#ifndef _CRT_SECURE_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
#endif // !#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
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

void ProcessTrim(const string src_fname, const string dst_fname)
{
	string s; // прочитаний рядок

	ifstream fin(src_fname); // відкрили файл для зчитування
	ofstream fout(dst_fname); // відкрили файл для запису
	while (getline(fin, s)) // поки можна прочитати рядок
	{
		fout << Trim(s) << endl; // замінили пробіли та записали його у файл
	}
	fout.close();
	fin.close();
}

void PrepareAndSaveTXTFile(const string fname) // створення файлу з введених рядків
{
	string s;

	ofstream fout(fname);
	for (int i = 0; i < 10; i++) {
		s = "  \t Remove  leading    and\ttrailing    spaces   \t\t";
		fout << s << endl; // записали його у файл
	}
	fout.close();
}

void PrintFromTXTFile(const string fname) // виведення файлу на екран
{
	string s; // прочитаний рядок

	ifstream fin(fname); // відкрили файл для зчитування
	while (getline(fin, s)) // поки можна прочитати рядок
	{
		cout << s << endl; // виводимо його на екран
	}
	cout << endl;
	fin.close();
}


int main()
{

	string src_fname = "t1.txt"; // ім'я першого файлу
	string dst_fname = "t2.txt"; // ім'я другого файлу

//	PrepareAndSaveTXTFile(src_fname);

	cout << "Content of " << src_fname << " : " << endl;
	PrintFromTXTFile(src_fname);

	ProcessTrim(src_fname, dst_fname);

	cout << "Content of " << dst_fname << " : " << endl;
	PrintFromTXTFile(dst_fname);

	return 0;
}
