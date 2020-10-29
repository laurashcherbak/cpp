#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double P, S, k;
	int i;

	S = 0;
	i = 1;

	while (i <= 15)
	{
		P = 1;
		k = 1;
		while (k <= i)
		{
			P *= k * k + 1;
			k++;
		}
		S += P / (1 + P * P);
		i++;
	}

	cout << S << endl;

	S = 0;
	i = 1;

	do
	{
		P = 1;
		k = 1;
		do
		{
			P *= k * k + 1;
			k++;
		} while (k <= i);
		S += P / (1 + P * P);
		i++;
	} while (i <= 15);

	cout << S << endl;

	S = 0;

	for (i = 1; i <= 15; i++)
	{
		P = 1;
		for (k = 1; k <= i; k++)
		{
			P *= k * k + 1;
		}
		S += P / (1 + P * P);
	}

	cout << S << endl;

	S = 0;

	for (i = 15; i >= 1; i--)
	{
		P = 1;
		for (k = i; k >= 1; k--)
		{
			P *= k * k + 1;
		}
		S += P / (1 + P * P);
	}

	cout << S << endl;

	return 0;
}