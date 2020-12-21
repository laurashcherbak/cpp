#include <iostream>
#include <time.h>

using namespace std;

typedef int Info;

struct Elem
{
	Elem* next;
	Elem* prev;
	Info info;
};

void Enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2
	tmp->next = NULL; // 3
	if (last != NULL)
		last->next = tmp; // 4
	tmp->prev = last; // 5
	last = tmp; // 6
	if (first == NULL)
		first = tmp; // 7
}

//Info dequeue(Elem*& first, Elem*& last)
//{
//	Elem* tmp = first->next; // 1
//	Info value = first->info; // 2
//	delete first; // 3
//	first = tmp; // 4
//	if (first == NULL)
//		last = NULL; // 5
//	else
//		first->prev = NULL; // 6
//	return value; // 7
//}

void Print(Elem* L, string desc)
{
	cout << desc << endl;
	while (L != NULL)
	{
		cout << L->info << " ";
		L = L->next;
	}
	cout << endl;
}

void Process(Elem* L, Info V1, Info V2)
{
	while (L != NULL)
	{
		if (L->info == V1) // 0
		{
			Elem* tmp = new Elem; // 1
			tmp->info = V2; // 2
			tmp->next = L->next; // 3
			if (L->next != NULL) // 4
				L->next->prev = tmp; // 5
			L->next = tmp; // 6
			tmp->prev = L; // 7
			
			L = L->next->next; // 8
		}
		else
			L = L->next; // 9
	}
}

int main()
{
	srand((unsigned)time(NULL));

	Elem* first = NULL,
		* last = NULL;

	int len;
	cout << "Enter List length = "; cin >> len; cout << endl;
	for (int v = 0; v < len; v++) {
		Enqueue(first, last, (rand() % 3));
	}

	Print(first, "List before changes : ");

	int V1, V2;
	cout << endl;
	cout << "Enter V1 = "; cin >> V1;
	cout << "Enter V2 = "; cin >> V2;
	cout << endl;
	Process(first, V1, V2);

	Print(first, "List after changes : ");

	return 0;
}
