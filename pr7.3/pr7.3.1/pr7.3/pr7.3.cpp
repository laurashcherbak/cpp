#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Input(int** a, const int rowCount, const int colCount)
{
		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++)
			{
				cout << "a[" << i << "][" << j << "] = ";
				cin >> a[i][j];
			}
			cout << endl;
		}
}

void Print(int** a, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

long Part1_Sum(int** a, const int rowCount, const int colCount)
{
	long s = 0;
	long s_row;
	int k_negative;
	for (int i = 0; i < rowCount; i++)
	{
		s_row = 0;
		k_negative = 0;
		for (int j = 0; j < colCount; j++) {
			if (a[i][j] < 0)
			{
				k_negative++;
			}
			s_row += a[i][j];
		}
		if (k_negative > 0)
		{
			s += s_row;
		}
	}
	return s;
}

bool IsMaxInRowN(int** a, const int n, const int k, const int colCount)
{
	for (int j = 0; j < colCount; j++)
		if (a[n][j] > a[n][k])
		{
			return false;
		}
	return true;
}

bool IsMinInColK(int** a, const int n, const int k, const int rowCount)
{
	for (int i = 0; i < rowCount; i++)
		if (a[i][k] < a[n][k])
		{
			return false;
		}
	return true;
}

void Part2_SaddlePoint(int** a, const int rowCount, const int colCount)
{
	cout << "Saddle points: max in row & min in col" << endl;
	cout << setw(4) << "No" << setw(6) << "Row" << setw(6) << "Col" << endl;
	int No = 0;
	for (int n = 0; n < rowCount; n++)
		for (int k = 0; k < colCount; k++)
			if (IsMaxInRowN(a, n, k, colCount) && IsMinInColK(a, n, k, rowCount))
			{
				cout << setw(4) << ++No << setw(6) << n << setw(6) << k << endl;
			}
}


int main()
{
	srand((unsigned)time(NULL));

	int Low = -17;
	int High = 15;
	int rowCount, colCount;
	char t;

	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	cout << endl;
	cout << "Would you like to enter data for array manually (y/n): "; cin >> t;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	if (t == 'y')
		Input(a, rowCount, colCount);
	else
		Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);

	cout << "sum = " << Part1_Sum(a, rowCount, colCount) << endl;
	cout << endl;

	Part2_SaddlePoint(a, rowCount, colCount);

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}
