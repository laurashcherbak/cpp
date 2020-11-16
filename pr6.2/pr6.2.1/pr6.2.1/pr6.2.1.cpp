#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateArray(int* a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}

void PrintArray(int* a, const int size)
{
	cout << "a[n=" << size << "] = {";
	for (int i = 0; i < size; i++)
		cout << (i > 0 ? ", " : "")  << a[i];
	cout << "}" << endl;
}

void SwapMinMaxInArray(int* a, const int size)
{
	int i_max = 0;
	int i_min = 0;

	for (int i = 1; i < size; i++) {
		if (a[i] > a[i_max]) {
			i_max = i;
		}
		else if (a[i] < a[i_min]) {
			i_min = i;
		}
	}

	cout << "max value = " << a[i_max] << endl;
	cout << "min value = " << a[i_min] << endl;

	int t = a[i_max];
	a[i_max] = a[i_min];
	a[i_min] = t;

}

int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел

	const int n = 10;
	int a[n];
	int Low = -10;
	int High = 10;

	CreateArray(a, n, Low, High);

	PrintArray(a, n);
	cout << endl;

	SwapMinMaxInArray(a, n);
	cout << endl;

	PrintArray(a, n);
	cout << endl;

	return 0;
}