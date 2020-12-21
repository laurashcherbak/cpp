#include <iostream>

using namespace std;

typedef int Info;

struct Elem
{
	Elem* link;
	Info info;
};

void Enqueue(Elem*& first, Elem*& last, Info value, int N)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2
	tmp->link = NULL; // 3

	if (first == NULL) // 4
		first = tmp; // 5
	else
		last->link = tmp; // 5
	last = tmp; // 6

	if (value < N - 1) // 7
		return Enqueue(first, last, value + 1, N); //8
}

//Info Dequeue(Elem*& first, Elem*& last)
//{
//	Elem* tmp = first->link; // 1
//	Info value = first->info; // 2
//	delete first; // 3
//	first = tmp; // 4
//	if (first == NULL)
//		last = NULL; // 5
//	return value; // 6
//}

void Print(Elem* L, string desc, int n)
{
	int N = n;
	if (N == 0)
		cout << desc << endl;
	if (L != NULL) {
		cout << L->info << " ";
		return Print(L->link, desc, N + 1);
	}
	else {
		cout << endl;
	}
}

void Process(Elem* L, int inc_val, int N)
{
	if (L != NULL) { // 1
		L->info = L->info + inc_val; // 2
		return Process(L->link, inc_val, N + 1); // 3
	}
}

int main()
{
	Elem* first = NULL,
		* last = NULL;

	int len;
	cout << "Enter List length = "; cin >> len; cout << endl;
	for (int v = 0; v < len; v++)
		Enqueue(first, last, v + 1, 0);

	Print(first, "List before changes : ", 0);
	
	int inc_val;
	cout << "Enter increment value = "; cin >> inc_val; cout << endl;
	Process(first, inc_val, 0);

	Print(first, "List after changes : ", 0);

	return 0;
}
