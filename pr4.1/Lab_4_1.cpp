#include <iostream>
//#include <cmath>

using namespace std;

int main()
{
	int N;
	double P, k;

	cout << "N = "; 
	cin >> N;

	P = 1;
	k = N;

	while (k <= 19)
	{
		P *= ((k - N) / (k + N)) + 1;
		//cout << "k= " << k << " ; P= " << P << endl;
		k++;
	}

	cout << P << endl;

	P = 1;
	k = N;

	do {
		P *= ((k - N) / (k + N)) + 1;
		//cout << "k= " << k << " ; P= " << P << endl;
		k++;
	} while (k <= 19);

	cout << P << endl;
	
	P = 1;

	for (k = N; k <= 19; k++)
	{
		P *= ((k - N) / (k + N)) + 1;
		//cout << "k= " << k << " ; P= " << P << endl;
	}

	cout << P << endl;
	
	P = 1;

	for (k = 19; k >= N; k--)
	{
		P *= ((k - N) / (k + N)) + 1;
		//cout << "k= " << k << " ; P= " << P << endl;
	}

	cout << P << endl;

	return 0;
}