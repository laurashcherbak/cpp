#include <iostream>
#include <time.h>

using namespace std;

void CreateArray(double* a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++) {
		if (i % 3 == 0)
			a[i] = 0.0;
		else
			a[i] = ((1. * Low) + rand() % (High - Low + 1)) / 10;
	}
}

void PrintArray(double* a, const int size)
{
	cout << "a[n=" << size << "] = {";
	for (int i = 0; i < size; i++)
		cout << (i > 0 ? ", " : "") << a[i];
	cout << "}" << endl;
}

double GetMinValueFromArray(double* a, const int size)
{
	double min = a[0];
	for (int i = 1; i < size; i++)
		if (a[i] < min)
			min = a[i];
	return min;
}

double GetMinIndexPositiveValue(double* a, const int size)
{
	int iMinPositive = -1;
	for (int i = 0; i < size; i++)
	{
		if (a[i] >= 0)
		{
			if (iMinPositive == -1)
			{
				iMinPositive = i;
			}
		}
	}
	return iMinPositive;
}

double GetMaxIndexPositiveValue(double* a, const int size)
{
	int iMaxPositive = -1;
	for (int i = 0; i < size; i++)
	{
		if (a[i] >= 0)
		{
			iMaxPositive = i;
		}
	}
	return iMaxPositive;
}

double GetSumPositiveValues(double* a, int iMinPositive, int iMaxPositive) // ітераційний спосіб
{
	double s = 0.;
	if (iMinPositive + 1 < iMaxPositive)
		for (int i = iMinPositive + 1; i < iMaxPositive; i++)
		{
			s += a[i];
		}
	return s;
}

void RearrangementArray(double* a, const int size)
{
	cout << "Rearrangement Array ..." << endl;
	for (int i = 1; i < size; i++) {// лічильник ітерацій
		for (int j = 0; j < size - i; j++) {// номер поточного елемента
			if ((a[j] != a[j + 1]) && (a[j + 1] == 0)) // якщо порушено умову впорядкування
			{ // - обмін елементів місцями
				double tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел

	int k = 100; // кількість елементів
	cout << "Enter k: ";
	cin >> k;

	double* a = new double[k]; // p - вказівник на динамічний масив

	int Low = -100.;
	int High = 100.;
	CreateArray(a, k, Low, High);

	PrintArray(a, k);

	cout << "Min value = " << GetMinValueFromArray(a, k) << endl;

	int iMinPositive = GetMinIndexPositiveValue(a, k);
	int iMaxPositive = GetMaxIndexPositiveValue(a, k);
	cout << "Sum positive values = " << GetSumPositiveValues(a, iMinPositive, iMaxPositive) << endl;

	RearrangementArray(a, k);

	PrintArray(a, k);
	
	delete[] a;

	return 0;
}
