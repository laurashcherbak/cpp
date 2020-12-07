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
	unsigned markInformatics;
};

void Create(Student* p, const int N)
{
	int specialty;

	for (int i = 0; i < N; i++)
	{
		cout << "Student No " << i + 1 << ":" << endl;
		cout << " Full name: "; cin >> p[i].name;
		cout << " Course: "; cin >> p[i].course;
		cout << " Specialty (0 - ComputerScience, 1 - Informatics, 2 - MathAndEconomic, 3 - PhysicsAndInformatics, 4 - TrudoveNavchannia): "; cin >> specialty;
		p[i].specialty = (Specialty)specialty;
		cout << " mark Physics: "; cin >> p[i].markPhysics;
		cout << " mark Math: "; cin >> p[i].markMath;
		cout << " mark Informatics: "; cin >> p[i].markInformatics;
		cout << endl;
	}
}

void Print(Student* p, const int N)
{
	cout << "+==================================================================================+" << endl;
	cout << "|    |           |        |                         |          Marks               |" << endl;
	cout << "| No | Full name | Course |        Specialty        | Physics | Math | Informatics |" << endl;
	cout << "+----------------------------------------------------------------------------------+" << endl;
	for (int i = 0; i < N; i++)
	{
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
}

int PercentOfGoodStudent(Student* p, const int N)
{
	int r = 0;

	for (int i = 0; i < N; i++)
	{
		if (((p[i].markPhysics == 4) || (p[i].markPhysics == 5))
			&& ((p[i].markMath == 4) || (p[i].markMath == 5))
			&& ((p[i].markInformatics == 4) || (p[i].markInformatics == 5))
			)
		{
			r++;
		}
	}

	return ((1.0 * r / N) * 100);
}

void PrintGoodStudent(Student* p, const int N)
{
	cout << "Good students :" << endl;
	for (int i = 0; i < N; i++)
	{
		if (((p[i].markPhysics == 4) || (p[i].markPhysics == 5))
			&& ((p[i].markMath == 4) || (p[i].markMath == 5))
			&& ((p[i].markInformatics == 4) || (p[i].markInformatics == 5))
			)
		{
			cout << p[i].name << endl;
		}
	}
}

int main()
{
	int N;

	cout << "Input N: "; cin >> N;
	cout << endl;

	Student* p = new Student[N];

	Create(p, N);
	Print(p, N);
	cout << "Percent : " << PercentOfGoodStudent(p, N) << " %" << endl;
	PrintGoodStudent(p, N);

	return 0;
}
