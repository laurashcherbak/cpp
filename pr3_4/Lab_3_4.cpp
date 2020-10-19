// Lab_3_4.cpp
// Laura Shcherbak
// Лабораторна робота No 3.4
// Розгалуження, задане плоскою фігурою.
// Варіант 25

#include <iostream>

using namespace std;

int main()
{
	double x; // вхідний аргумент
	double y; // вхідний параметр
	double R; // вхідний параметр

	cout << "x = "; 
	cin >> x;
	cout << "y = "; 
	cin >> y;
	cout << "R = "; 
	cin >> R;

	// розгалуження в повній формі
	if ((((x * x + y * y) <= R * R) && 0 <= x && x <= R && 0 <= y && y <= R) ||
		(((x * x + y * y) <= R * R) && -R <= x && x <= 0 && -R <= y && y <= 0) ||
		((fabs(x) + fabs(y)) <= (R * sqrt(2)) && -R <= x && x <= 0 && 0 <= y && y <= R)
		) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}

	cin.get();

	return 0;
}