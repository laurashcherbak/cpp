﻿#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double xp, xk, x, dx, eps, a = 1, R = 0, S = 0;
	int64_t n = 0;

	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;

	cout << fixed;
	cout << "-------------------------------------------------" << endl;
	cout << "|" << setw(7) << "x" << " |"
		<< setw(16) << "ln((1+x)/(1-x))" << " |"
		<< setw(10) << "S" << " |"
		<< setw(7) << "n" << " |"
		<< endl;
	cout << "-------------------------------------------------" << endl;

	x = xp;

	while (x <= xk)
	{
		n = 0; // вираз залежить від умови завдання варіанту
		a = 2 * x; // вираз залежить від умови завдання варіанту
		S = a;

		do {
			n++;
			R = (pow(x, 2 * n + 1) * (2 * n - 1)) / (pow(x, 2 * n - 1) * (2 * n + 1)); // вираз залежить від умови завдання варіанту
			a *= R;
			S += a;
		} while (abs(a) >= eps);

		cout << "|" << setw(7) << setprecision(2) << x << " |"
			<< setw(16) << setprecision(5) << log((1 + x) / (1 - x)) << " |"
			<< setw(10) << setprecision(5) << S << " |"
			<< setw(7) << n << " |"
			<< endl;

		x += dx;
	}

		cout << "-------------------------------------------------" << endl;
	return 0;
}