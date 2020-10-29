#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double xp, xk, dx;

	double x; // вхідний аргумент
	double a; // вхідний параметр
	double b; // вхідний параметр
	double c; // вхідний параметр
	double F; // результат обчислення виразу

	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "c = "; cin >> c;

	cout << "xp = ";
	cin >> xp;
	cout << "xk = ";
	cin >> xk;
	cout << "dx = ";
	cin >> dx;

	cout << fixed;
	cout << "-------------------------" << endl;
	cout << "|" << setw(10) << "x" << " |"
		<< setw(10) << "F" << " |" << endl;
	cout << "-------------------------" << endl;

	x = xp;

	while (x <= xk)
	{
		if ((x < 0) && (b != 0)) {
			if (b == -10) {
				F = a - x;
			}
			else {
				F = a - x / (10 + b);
			}
		}
		else if ((x > 0) && (b == 0)) {
			if ((x - c) == 0) {
				F = x - a;
			}
			else {
				F = (x - a) / (x - c);
			}
		}
		else {
			if (c == 0) {
				F = 3 * x + 2;
			}
			else {
				F = 3 * x + 2. / c;
			}
		}

		cout << "|" << setw(10) << setprecision(2) << x
			<< " |" << setw(10) << setprecision(3) << F
			<< " |" << endl;

		x += dx;
	}

	cout << "-------------------------" << endl;

	return 0;
}
