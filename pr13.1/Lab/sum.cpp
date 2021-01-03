//////////////////////////////////////////////////////////////////////////////
// sum.cpp
// файл реалізації функції

#include <math.h>

#include "sum.h"
#include "add.h"
#include "var.h"

using namespace Var;
using namespace Add;

void Sum::Sum() {

	n = 1;
	a = -x;
	s = a;
	do {
		n++;
		Add::Add();
		s += a;
	} while (fabs(a) >= eps);

}
