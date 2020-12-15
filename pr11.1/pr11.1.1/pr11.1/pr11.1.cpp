#ifndef _CRT_SECURE_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
#endif // !#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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

int Process(char* src_fname, char* dest_fname)
{
	char s[128];
	FILE *fin, *fout;

	if ((fin = fopen(src_fname, "rb")) != NULL) {
		if ((fout = fopen(dest_fname, "wb")) != NULL) {
			while (!feof(fin)) {
				if ((fgets(s, 128, fin)) != NULL) {
					if (CheckStringIsDoubleAndNotEqualsSinX(s) != NULL) {
						fputs(s, fout);
					}
				}
			}
			fclose(fout);
		}
		fclose(fin);
	}

	return 0;
}

void CreateFile(char* fname)
{
	char ch;
	char s[128];
	FILE* f;
	
	if ((f = fopen(fname, "wb")) != NULL) {
		do {
			cout << "enter value for [y=sin(x)] : "; cin >> s;
			strcat(s, "\n");
			fputs(s, f);
			cout << "continue? (y/n) : "; cin >> ch;
		} while (ch == 'y' || ch == 'Y');
		fclose(f);
	}
	cout << endl;
}

void PrintFile(char* fname)
{
	char s[128];
	FILE* f;

	if ((f = fopen(fname, "rb")) != NULL) {
		while (!feof(f)) {
			if (fgets(s, 128, f)) {
				cout << s;
			}
		}
		fclose(f);
	}
	cout << endl;
}

int main()
{
	char src_fname[128] = "source.txt";
	char dest_fname[128] = "result.txt";
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
