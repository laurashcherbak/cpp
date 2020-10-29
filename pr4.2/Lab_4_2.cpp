#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double x, xp, xk, dx, A, B, y;

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
		A = 8.1 + x * x * x;

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

		cout << "|" << setw(10) << setprecision(2) << x
			<< " |" << setw(10) << setprecision(3) << y
			<< " |" << endl;
		
		x += dx;
	}

	cout << "-------------------------" << endl;

	return 0;
}