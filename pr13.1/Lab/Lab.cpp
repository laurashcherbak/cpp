//////////////////////////////////////////////////////////////////////////////
// Lab_13_1.cpp
// головний файл проекту – функція main

#include <iostream>
#include <iomanip>
#include <cmath>

#include "var.h"
#include "sum.h"
#include "add.h"

using namespace std;
using namespace Sum;
using namespace Var;

int main()
{
	n = 0;
	s = 0;

	cout << "x_p = "; cin >> x_p;
	cout << "x_k = "; cin >> x_k;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;
	cout << endl;

	cout << fixed;
	cout << "+--------------------------------------------+" << endl;
	cout << "|" << setw(7) << "x" << " |"
		<< setw(10) << "ln(1-x)" << " |"
		<< setw(10) << "S" << " |"
		<< setw(10) << "n" << " |"
		<< endl;
	cout << "+--------+-----------+-----------+-----------+" << endl;

	x = x_p;
	while (x <= x_k) {

		Sum::Sum();
		cout << "|" << setw(7) << setprecision(2) << x << " |"
			<< setw(10) << setprecision(5) << log(1 - x) << " |"
			<< setw(10) << setprecision(5) << s << " |"
			<< setw(10) << n << " |"
			<< endl;

		x += dx;
	}
	cout << "+--------------------------------------------+" << endl;

	return 0;
}
