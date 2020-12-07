#include <iostream>
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
	union
	{
		unsigned markProgramming;
		unsigned markNumericalMethods;
		unsigned markPedagogy;
	};
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

void Create(Student* p, const int N)
{
	int specialty;

	for (int i = 0; i < N; i++)
	{
		cout << "Student No " << i + 1 << ":" << endl;
		cout << " Full name: "; cin >> p[i].name;
		p[i].course = GetAndCheckUnsignedValue(" Course (1..5): ", 1, 5);
		specialty = GetAndCheckUnsignedValue(" Specialty (0 - ComputerScience, 1 - Informatics, 2 - MathAndEconomic, 3 - PhysicsAndInformatics, 4 - TrudoveNavchannia): ", 0, 4);
		p[i].specialty = (Specialty)specialty;
		p[i].markPhysics = GetAndCheckUnsignedValue(" mark Physics (1-5): ", 1, 5);
		p[i].markMath = GetAndCheckUnsignedValue(" mark Math (1-5): ", 1, 5);
		if (p[i].specialty == ComputerScience) {
			p[i].markProgramming = GetAndCheckUnsignedValue(" mark Programming (1-5): ", 1, 5);
		}
		else if (p[i].specialty == Informatics) {
			p[i].markNumericalMethods = GetAndCheckUnsignedValue(" mark Numerical Methods (1-5): ", 1, 5);
		}
		else {
			p[i].markPedagogy = GetAndCheckUnsignedValue(" mark Pedagogy (1-5): ", 1, 5);
		}
		cout << endl;
	}
}

void Print(Student* p, const int N, int *I)
{
	cout << "+=================================================================================================================+" << endl;
	cout << "|    |           |        |                         |                              Marks                          |" << endl;
	cout << "| No | Full name | Course |        Specialty        | Physics | Math | Programming | Numerical Methods | Pedagogy |" << endl;
	cout << "+-----------------------------------------------------------------------------------------------------------------+" << endl;
	int i;
	for (int j = 0; j < N; j++)
	{
		i = I ? I[j] : j;
		cout << "| " << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(10) << left << p[i].name
			<< "| " << setw(6) << right << p[i].course << " "
			<< "| " << setw(23) << left << SpecialtyStr[p[i].specialty] << " "
			<< "| " << setw(7) << right << p[i].markPhysics << " "
			<< "| " << setw(4) << right << p[i].markMath << " ";
			if (p[i].specialty == ComputerScience) {
				cout << "| " << setw(11) << right << p[i].markProgramming << " | " << setw(20) << " | " << setw(11) << " | ";
			}
			else if (p[i].specialty == Informatics) {
				cout << "| " << setw(14) << "| " << setw(17) << right << p[i].markNumericalMethods << " | " << setw(11) << " | ";
			}
			else {
				cout << "| " << setw(14) << "| " << setw(20) << "| " << setw(8) << right << p[i].markPedagogy << " | ";
			}
			cout << endl;
	}
	cout << "+=================================================================================================================+" << endl;
	cout << endl;
}

void Sort(Student* p, const int N)
{
	Student t;

	for (int i0 = 0; i0 < N - 1; i0++)
		for (int i1 = 0; i1 < N - i0 - 1; i1++) {
			if (
				(p[i1].course > p[i1 + 1].course)
				|| (
					(p[i1].course == p[i1 + 1].course) &&
					(p[i1].markMath > p[i1 + 1].markMath)
					)
				|| (
					(p[i1].course == p[i1 + 1].course) &&
					(p[i1].markMath == p[i1 + 1].markMath) &&
					(p[i1].name < p[i1 + 1].name)
					)
				)
			{
				t = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = t;
			}
		}
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

int BinSearch(Student* p, const int N, const string name, const unsigned course, const unsigned markMath)
{
	int L = 0, R = N - 1, m;

	do {
		m = (L + R) / 2;

		if (p[m].name == name && p[m].course == course && p[m].markMath == markMath)
			return m;

		if (
			(p[m].course < course) ||
			(p[m].course == course && p[m].markMath < markMath) ||
			(p[m].course == course && p[m].markMath == markMath && p[m].name < name)
			) {
			L = m + 1;
		}
		else {
			R = m - 1;

		}

	} while (L <= R);

	return -1;
}

void Menu()
{
	unsigned course;
	unsigned markMath;
	string name;
	int found;

	int menuItem;

	int N;
	cout << "Input N: "; cin >> N;
	cout << endl;
	Student* p = new Student[N];

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
			Create(p, N);
			break;
		case 2:
			Print(p, N, NULL);
			break;
		case 3:
			Sort(p, N);
			break;
		case 4:
			Print(p, N, IndexSort(p, N));
			break;
		case 5:
			cout << "Enter search keys:" << endl;
			course = GetAndCheckUnsignedValue(" Course (1-5): ", 1, 5);
			markMath = GetAndCheckUnsignedValue(" mark Math (1-5): ", 1, 5);
			cout << " Name: "; cin >> name;
			cout << endl;
			if ((found = BinSearch(p, N, name, course, markMath)) != -1)
				cout << "Found in the index " << found + 1 << endl;
			else
				cout << "Not found" << endl;
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
