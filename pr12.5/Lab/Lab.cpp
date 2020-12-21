#include <iostream>
#include <iomanip>

using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};

void push(Elem*& top, Info value)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2
	if (top == NULL)
		tmp->link = NULL; // 3
	else
		tmp->link = top; // 3
	top = tmp; // 4
}

Info pop(Elem*& top)
{
	Elem* tmp = top->link; // 1
	Info value = top->info; // 2
	delete top; // 3
	top = tmp; // 4
	return value; // 5
}

void print(Elem*& top)
{
	while (top != NULL)
		cout << pop(top) << " ";
	cout << endl;
}

void find(Elem*& top, Info inf)
{
	bool found = false;
	while (top != NULL) {
		if (pop(top) == inf) {
			found = true;
		}
	}
	if (found)
		cout << "Value was found.";
	else
		cout << "Value was not found.";
	cout << endl;
}

int main()
{

	Elem* top = NULL;
	cout << "Stack has been created and populated." << endl;
	for (int i = 1; i <= 10; i++)
		push(top, i);
	cout << "Print Stack." << endl;
	print(top);

	cout << "Stack has been created and populated." << endl;
	for (int i = 1; i <= 10; i++)
		push(top, i);
	Info inf;
	cout << "Search value in Stack." << endl;
	cout << "Enter search value : "; cin >> inf;
	find(top, inf);
	cout << "Print Stack." << endl;
	print(top);

	for (int i = 1; i <= 10; i++)
		push(top, i);

	cout << "Print Stack." << endl;
	print(top);

	cout << "Stack has been created and populated." << endl;
	for (int i = 1; i <= 10; i++)
		push(top, i);
	cout << "Delete top 5 values from Stack." << endl;
	for (int i = 1; i <= 5; i++)
		pop(top);
	cout << "Print Stack." << endl;
	print(top);

	return 0;
}
