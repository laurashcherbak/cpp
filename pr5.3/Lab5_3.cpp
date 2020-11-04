#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double z(const double x);

int main()
{
	double kp, kk, r;
	int n;

	cout << "kp = "; cin >> kp;
	cout << "kk = "; cin >> kk;
	cout << "n = "; cin >> n;

	double dk = (kk - kp) / n;
	double k = kp;

	cout << fixed;
	cout << "-------------------------" << endl;
	cout << "|" << setw(10) << "k" << " |"
		<< setw(10) << "r" << " |"
		<< endl;
	cout << "-------------------------" << endl;

	while (k <= kk)
	{
		r = z(2 * k + 1) + pow(z(2 * k - 1), 2) + sqrt(z(k));

		cout << "|" << setw(10) << setprecision(2) << k << " |"
			<< setw(10) << setprecision(5) << r << " |"
			<< endl;

		k += dk;
	}

	cout << "-------------------------" << endl;

	return 0;
}

double z(const double x)
{
	if (abs(x) >= 1)
		return (cos(x) + 1) / (pow(sin(x), 2) + exp(x));
	else
	{
		double S = 0;
		int j = 0;
		double a = 1 / exp(x);
		S = a;
		do
		{
			j++;
			double R = -x / j;
			a *= R;
			S += a;
		} while (j <= 7);

		//cout << "z(x) = " << (1 / exp(2 * x)) << " : " << S << "x: " << x << endl;
		return S;
	}
}
