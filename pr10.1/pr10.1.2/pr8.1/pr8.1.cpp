#ifndef _CRT_SECURE_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
#endif // !#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int Count(const string s)
{
	int k = 0;
	size_t pos = 0;

	while ((pos = s.find("SQ", pos)) != -1) {
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

int ProcessCount(const string fname)
{
	ifstream fin(fname); // відкрили файл для зчитування
	string s; // прочитаний рядок
	int k = 0; // кількість слів
	while (getline(fin, s)) // поки можна прочитати рядок
	{
		k += Count(s);
	}

	fin.close();
	return k;
}

int Exists(const string s)
{
	size_t pos = 0;

	while ((pos = s.find("SQ", pos)) != -1) {
		return 1;
	}

	pos = 0;
	while ((pos = s.find("QS", pos)) != -1) {
		return 1;
	}
	return 0;
}

int ProcessExists(const string fname)
{
	ifstream fin(fname); // відкрили файл для зчитування
	string s; // прочитаний рядок
	while (getline(fin, s)) // поки можна прочитати рядок
	{
		if (Exists(s) > 0) {
			return 1;
		}
	}

	fin.close();
	return 0;
}

void CreateTXT(const string fname) // створення файлу з введених рядків
{
	ofstream fout(fname); // відкрили файл для запису
	char ch; // відповідь користувача – чи продовжувати введення
	string s; // введений користувачем рядок
	do
	{
		cin.get(); // очищуємо буфер клавіатури – щоб не було символу
		cin.sync(); // "кінець рядка", який залишився після вводу числа
		cout << "enter line: "; cin >> s;//getline(cin, s); // ввели рядок
		fout << s << endl; // записали його у файл
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
	fout.close();
}

void PrintTXT(const string fname) // виведення файлу на екран
{
	cout << "Context of " << fname << " : " << endl << endl;
	ifstream fin(fname); // відкрили файл для зчитування
	string s; // прочитаний рядок
	while (getline(fin, s)) // поки можна прочитати рядок
	{
		cout << s << endl; // виводимо його на екран
	}
	cout << endl;
	fin.close();
}

int main()
{
	string fname = "t.txt"; // ім'я першого файлу
	//cout << "enter file name: "; cin >> fname;

	//CreateTXT(fname); // ввели рядки файлу з клавіатури
	PrintTXT(fname); // вивели вміст першого файлу на екран

	//cout << "Found " << ProcessCount(fname) << " symbols 'SQ' or/and 'QS' in " << fname << endl << endl;
	cout << "'SQ' or/and 'QS' symbols " << (ProcessExists(fname) > 0 ? "" : "not ") << "found in " << fname << endl;

	return 0;
}
