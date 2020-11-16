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

int PrintValue(int* a, const int size, int i)
{
	if (i == 0)
		cout << "Print values in function" << endl;
	cout << "a[" << setw(2) << i << "] = " << setw(4) << a[i] << endl;
	if (i < size - 1)
		PrintValue(a, size, i + 1);
	else
		cout << endl;

	return 0;
}

template <typename T> // шаблон функції
T PrintTValue(T* a, const T size, T i)
{
	if (i == 0)
		cout << "Print values in template function" << endl;
	cout << "a[" << setw(2) << i << "] = " << setw(4) << a[i] << endl;
	if (i < size - 1)
		PrintValue(a, size, i + 1);
	else
		cout << endl;

	return 0;
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

	PrintValue(a, n, 0);

	PrintTValue(a, n, 0);

	PrintArray(a, n, 0);

	return 0;
}