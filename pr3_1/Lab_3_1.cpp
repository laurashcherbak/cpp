// Lab_3_1.cpp
// Laura Shcherbak
// Лабораторна робота No 3.1
// Розгалуження, задане формулою: функція однієї змінної.
// Варіант 25

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double x; // вхідний параметр
	double y; // результат обчислення виразу
	double A; // проміжний результат - функціонально стала частина виразу
	double B; // проміжний результат - функціонально змінна частина виразу

	cout << "x = "; 
	cin >> x;
	
	A = 8.1 + x*x*x;
	
	// спосіб 1: розгалуження в скороченій формі
	if (x < -3.5) {
		B = 1. - pow(x, -5);
	}

	if ((-3.5 <= x) && (x < 1)) {
		if (tan(fabs(x + 1)) == 0) {
			B = 1.;
		}
		else {
			B = 1. / tan(fabs(x + 1));
		}
	}

	if (x >= 1) {
		B = atan(2 * x) - log(x / 2);
	}

	y = A + B;
	
	cout << endl;
	cout << "1) y = " << y << endl;
	
	// спосіб 2: розгалуження в повній формі
	if (x < -3.5) {
		B = 1. - pow(x, -5);
	}
	else if ((-3.5 <= x) && (x < 1)) {
		if (tan(fabs(x + 1)) == 0) {
			B = 1.;
		}
		else {
			B = 1. / tan(fabs(x + 1));
		}
	}
	else {
		B = atan(2 * x) - log(x / 2);
	}

	y = A + B;
	
	cout << "2) y = " << y << endl;
	
	cin.get();
	
	return 0;
}