#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

enum Specialty { ComputerScience, Informatics, MathAndEconomic, PhysicsAndInformatics, TrudoveNavchannia};

string SpecialtyStr[] = { "ComputerScience", "Informatics", "Math And Economic", "Physics And Informatics", "Trudove Navchannia" };

struct Student
{
	string name;
	unsigned course;
	Specialty specialty;
	unsigned markPhysics;
	unsigned markMath;
	unsigned markInformatics;
};

unsigned GetAndCheckUnsignedValue(string s, unsigned minVal, unsigned maxVal)
{
	unsigned t;
	bool e;
	e = true;

	while (e) {
		cout << s; cin >> t;

		if (cin.fail())
			e = true;
		else if (t < minVal || t > maxVal)
			e = true;
		else
			e = false;

		if (e) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Error: Incorrect value. Please enter again." << endl;
		}
	}

	return t;
}

void CreateFile(const string filename, const int& N)
{
	bool res = false;
	int specialty;
	//int N;
	//cout << "Input N: "; cin >> N;
	Student* p = new Student[N];

	ofstream fout(filename, ios::binary); // відкрили бінарний файл зчитування
	//fout.write((char*)&N, sizeof(N)); // прочитали кількість елементів

	p[0] = { "Ivanov", 5, ComputerScience, 4, 3, 5 };
	fout.write((char*)&p[0], sizeof(Student)); // прочитали елементи масиву
	p[1] = { "Petrov", 4, Informatics, 4, 4, 5 };
	fout.write((char*)&p[1], sizeof(Student)); // прочитали елементи масиву
	p[2] = { "Bulba", 3, MathAndEconomic, 5, 3, 5 };
	fout.write((char*)&p[2], sizeof(Student)); // прочитали елементи масиву
	p[3] = { "Ivanova", 2, PhysicsAndInformatics, 5, 4, 5 };
	fout.write((char*)&p[3], sizeof(Student)); // прочитали елементи масиву
	p[4] = { "Petrova", 1, TrudoveNavchannia, 3, 3, 3 };
	fout.write((char*)&p[4], sizeof(Student)); // прочитали елементи масиву
	//p[5] = { "Petrovka", 2, TrudoveNavchannia, 3, 3, 3 };
	//fout.write((char*)&p[5], sizeof(Student)); // прочитали елементи масиву

	//for (int i = 0; i < N; i++)
	//{
	//	cout << "Student No " << i + 1 << ":" << endl;
	//	cout << " Full name: "; cin >> p[i].name;
	//	cout << " Course: "; cin >> p[i].course;
	//	cout << " Specialty (0 - ComputerScience, 1 - Informatics, 2 - MathAndEconomic, 3 - PhysicsAndInformatics, 4 - TrudoveNavchannia): "; cin >> specialty;
	//	p[i].specialty = (Specialty)specialty;
	//	cout << " mark Physics: "; cin >> p[i].markPhysics;
	//	cout << " mark Math: "; cin >> p[i].markMath;
	//	cout << " mark Informatics: "; cin >> p[i].markInformatics;
	//	cout << endl;
	//	fout.write((char*)&p[i], sizeof(Student)); // прочитали елементи масиву
	//}

	fout.close(); // закрили файл
	//delete[] p; // знищили попередні дані
}

void PrintFile(const string filename, int* I, const int& N)
{
	//int N;
	ifstream fin(filename, ios::binary); // відкрили бінарний файл зчитування
	//fin.read((char*)&N, sizeof(N)); // прочитали кількість елементів
	Student* p = new Student[N]; // створили динамічний масив

	cout << "+==================================================================================+" << endl;
	cout << "|    |           |        |                         |          Marks               |" << endl;
	cout << "| No | Full name | Course |        Specialty        | Physics | Math | Informatics |" << endl;
	cout << "+----------------------------------------------------------------------------------+" << endl;
	int i;
	for (int j = 0; j < N; j++)
	{
		i = I ? I[j] : j;
		fin.read((char*)&p[i], sizeof(Student)); // прочитали елементи масиву

		cout << "| " << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(10) << left << p[i].name
			<< "| " << setw(6) << right << p[i].course << " "
			<< "| " << setw(23) << left << SpecialtyStr[p[i].specialty] << " "
			<< "| " << setw(7) << right << p[i].markPhysics << " "
			<< "| " << setw(4) << right << p[i].markMath << " "
			<< "| " << setw(11) << right << p[i].markInformatics << " "
			<< "| " << endl;
	}
	cout << "+==================================================================================+" << endl;
	cout << endl;

	fin.close(); // закрили файл
}

void Sort(const string fname, const int& N)
{
	Student p0;
	Student p1;

	fstream f(fname, ios::binary | ios::in | ios::out);
	// обов'язково слід вказати режими
	// ios::binary | ios::in | ios::out
	// - бінарний файл, для якого
	// одночасно доступні операції
	// - зчитування та
	// - запису

	//f.seekg(0, ios::end);
	//int size = f.tellg();
	f.seekg(0, ios::beg);
	//f.seekg(0 * (long)sizeof(N));
	//f.read((char*)&N, sizeof(N)); // прочитали кількість елементів

	for (int i0 = 0; i0 < N - 0; i0++) {
		for (int i1 = 0; i1 < N - i0 - 0; i1++) {
			f.seekg(0 + (i0 * (long)sizeof(Student))); // встановили вказівник
			f.read((char*)&p0, sizeof(Student)); // прочитали значення
			f.seekg(0 + ((i1 + 0) * (long)sizeof(Student))); // встановили вказівник
			f.read((char*)&p1, sizeof(Student)); // прочитали значення
			if (
				(p0.course > p1.course)
				|| (
					(p0.course == p1.course) &&
					(p0.markMath > p1.markMath)
					)
				|| (
					(p0.course == p1.course) &&
					(p0.markMath == p1.markMath) &&
					(p0.name < p1.name)
					)
				) {
				//cout << p0.name << endl;
				//cout << p1.name << endl;
				f.seekp(0 + (i0 * (long)sizeof(Student))); // встановили вказівник
				f.write((char*)&p1, sizeof(Student)); // записали значення
				f.seekp(0 + (i1 * (long)sizeof(Student))); // встановили вказівник
				f.write((char*)&p0, sizeof(Student)); // записали значення
			}
		}
		f.seekp(0, ios::end);
		f.close();
	}
}

