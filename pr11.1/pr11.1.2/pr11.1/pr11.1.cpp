#ifndef _CRT_SECURE_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
#endif // !#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double CheckStringIsDoubleAndNotEqualsSinX(char* s)
{
	//sin(x) in range [-1, 1]
	if ((atof(s) < -1.) || (atof(s) > 1.))
		return atof(s);
	else
		return NULL;
}

int Process(const string src_fname, const string dest_fname)
{
	char s[128];

	ifstream fin(src_fname, ios::binary);
	ofstream fout(dest_fname, ios::binary);
	while (fin.read((char*)&s, sizeof(s))) {
		if (CheckStringIsDoubleAndNotEqualsSinX(s) != NULL) {
			fout.write((char*)&s, sizeof(s));
		}
	}
	fout.close();
	fin.close();

	return 0;
}

void CreateFile(const string fname)
{
	char ch;
	char s[128];

	ofstream fout(fname, ios::binary);
	do {
		cout << "enter value for [y=sin(x)] : "; cin >> s;
		fout.write((char*)&s, sizeof(s));
		cout << "continue? (y/n) : "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	fout.close();
	cout << endl;
}

void PrintFile(const string fname)
{
	char s[128];
	ifstream fin(fname, ios::binary);
	int i = 0;
	while(fin.read((char*)&s, sizeof(s))) {
		cout << s << endl;
	}
	fin.close();
	cout << endl;
}

int main()
{
	string src_fname = "source.txt";
	string dest_fname = "result.txt";
	cout << "enter source file name: "; cin >> src_fname;
	cout << "enter result file name: "; cin >> dest_fname;

	CreateFile(src_fname);
	cout << "Source file : " << endl;
	PrintFile(src_fname);
	Process(src_fname, dest_fname);
	cout << "Result file : " << endl;
	PrintFile(dest_fname);

	return 0;
}
