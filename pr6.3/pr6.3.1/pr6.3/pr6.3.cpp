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
		cout << (i > 0 ? ", " : "") << a[i];
	cout << "}" << endl;
	cout << endl;
}

int PrintValue(int* a, const int size)
{
	cout << "Print values in function" << endl;
	for (int i = 0; i < size; i++)
		cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
	cout << endl;

	return 0;
}

template <typename T> // шаблон функції
T PrintTValue(T* a, const T size)
{
	cout << "Print values in template function" << endl;
	for (int i = 0; i < size; i++)
		cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
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

	CreateArray(a, n, Low, High);
	
	PrintArray(a, n);

	PrintValue(a, n);

	PrintTValue(a, n);

	PrintArray(a, n);

	return 0;
}