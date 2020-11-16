#include <iostream>
#include <time.h>

using namespace std;

void CreateArray(double* a, const int size, const int Low, const int High, int i)
{
	a[i] = ((1. * Low) + rand() % (High - Low + 1)) / 10;
	if (i % 3 == 0)
		a[i] = 0.0;
	if (i < size - 1)
		CreateArray(a, size, Low, High, i + 1);
}

void PrintArray(double* a, const int size, int i)
{
	if (i == 0)
		cout << "a[n=" << size << "] = {";
	if (i > 0)
		cout << ", ";
	cout << a[i];

	if (i == (size - 1))
		cout << "}" << endl;

	if (i < size - 1)
		PrintArray(a, size, i + 1);
}

double GetMinValueFromArray(double* a, const int size, int i, double min)
{
	if (a[i] < min)
		min = a[i];
	if (i < size - 1)
		return GetMinValueFromArray(a, size, i + 1, min);
	else
		return min;
}

double GetMinIndexPositiveValue(double* a, const int size, int i, int iMinPositive)
{
	if (a[i] >= 0)
	{
		if (iMinPositive == -1)
		{
			iMinPositive = i;
		}
		//cout << i << " : " << a[i] << " : " << iMinPositive << " : " << iMaxPositive << endl;
	}
	if (i < size - 1)
		return GetMinIndexPositiveValue(a, size, i + 1, iMinPositive);
	else
		return iMinPositive;

}

double GetMaxIndexPositiveValue(double* a, const int size, int i, int iMaxPositive)
{
	if (a[i] >= 0)
	{
		iMaxPositive = i;
		//cout << i << " : " << a[i] << " : " << iMinPositive << " : " << iMaxPositive << endl;
	}
	if (i < size - 1)
		return GetMaxIndexPositiveValue(a, size, i + 1, iMaxPositive);
	else
		return iMaxPositive;
}

double GetSumPositiveValues(double* a, int iMinPositive, int iMaxPositive, int i) // ітераційний спосіб
{
	double s = 0.;

	if (i > iMinPositive && i < iMaxPositive)
	{
		s = a[i];
	}

	if (i > 0)
	{
		s += GetSumPositiveValues(a, iMinPositive, iMaxPositive, i - 1);
	}

	return s;
}

void RearrangementArray(double* a, const int size, int i)
{
	if ( i == 0)
		cout << "Rearrangement Array ..." << endl;

	for (int j = 0; j < size - i; j++) {// номер поточного елемента
		if ((a[j] != a[j + 1]) && (a[j + 1] == 0)) // якщо порушено умову впорядкування
		{ // - обмін елементів місцями
			double tmp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = tmp;
		}
	}
	if (i < size - 1) // i - лічильник ітерацій
		RearrangementArray(a, size, i + 1);
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
	CreateArray(a, k, Low, High, 0);

	PrintArray(a, k, 0);

	cout << "Min value = " << GetMinValueFromArray(a, k, 1, a[0]) << endl;

	int iMinPositive = GetMinIndexPositiveValue(a, k, 0, -1);
	int iMaxPositive = GetMaxIndexPositiveValue(a, k, 0, -1);
	cout << "Sum positive values = " << GetSumPositiveValues(a, iMinPositive, iMaxPositive, k -1) << endl;

	RearrangementArray(a, k, 0);

	PrintArray(a, k, 0);
	
	delete[] a;

	return 0;
}
