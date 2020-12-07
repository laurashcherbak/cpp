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
		if (p[i].specialty == ComputerScience) {
			cout << " mark Programming: "; cin >> p[i].markProgramming;
		}
		else if (p[i].specialty == Informatics) {
			cout << " mark Numerical Methods: "; cin >> p[i].markNumericalMethods;
		}
		else {
			cout << " mark Pedagogy: "; cin >> p[i].markPedagogy;
		}

		cout << endl;
	}
}

void Print(Student* p, const int N)
{
	cout << "+=================================================================================================================+" << endl;
	cout << "|    |           |        |                         |                              Marks                          |" << endl;
	cout << "| No | Full name | Course |        Specialty        | Physics | Math | Programming | Numerical Methods | Pedagogy |" << endl;
	cout << "+-----------------------------------------------------------------------------------------------------------------+" << endl;
	for (int i = 0; i < N; i++)
	{
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

int PercentOfGoodStudent(Student* p, const int N)
{
	int r = 0;

	for (int i = 0; i < N; i++)
	{
		if (((p[i].markPhysics == 4) || (p[i].markPhysics == 5))
			&& ((p[i].markMath == 4) || (p[i].markMath == 5))
			&& ((p[i].markProgramming == 4) || (p[i].markProgramming == 5))
			&& ((p[i].markNumericalMethods == 4) || (p[i].markNumericalMethods == 5))
			&& ((p[i].markPedagogy == 4) || (p[i].markPedagogy == 5))
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
			&& ((p[i].markProgramming == 4) || (p[i].markProgramming == 5))
			&& ((p[i].markNumericalMethods == 4) || (p[i].markNumericalMethods == 5))
			&& ((p[i].markPedagogy == 4) || (p[i].markPedagogy == 5))
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
