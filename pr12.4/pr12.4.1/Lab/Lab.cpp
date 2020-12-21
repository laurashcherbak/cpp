#include <iostream>
#include <iomanip>

using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};

void Enqueue(Elem*& L, Info val, bool fillArray)
{
	if (fillArray)
	{
		//val = 10 - rand() % 20;
		val = abs(val) + 1;
		val = (((val % 2) == 0) ? val : -val);
	}

	Elem* tmp = new Elem; // 1
	tmp->info = val; // 2
	if (L != NULL) {
		Elem* T = L;
		while (T->link != L) {
			T = T->link; // 3
		}
		T->link = tmp; // 4
	}
	else {
		L = tmp; // 5
	}
	tmp->link = L; // 6
}

//Info Remove(Elem*& L)
//{
//	Elem* T = L;
//	while (T->link != L)
//		T = T->link; // 1
//	Info value = L->info; // 2
//	if (T != L) {
//		Elem* tmp = L->link; // 3
//		delete L; // 4
//		L = tmp; // 5
//		T->link = L; // 6
//	}
//	else {
//		delete L; // 4
//		L = NULL; // 7
//	}
//	return value; // 8
//}

void Print(Elem* L, string desc) {
	cout << desc << endl;
	if (L == NULL)
		return;
	Elem* first = L;
	cout<< L->info << " ";
	while (L->link != first) {
		L = L->link;
		cout << L->info << " ";
	}
	cout << endl << endl;
}

//int Count(Elem* L) {
//	if (L == NULL)
//		return 0;
//	Elem* first = L;
//	int k = 1;
//	while (L->link != first) {
//		k++;
//		L = L->link;
//	}
//	return k;
//}

void Process(Elem* L, Elem*& L1, Elem*& L2) {
	if (L != NULL) {
		Elem* first = L; // 1

		//while (L->link != first) { // 2
		while (L->link != NULL) { // 2
			if (L->info < 0) { // 3
				Enqueue(L2, L->info, false); // 4

			}
			else {
				Enqueue(L1, L->info, false); // 5

			}

			if (L->link == first) // 6
				break; // 7
			else
				L = L->link; // 8
		}
	}
}

int main()
{
	Elem* L = NULL;
	Elem* L1 = NULL;
	Elem* L2 = NULL;

	int len;
	cout << "Enter List length = "; cin >> len; cout << endl;
	for (int i = 0; i < len; i++)
		Enqueue(L, i, true);

	Print(L, "List L : ");
	
	cout << "Split values from L between L1 and L2 ..." << endl << endl;
	Process(L, L1, L2);

	Print(L1, "List L1 (positive values) : ");
	Print(L2, "List L2 (negative values) : ");

	return 0;
}
