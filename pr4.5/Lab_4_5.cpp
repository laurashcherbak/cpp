#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int main()
{
	double x; // вхідний аргумент
	double y; // вхідний параметр
	double R; // вхідний параметр

	cout << "R = ";
	cin >> R;

	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++)
	{
		cout << "x = "; 
		cin >> x;
		cout << "y = "; 
		cin >> y;

		if ((((x * x + y * y) <= R * R) && 0 <= x && x <= R && 0 <= y && y <= R) ||
			(((x * x + y * y) <= R * R) && -R <= x && x <= 0 && -R <= y && y <= 0) ||
			((fabs(x) + fabs(y)) <= (R * sqrt(2)) && -R <= x && x <= 0 && 0 <= y && y <= R)
			) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}

	cout << endl << fixed;


	double s;
		for (int i = 0; i < 10; i++)
		{
			//get random value in range => ((double)rand() / (RAND_MAX + 1))* (max - min + 1) + min;
			s = (1. * rand() / RAND_MAX);
			x = (1. * rand() / RAND_MAX * R) * (s >= 0.5 ? -1. : 1.);
			s = (1. * rand() / RAND_MAX);
			y = (1. * rand() / RAND_MAX * R) * (s >= 0.5 ? -1. : 1.);

			if ((((x * x + y * y) <= R * R) && 0 <= x && x <= R && 0 <= y && y <= R) ||
				(((x * x + y * y) <= R * R) && -R <= x && x <= 0 && -R <= y && y <= 0) ||
				((fabs(x) + fabs(y)) <= (R * sqrt(2)) && -R <= x && x <= 0 && 0 <= y && y <= R)
				) {
				cout << setw(10) << setprecision(4) << x << " "
					<< setw(10) << setprecision(4) << y << " "
					<< "yes" << endl;
			}
			else {
				cout << setw(10) << setprecision(4) << x << " "
					<< setw(10) << setprecision(4) << y << " "
					<< "no" << endl;
			}
		}

		return 0;
}