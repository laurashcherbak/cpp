#include <iostream>

using namespace std;

int main()
{
	double p1, p2, r;
	char op;

	int q = 0;
	
	while (true) {
		if (q > 0) {
			cout << "Continue (Y/N): "; cin >> op;
			if (op == 'N') return 0;
		}
		r = 0;
		cout << "operation: "; cin >> op;
		if (op == '+' || op == '-' || op == '*' || op == '/') {
			cout << "parameter 1: "; cin >> p1;
			cout << "parameter 2: "; cin >> p2;

			if (op == '+') {
				r = p1 + p2;
				cout << "result: " << r << endl;
			}
			else if (op == '-') {
				r = p1 - p2;
				cout << "result: " << r << endl;
			}
			else if (op == '*') {
				r = p1 * p2;
				cout << "result: " << r << endl;
			}
			else if (op == '/') {
				if (p2 == 0) {
					cout << "Can not divide by 0" << endl;
				}
				else {
					r = p1 / p2;
					cout << "result: " << r << endl;
				}
			}

		}
		else {
			//return 0;
		}
		q++;
	}

	return 0;
}
