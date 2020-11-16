#include <iostream>
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
	//cout << endl << "i = " << i << "; a[i] = " << a[i];
	if (i == (size - 1))
		cout << "}" << endl;

	if (i < size - 1)
		PrintArray(a, size, i + 1);
	//else
	//	cout << endl;
}

int GetSum(int* a, const int i) // рекурсивний спосіб
{
	int s = 0;

	if ((a[i] >= 0) && (i % 5 != 0)) {
		s = a[i];
		//cout << i << " - " << a[i] << endl;
	}

	if (i > 0) {
		s += GetSum(a, i - 1);
	}

	return s;
}

int GetAmount(int* a, const int i) // рекурсивний спосіб
{
	int am = 0;

	if ((a[i] >= 0) && (i % 5 != 0)) {
		am++;
		//cout << i << " - " << a[i] << endl;
	}

	if (i > 0) {
		am += GetAmount(a, i - 1);
	}

	return am;
}

void Set0(int* a, const int size, int i)
{
	if (i < size) {
		if ((a[i] >= 0) && (i % 5 != 0)) {
			a[i] = 0;
			//cout << i << " - " << a[i] << endl;
		}
		Set0(a, size, i + 1);
	}
}

int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел

	const int k = 20; // кількість елементів масиву

	int a[k]; // оголосили масив

	int Low = -21;
	int High = 49;

	CreateArray(a, k, Low, High, 0);

	PrintArray(a, k, 0);
	cout << endl;

	cout << "Sum = " << GetSum(a, k - 1) << endl;
	cout << "Amount = " << GetAmount(a, k - 1) << endl;
	cout << endl;

	Set0(a, k, 0);

	PrintArray(a, k, 0);
	cout << endl;

	return 0;
}
