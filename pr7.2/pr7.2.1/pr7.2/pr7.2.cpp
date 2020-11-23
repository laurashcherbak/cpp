#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int Sum(int** a, const int n)
{
	int S = 0;
	for (int i = 0; i < n; i++) {
		S += a[i][n - i - 1];
		//int j = 0;
		//for (j = n - 1 - i; j < n; j++) {
		//	S += a[i][j];
		//	break;
		//}
	}
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

	Create(a, n, Low, High);
	Print(a, n);

	cout << "Sum: " << Sum(a, n) << endl;

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
