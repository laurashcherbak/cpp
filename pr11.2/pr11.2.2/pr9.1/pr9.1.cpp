﻿#include <iostream>
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

void CreateFile(const string filename)
{
	bool res = false;
	int specialty;
	int N;

	cout << "Input N: "; cin >> N;
	Student* p = new Student[N];

	ofstream fout(filename, ios::binary); // відкрили бінарний файл зчитування
	fout.write((char*)&N, sizeof(N)); // прочитали кількість елементів

	//p[0] = { "Ivanov", 5, ComputerScience, 4, 3, 5 };
	//fout.write((char*)&p[0], sizeof(Student)); // прочитали елементи масиву
	//p[1] = { "Petrov", 4, Informatics, 4, 4, 5 };
	//fout.write((char*)&p[1], sizeof(Student)); // прочитали елементи масиву
	//p[2] = { "Bulba", 3, MathAndEconomic, 5, 3, 5 };
	//fout.write((char*)&p[2], sizeof(Student)); // прочитали елементи масиву
	//p[3] = { "Ivanova", 2, PhysicsAndInformatics, 5, 4, 5 };
	//fout.write((char*)&p[3], sizeof(Student)); // прочитали елементи масиву
	//p[4] = { "Petrova", 1, TrudoveNavchannia, 3, 3, 3 };
	//fout.write((char*)&p[4], sizeof(Student)); // прочитали елементи масиву

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
		fout.write((char*)&p[i], sizeof(Student)); // прочитали елементи масиву
	}

	fout.close(); // закрили файл
}

void PrintFile(const string filename)
{
	int N;

	ifstream fin(filename, ios::binary); // відкрили бінарний файл зчитування
	fin.read((char*)&N, sizeof(N)); // прочитали кількість елементів
	Student* p = new Student[N];

	cout << "+=================================================================================================================+" << endl;
	cout << "|    |           |        |                         |                              Marks                          |" << endl;
	cout << "| No | Full name | Course |        Specialty        | Physics | Math | Programming | Numerical Methods | Pedagogy |" << endl;
	cout << "+-----------------------------------------------------------------------------------------------------------------+" << endl;
	for (int i = 0; i < N; i++)
	{
		fin.read((char*)&p[i], sizeof(Student)); // прочитали елементи масиву
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

	fin.close(); // закрили файл
}

int IsGoodStudent(Student p)
{
	if (((p.markPhysics == 4) || (p.markPhysics == 5))
		&& ((p.markMath == 4) || (p.markMath == 5))
		&& ((p.markProgramming == 4) || (p.markProgramming == 5))
		&& ((p.markNumericalMethods == 4) || (p.markNumericalMethods == 5))
		&& ((p.markPedagogy == 4) || (p.markPedagogy == 5))
		)
		return 1;
	return 0;
}

int PercentOfGoodStudent(const string filename)
{
	int r = 0;
	int N;

	ifstream fin(filename, ios::binary);
	fin.read((char*)&N, sizeof(N));
	Student* p = new Student[N];

	for (int i = 0; i < N; i++) {
		fin.read((char*)&p[i], sizeof(Student));
		r += IsGoodStudent(p[i]);
	}
	fin.close();

	return ((1.0 * r / N) * 100);
}

void PrintGoodStudent(const string filename)
{
	int N;

	ifstream fin(filename, ios::binary);
	fin.read((char*)&N, sizeof(N));
	Student* p = new Student[N];

	cout << "Good students :" << endl;
	for (int i = 0; i < N; i++) {
		fin.read((char*)&p[i], sizeof(Student));
		if (((p[i].markPhysics == 4) || (p[i].markPhysics == 5))
			//&& ((p[i].markMath == 4) || (p[i].markMath == 5))
			//&& ((p[i].markProgramming == 4) || (p[i].markProgramming == 5))
			//&& ((p[i].markNumericalMethods == 4) || (p[i].markNumericalMethods == 5))
			//&& ((p[i].markPedagogy == 4) || (p[i].markPedagogy == 5))
			)
		{
			cout << p[i].name << endl;
		}
	}
	fin.close();
}

int main()
{
	string filename;

	cout << "Input file name: "; cin >> filename;
	cout << endl;

	CreateFile(filename);
	PrintFile(filename);
	cout << "Percent : " << PercentOfGoodStudent(filename) << " %" << endl;
	PrintGoodStudent(filename);


	return 0;
}
