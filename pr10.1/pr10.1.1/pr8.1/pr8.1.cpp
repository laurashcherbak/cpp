#ifndef _CRT_SECURE_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
#endif // !#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
//#include <fstream>
#include <string>

using namespace std;

int Count(char* s)
{
	char* t = s;
	int k = 0;

	while ((t = strpbrk(t, "SQ")) != NULL)
	{
		if ((t[0] == 'S' && t[1] == 'Q') || (t[0] == 'Q' && t[1] == 'S')) {
			k++;
		}
		t++;
	}

	return k;
}

int ProcessCount(char* fname)
{
	int pos = 0;
	char s[128]; // прочитаний рядок
	int k = 0; // кількість слів
	FILE* f;

	if ((f = fopen(fname, "r")) != NULL) // відкрили файл для зчитування
	{
		while (!feof(f)) {
			if ((fgets(s, 128, f)) != NULL) {
				k += Count(s);
			}
		}
		fclose(f);
	}

	return k;
}

int Exists(char* s)
{
	char* t = s;

	while ((t = strpbrk(t, "SQ")) != NULL)
	{
		if ((t[0] == 'S' && t[1] == 'Q') || (t[0] == 'Q' && t[1] == 'S')) {
			return 1;
		}
	}

	return 0;
}

int ProcessExists(char* fname)
{
	char s[128]; // прочитаний рядок
	FILE* f;

	if ((f = fopen(fname, "r")) != NULL) // відкрили файл для зчитування
	{
		while (!feof(f)) {
			if ((fgets(s, 128, f)) != NULL) {
				if (Exists(s) > 0) {
					return 1;
				}
			}
		}
		fclose(f);
	}

	return 0;
}

void CreateTXT(char* fname) // створення файлу з введених рядків
{
	char ch; // відповідь користувача – чи продовжувати введення
	char s[128];
	FILE* f;

	if ((f = fopen(fname, "w")) != NULL) // відкрили файл для запису
	{
		do {
				cin.get(); // очищуємо буфер клавіатури – щоб не було символу
				cin.sync(); // "кінець рядка", який залишився після вводу числа
				cout << "enter line: "; cin >> s;// ввели рядок
				strcat(s, "\n"); // добавлення символу нового рядка
				fputs(s, f);
				cout << "continue? (y/n): "; cin >> ch;
		} while (ch == 'y' || ch == 'Y');
		fclose(f);
	}

	cout << endl;
}

void PrintTXT(char* fname) // виведення файлу на екран
{
	char s[128]; // прочитаний рядок
	FILE* f;

	cout << "Context of " << fname << " : " << endl << endl;
	if ((f = fopen(fname, "r")) != NULL) // відкрили файл для зчитування
	{
		while (!feof(f)) {
			if (fgets(s, 128, f)) {
				cout << s; // виводимо його на екран
			}
		}
		fclose(f);
	}

	cout << endl;
}

int main()
{
	// text files
	char fname[128] = "t.txt";
	//cout << "enter file name: "; cin >> fname;

	//CreateTXT(fname);
	PrintTXT(fname);

	//cout << "Found " << ProcessCount(fname) << " symbols 'SQ' or/and 'QS' in " << fname << endl << endl;
	cout << "'SQ' or/and 'QS' symbols " << (ProcessExists(fname) > 0 ? "" : "not ") << "found in " << fname << endl;

	return 0;
}
