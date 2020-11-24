#include <iostream>
#include <iomanip>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Input(int** a, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	cout << setw(6) << "m\\n |";
	for (int i = 0; i < colCount; i++) cout << setw(4) << i;
	cout << endl;
	cout << "-------"; for (int i = 0; i < colCount; i++) cout << "----"; cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		cout << setw(4) << i << " | ";
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

bool IsSymmetricalMatrixBack(int** a, const int N, const int M)
{
	if (N != M) return false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - i - 1; j++) {
			//cout << "back diagonal: compare a[" << i << "][" << j << "] and a[" << N - j - 1 << "][" << M - i - 1 << "] (" << a[i][j] << " and " << a[M - j - 1][N - i - 1] << ")" << endl;
			if ((a[j][i] != a[N - i - 1][M - j - 1]) && (j != (N - i - 1))) {
				//cout << "<>" << endl;
				return false;
			}
		}
	}
	return true;
}

bool IsSymmetricalMatrixBackR(int** a, const int N, const int M, int i, int j, bool& r)
{
	//cout << "back diagonal: compare a[" << i << "][" << j << "] and a[" << j << "][" << i << "] (" << a[i][j] << " and " << a[j][i] << ")" << endl;
	if (N == M && N == 1 && r) {
		r = true;
	}
	else if (N != M && r) {
		//cout << "N<>M" << endl;
		r = false;
	}
	//else if (N == M && r)
	//{
		//cout << "main diagonal: compare a[" << i << "][" << j << "] and a[" << j << "][" << i << "] (" << a[i][j] << " and " << a[j][i] << ")" << endl;
		if ((a[j][i] != a[N - i - 1][M - j - 1]) && (j != (N - i - 1))) {
			//cout << "a[j][i] != a[i][j]" << endl;
			r = false;
		}

		if (j < M - i - 1 && (i != j)) {
			r = IsSymmetricalMatrixBackR(a, N, M, i , j + 1, r);
		}
		else
		if (i < N - 1 && (i != j)) {
			r = IsSymmetricalMatrixBackR(a, N, M, i + 1, 0, r);
		}

	//}

	return r;
}

int main() {
	srand((unsigned)time(NULL));

	int Low = -17;
	int High = 15;
	int rowCount, colCount;
	char t;

	cout << "rowCount (m) = "; cin >> rowCount;
	cout << "colCount (n) = "; cin >> colCount;
	cout << endl;
	if (rowCount < 1 || colCount < 1) return 0;
	
	cout << "Would you like to enter data for array manually (y/n): "; cin >> t;
	cout << endl;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	if (t == 'y')
		Input(a, rowCount, colCount);
	else
		Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);

	
	bool r = true;
	r = IsSymmetricalMatrixBackR(a, rowCount, colCount, 0, 0, r);
	cout << (r ? "yes" : "no") << endl;

	cout << (IsSymmetricalMatrixBack(a, rowCount, colCount) ? "yes" : "no") << endl;


	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}
