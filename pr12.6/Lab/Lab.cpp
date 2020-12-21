#include <iostream>
#include <iomanip>

using namespace std;

typedef int Info;

struct Elem
{
	Elem* link;
	Info info;
};

void Enqueue(Elem*& first, Elem*& last, Info val, bool fillArray)
{
	if (fillArray)
	{
		val = 10 - rand() % 20;
		//val = abs(val) + 1;
		//val = (((val % 2) == 0) ? val : -val);
	}

	Elem* tmp = new Elem; // 1
	tmp->info = val; // 2
	tmp->link = NULL; // 3
	if (last != NULL)
		last->link = tmp; // 4
	last = tmp; // 5
	if (first == NULL)
		first = tmp; // 6
}

void Print(Elem* L, string desc)
{
	Info inf;
	cout << desc << endl;
	while (L != NULL)
	{
		inf = L->info;
		cout << L->info << " ";
		L = L->link;
	}
	cout << endl << endl;
}

void Process(Elem* L, Elem*& Q1_first, Elem*& Q2_first, Elem*& Q1_last , Elem*& Q2_last)
{
	Info val;
	while (L != NULL) // 0
	{
		val = L->info; // 1
		if ((val % 2) == 0) // 2
			Enqueue(Q2_first, Q2_last, val, false); // 3
		else
			Enqueue(Q1_first, Q1_last, val, false); // 4
		L = L->link; // 5
	}
}

int main()
{
	Elem* first = NULL,
		* last = NULL;
	Elem* Q1_first = NULL,
		* Q1_last = NULL,
		* Q2_first = NULL,
		* Q2_last = NULL;

	int len = 10;
	//cout << "Enter List length = "; cin >> len; cout << endl;
	for (int v = 0; v < len; v++)
		Enqueue(first, last, v, true);

	Print(first, "List numbers before changes : ");

	cout << "Split values from L between Q1 and Q2 ..." << endl << endl;
	Process(first, Q1_first, Q2_first, Q1_last, Q2_last);

	cout << "Q1 first pointer : " << Q1_first << endl;
	cout << "Q1 last pointer : " << Q1_last << endl;
	Print(Q1_first, "Queue Q1 : ");

	cout << "Q2 first pointer : " << Q2_first << endl;
	cout << "Q2 last pointer : " << Q2_last << endl;
	Print(Q2_first, "Queue Q2 : ");

	return 0;
}
