#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void InputRow(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << "a[" << rowNo << "][" << colNo << "] = ";
	cin >> a[rowNo][colNo];
	if (colNo < colCount - 1)
		InputRow(a, rowNo, colCount, colNo + 1);
	else
		cout << endl;
}

void InputRows(int** a, const int rowCount, const int colCount, int rowNo)
{
	InputRow(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		InputRows(a, rowCount, colCount, rowNo + 1);
	else
		cout << endl;
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}

void Part1_CountNegative(int** a, const int colCount, int j, int i, int& k_negative)
{
	if (a[i][j] < 0)
	{
		k_negative++;
	}
	else
		if (j < colCount - 1)
			Part1_CountNegative(a, colCount, j + 1, i, k_negative);
}

void Part1_SumRow(int** a, const int colCount, int& s, int j, int i)
{
	//if (a[i][i] > 0)
		s += a[i][j];
	if (j < colCount - 1)
		Part1_SumRow(a, colCount, s, j + 1, i);
}

int Part1_SumRows(int** a, const int rowCount, const int colCount, int& s, int i)
{
	int k_negative = 0;
	Part1_CountNegative(a, colCount, 0, i, k_negative);
	if (k_negative > 0)
		Part1_SumRow(a, colCount, s, 0, i);
	if (i < rowCount - 1)
		Part1_SumRows(a, rowCount, colCount, s, i + 1);
	return s;
}

bool IsMaxInRowN(int** a, const int rowNo, const int max, const int colCount,
	int colNo)
{
	if (a[rowNo][colNo] > max)
		return false;
	if (colNo < colCount - 1)
		return IsMaxInRowN(a, rowNo, max, colCount, colNo + 1);
	else
		return true;
}

bool IsMinInColK(int** a, const int colNo, const int min, const int rowCount, int rowNo)
{
	if (a[rowNo][colNo] < min)
		return false;
	if (rowNo < rowCount - 1)
		return IsMinInColK(a, colNo, min, rowCount, rowNo + 1);
	else
		return true;
}

void Part2_SaddlePointRow(int** a, const int rowCount, const int colCount, int& No, const int rowNo, int colNo)
{
	if (IsMaxInRowN(a, rowNo, a[rowNo][colNo], colCount, 0) &&
		IsMinInColK(a, colNo, a[rowNo][colNo], rowCount, 0))
	{
		cout << setw(4) << ++No << setw(6) << rowNo << setw(6) << colNo << endl;
	}
	if (colNo < colCount - 1)
		Part2_SaddlePointRow(a, rowCount, colCount, No, rowNo, colNo + 1);
}

void Part2_SaddlePointRows(int** a, const int rowCount, const int colCount, int& No, int rowNo)
{
	Part2_SaddlePointRow(a, rowCount, colCount, No, rowNo, 0);
	if (rowNo < rowCount - 1)
		Part2_SaddlePointRows(a, rowCount, colCount, No, rowNo + 1);
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
		InputRows(a, rowCount, colCount, 0);
	else
		Create(a, rowCount, colCount, Low, High, 0, 0);
	Print(a, rowCount, colCount, 0, 0);
	
	int s = 0;
	s = Part1_SumRows(a, rowCount, colCount, s, 0);
	cout << "sum = " << s << endl;
	cout << endl;
	
	int No = 0;
	cout << "Saddle points: max in row & min in col" << endl;
	cout << setw(4) << "No" << setw(6) << "Row" << setw(6) << "Col" << endl;
	Part2_SaddlePointRows(a, rowCount, colCount, No, 0);
	cout << endl;
	
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}
