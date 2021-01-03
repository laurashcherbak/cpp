//////////////////////////////////////////////////////////////////////////////
// Lab_13_2.cpp
// головний файл проекту – функція main

#include <iostream>
#include <iomanip>
#include <cmath>

#include "var.h"
using namespace std;
using namespace Var;

#define z 0 // директива препроцесора – макровизначення

#define COUT(s) cout << s

#define MOD(x) abs(x)
#define POW(x) (x) * (x)
#define SQRT(x) sqrt(x)
#define MIN(x, y, z) ((x - y) > (y - z)) ? (y - z) : (x - y)
#define MAX(x, y, z) (POW(x - z) > (x - y)) ? POW(x - z) : (x - y)

#define COS(x) cos(x)
#define R2(a, b, c) COS(a) + COS(b) + COS(c)

void main()
{

	COUT("Lab 13.2. Using macros and preprocessing directive \n");

	COUT("\n Part 1 \n\n");
	do
	{
		COUT("Enter values: \n");
		COUT("x = "); cin >> x;
		COUT("y = "); cin >> y;

#if z > 1 // якщо умова істинна, то шукаємо максимум з трьох чисел
			r = MAX(x, y, z);
#else // компілювати іншу частину програми, якщо z <= 1
			r = MIN(x, y, z);
#endif // завершення блоку умовної компіляції

		COUT("Result = ");
		COUT(MOD(r));
		COUT("\n");

		COUT("Get MOD result (y/n): "); cin >> ch;
		if (ch == 'y') {
			COUT("MOD(result) = ");
			COUT(MOD(r));
			COUT("\n");
		}
		COUT("Get POW result (y/n): "); cin >> ch;
		if (ch == 'y') {
			COUT("POW(result) = ");
			COUT(POW(r));
			COUT("\n");
		}
		COUT("Get SQRT result (y/n): "); cin >> ch;
		if (ch == 'y') {
			COUT("SQRT(result) = ");
			COUT(SQRT(MOD(r)));
			COUT("\n");
		}

		COUT("Repeat? y /n "); cin >> ch;

	} while (ch == 'y');

	COUT("\n Part 2 \n\n");
	do
	{
		COUT("Enter values: \n");
		COUT("a = "); cin >> a;
		COUT("b = "); cin >> b;
		COUT("c = "); cin >> c;

		r = R2(a, b, c);
		cout << "a = " << a << " b = " << b << " c = " << c << " r2 = " << r << endl;
		COUT("Result = ");
		COUT(r);
		COUT("\n");

		COUT("Repeat? y /n "); cin >> ch;

	} while (ch == 'y');

}
