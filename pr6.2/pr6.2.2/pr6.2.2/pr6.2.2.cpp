#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateArray(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		CreateArray(a, size, Low, High, i + 1);
}

void PrintArray(int* a, const int size, int i)
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
	else
		cout << endl;
}

void SwapMinMaxInArray(int* a, const int size, int i, int i_min, int i_max)
{
	if (a[i] > a[i_max]) {
		i_max = i;
	}
	else if (a[i] < a[i_min]) {
		i_min = i;
	}

	if (i < size - 1) {
		SwapMinMaxInArray(a, size, i + 1, i_min, i_max);
	}
	else {
		cout << "max value = " << a[i_max] << endl;
		cout << "min value = " << a[i_min] << endl;

		int t = a[i_max];
		a[i_max] = a[i_min];
		a[i_min] = t;
		cout << endl;
	}

}

int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	const int n = 10;
	int a[n];
	int Low = -10;
	int High = 10;
	CreateArray(a, n, Low, High, 0);
	PrintArray(a, n, 0);

	SwapMinMaxInArray(a, n, 0, 0, 0);

	PrintArray(a, n, 0);

	return 0;
}