#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int n, const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < n - 1)
		Create(a, n, Low, High, i, j + 1);
	else
		if (i < n - 1)
			Create(a, n, Low, High, i + 1, 0);
}

void Print(int** a, const int n, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < n - 1)
		Print(a, n, i, j + 1);
	else
		if (i < n - 1)
		{
			cout << endl;
			Print(a, n, i + 1, 0);
		}
		else
			cout << endl << endl;
}

int Sum(int** a, const int n, int i, int j, int &S)
{
	//cout << a[i][n - i - 1] << endl;
	S += a[i][n - i - 1];
		if (i < n - 1)
			Sum(a, n, i + 1, 0, S);
	return S;
}

int main()
{
	srand((unsigned)time(NULL));

	int Low = 7;
	int High = 65;
	int n;
	cout << "n = "; cin >> n;

	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];

	Create(a, n, Low, High, 0, 0);
	Print(a, n, 0, 0);

	int S = 0;
	cout << "Sum: " << Sum(a, n, 0, 0, S) << endl;

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
