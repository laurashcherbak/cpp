#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double xp, xk, dx;

	double x; // вхідний аргумент
	double R; // вхідний параметр
	double y; // результат обчислення виразу

	cout << "R = "; 
	cin >> R;

	cout << "xp = ";
	cin >> xp;
	cout << "xk = ";
	cin >> xk;
	cout << "dx = ";
	cin >> dx;

	cout << fixed;
	cout << "-------------------------" << endl;
	cout << "|" << setw(10) << "x" << " |"
		<< setw(10) << "y" << " |" << endl;
	cout << "-------------------------" << endl;

	x = xp;

	while (x <= xk)
	{
		if (x <= -2) {
			y = x + 3;
		}
		else if ((-2 < x) && (x <= 4)) {
			y = 1 + (-R - 1) * (x + 2.) / 6.;
		}
		else if ((4 < x) && (x <= (8 - R))) {
			y = -R;
		}
		else if (((8 - R) < x) && (x <= 8)) {
			y = sqrt(R * R - (x - 8) * (x - 8)) - R;
		}
		else if ((8 < x) && (x <= (8 + R))) {
			y = sqrt(R * R - (x - 8) * (x - 8)) - R;
		}
		else {
			y = -R;
		}

		cout << "|" << setw(10) << setprecision(2) << x
			<< " |" << setw(10) << setprecision(3) << y
			<< " |" << endl;

		x += dx;
	}

	cout << "-------------------------" << endl;

	return 0;
}