void SortBIN(const string fname, const int& N)
{
	Student t;
	Student p0;
	Student p1;
	
	fstream f(fname, ios::binary | ios::in | ios::out);
	for (int i0 = 1; i0 < N - 1; i0++)
	{
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
		{
			f.open(fname, ios::binary | ios::in | ios::out);
			int l, m;
			l = i1;
			m = i1 + 2;
			while (l < m)
			{
				f.seekg(l * sizeof(Student), ios::beg);
				f.read((char*)&t, sizeof(Student));
				if (l == m - 2)
					p0 = t;
				else
					p1 = t;
				l++;
			}

			if (
				(p0.course > p1.course)
				|| (
					(p0.course == p1.course) &&
					(p0.markMath > p1.markMath)
					)
				|| (
					(p0.course == p1.course) &&
					(p0.markMath == p1.markMath) &&
					(p0.name < p1.name)
					)
				)
			{
				l = i1;
				while (l < m)
				{
					if (l == m - 2)
						t = p1;
					else
						t = p0;
					f.seekp(l * sizeof(Student), ios::beg);
					f.write((char*)&t, sizeof(Student));
					l++;
				}
			}
		}
	}
	f.close();
}

int* IndexSort(Student* p, const int N)
{
	int* I = new int[N];

	for (int i = 0; i < N; i++)
		I[i] = i;

	int i, j, t;
	
	for (i = 1; i < N; i++)
	{
		t = I[i];

		for (j = i - 1;
			j >= 0 && (
						(p[I[j]].course > p[t].course)
						|| (
							(p[I[j]].course == p[t].course) &&
							(p[I[j]].markMath > p[t].markMath)
							)
						|| (
							(p[I[j]].course == p[t].course) &&
							(p[I[j]].markMath == p[t].markMath) &&
							(p[I[j]].name > p[t].name)
							)
						);
			j--)
		{
			I[j + 1] = I[j];
		}
		I[j + 1] = t;
	}

	return I;
}

int BinSearch(const string name, const unsigned course, const unsigned markMath, const string fname)
{
	int N;

	fstream f(fname, ios::binary | ios::in | ios::out);
	f.read((char*)&N, sizeof(N)); // прочитали кількість елементів

	Student p;
	int L = 0, R = N - 1, m;

	do {
		m = (L + R) / 2;
		f.open(fname, ios::binary);
		f.seekg(m * sizeof(Student), ios::beg);
		f.read((char*)&p, sizeof(Student));


		if (p.name == name && p.course == course && p.markMath == markMath)
			return m;

		if (
			(p.course < course) ||
			(p.course == course && p.markMath < markMath) ||
			(p.course == course && p.markMath == markMath && p.name < name)
			) {
			L = m + 1;
			//R = m - 1;
			cout << "-";
		}
		else {
			R = m - 1;
			//L = m + 1;
			cout << "+";

		}

	} while (L <= R);
	f.close();

	return -1;
}

void Menu()
{
	unsigned course;
	unsigned markMath;
	string name;
	int found;

	int menuItem;

	//int N;
	//cout << "Input N: "; cin >> N;
	//cout << endl;
	//Student* p = new Student[N];

	string filename;
	int N;

	cout << "Input file name: "; cin >> filename;
	cout << "Input N: "; cin >> N;
	cout << endl;

	do {
		cout << endl << endl << endl;
		cout << "Select an action:" << endl << endl;
		cout << " [1] - enter data" << endl;
		cout << " [2] - output data" << endl;
		cout << " [3] - sort" << endl;
		cout << " [4] - index ordering and output data" << endl;
		cout << " [5] - binary search" << endl;
		cout << " [0] - exit" << endl << endl;
		cout << "Enter a number: "; cin >> menuItem;
		cout << endl << endl << endl;

		switch (menuItem)
		{
		case 1:
			CreateFile(filename, N);
			break;
		case 2:
			PrintFile(filename, NULL, N);
			break;
		case 3:
			Sort(filename, N);
			break;
		//case -3:
		//	SortBIN(filename, N);
		//	break;
		case 4:
			//PrintFile(filename, IndexSort(p, N));
			break;
		case 5:
			cout << "Enter search keys:" << endl;
			cout << " Name: "; cin >> name;
			course = GetAndCheckUnsignedValue(" Course (1-5): ", 1, 5);
			markMath = GetAndCheckUnsignedValue(" mark Math (1-5): ", 1, 5);
			cout << endl;
			if ((found = BinSearch(name, course, markMath, filename)) != -1)
				cout << "Found in the index " << found + 1 << endl;
			else
				cout << "Not found" << endl;
			cout << "BinSearch : " << found << endl;
			break;
		case 0:
			break;
		default:
			cout << "You have entered an incorrect value! "
				"You must enter the number - the number of the selected menu item" << endl;
		}

	} while (menuItem != 0);
}

int main()
{
	Menu();

	return 0;
}
