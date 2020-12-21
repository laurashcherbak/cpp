#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};

void Enqueue(Elem*& L, Elem* F, Info val, int N, int i, bool fillArray)
{

	if (fillArray)
	{
		//val = 10 - rand() % 20;
		val = abs(val) + 1;
		val = (((val % 2) == 0) ? val : -val);
	}

	Elem* tmp = new Elem;

	if (L != NULL)
		while (F->link != L)
			F = F->link;

	tmp->info = val;
	if (L == NULL)
		L = tmp;
	else
		F->link = tmp;
	tmp->link = L;

	if (i < N - 1)
		Enqueue(L, L, val, N, i + 1, fillArray);
}

void Print(Elem*& L, Elem*& F, string desc, bool showDesc)
{
	if (showDesc)
		cout << desc << endl;

	cout << F->info << " ";

	if (F->link != L)
	{
		F = F->link;
		Print(L, F, desc, false);
	}
	else
	{
		cout << endl << endl;
	}
}

void Process(Elem*& L, Elem*& L1, Elem*& L2, Elem*& F)
{
	Info val;

	if (F->link != L) // 0
	{
		val = F->info; // 1
		//F = F->link; // 2
		if (val >= 0) // 3
			Enqueue(L1, L1, val, 1, 0, false); // 4
		else
			Enqueue(L2, L2, val, 1, 0, false); // 5

		//Process(L, L1, L2, F); // 6
		Process(L, L1, L2, F->link); // 6
	}
	//if (F->link != L)
	//	Process(L, L1, L2, F);
	else
	{
		val = F->info; // 1
		if (val >= 0) // 3
			Enqueue(L1, L1, val, 1, 0, false); // 4
		else
			Enqueue(L2, L2, val, 1, 0, false); // 5
	}
}

int main()
{
	srand((unsigned)time(NULL));

	Elem* L = NULL;
	Elem* L1 = NULL;
	Elem* L2 = NULL;
	Elem* F;

	int len = 10;
	cout << "Enter List length = "; cin >> len; cout << endl;
	F = L;
	Enqueue(L, F, 0, len, 0, true);

	F = L;
	Print(L, F, "List L : ", true);

	cout << "Split values from L between L1 and L2 ..." << endl << endl;
	F = L;
	Process(L, L1, L2, F);

	F = L1;
	Print(L1, F, "List L1 (positive values) : ", true);

	F = L2;
	Print(L2, F, "List L2 (negative values) : ", true);

	return 0;
}


