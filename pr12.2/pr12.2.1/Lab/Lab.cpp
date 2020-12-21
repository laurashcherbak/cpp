#include <iostream>

using namespace std;

typedef int Info;

struct Elem
{
	Elem* link;
	Info info;
};

void Enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2
	tmp->link = NULL; // 3
	if (last != NULL)
		last->link = tmp; // 4
	last = tmp; // 5
	if (first == NULL)
		first = tmp; // 6
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
	cout << endl;
}

void Process(Elem* L, int inc_val)
{
	while (L != NULL) // 1
	{
		L->info = L->info + inc_val; // 2
		L = L->link; // 3
	}
}

int main()
{
	Elem* first = NULL,
		* last = NULL;

	int len;
	cout << "Enter List length = "; cin >> len; cout << endl;
	for (int v = 0; v < len; v++)
		Enqueue(first, last, v + 1);

	Print(first, "List before changes : ");
	
	int inc_val;
	cout << "Enter increment value = "; cin >> inc_val; cout << endl;
	Process(first, inc_val);

	Print(first, "List after changes : ");

	return 0;
}
