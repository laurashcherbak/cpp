#include <iostream>
#include <cmath>

using namespace std;

double P0(const int N, const int N19)
{
	double p = 1;
	for (int k = N; k <= N19; k++) {
		p *= (((k - N) * 1. / (k + N)) + 1);
	}
	return p;
}

double P1(const int N, const int N19, const int k)
{
	double p;
	if (k > N19)
		p = 1.;
	else
		p = (((k - N) * 1. / (k + N)) + 1) * P1(N, N19, k + 1);
	return p;
}

double P2(const int N, const int N19, const int k)
{
	double p;
	if (k < N)
		p = 1.;
	else
		p = (((k - N) * 1. / (k + N)) + 1) * P2(N, N19, k - 1); // sin(1. * i) + S2(K, N, i - 1);
	return p;
}

double P3(const int N, const int N19, const int k, double t)
{
	t = t * (((k - N) * 1. / (k + N)) + 1);
	if (k >= N19)
		return t;
	else
		return P3(N, N19, k + 1, t);
}

double P4(const int N, const int N19, const int k, double t)
{
	t = t * (((k - N) * 1. / (k + N)) + 1);
	if (k <= N)
		return t;
	else
		return P4(N, N19, k - 1, t);
}

int main()
{
	int N;
	//int N19 = 19;

	cout << "N = "; cin >> N;
	//	cout << "N19 = "; cin >> N19;

	cout << "(iter) P0 = " << P0(N, 19) << endl;
	cout << "(rec up ++) P1 = " << P1(N, 19, N) << endl;
	cout << "(rec up --) P2 = " << P2(N, 19, 19) << endl;
	cout << "(rec down ++) P3 = " << P3(N, 19, N, 1.) << endl;
	cout << "(rec down --) P4 = " << P4(N, 19, 19, 1.) << endl;

	return 0;
}