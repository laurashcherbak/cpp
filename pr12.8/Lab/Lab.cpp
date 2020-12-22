#ifndef _CRT_SECURE_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
#endif // !#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef string Info;

struct Elem
{
	//Elem* link;
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

Info dequeue(Elem*& first, Elem*& last)
{
	Elem* tmp = first->next; // 1
	Info value = first->info; // 2
	delete first; // 3
	first = tmp; // 4
	if (first == NULL)
		last = NULL; // 5
	else
		first->prev = NULL; // 6
	return value; // 7
}

void Print(Elem* L, string desc)
{
	cout << desc << endl;
	while (L != NULL)
	{
		//cout << "function Print : " << "L->info : " << L->info << " L : " << L << " L->prev : " << L->prev << " L->next : " << L->next << " \n";
		cout << L->info << " ";
		//L = L->link;
		L = L->next;
	}
	cout << endl << endl;
}

int Count(Elem* L)
{
	int k = 0;

	while (L != NULL)
	{
		k++;
		L = L->next;
		//L = L->link;
	}
	cout << endl << endl;

	return k;
}

void SplitStrAndPutIntoQueue(Elem*& first, Elem*& last, string s)
{
	char sep = ' ';
	Info val;

	for (size_t p = 0, q = 0; p != s.npos; p = q) {
		val = s.substr(p + (p != 0), (q = s.find(sep, p + 1)) - p - (p != 0));
		Enqueue(first, last, val);
	}
}

bool cmp(Info a, Info b)
{
	char L1_firstChar, L2_firstChar, L1_lastChar, L2_lastChar;

	//L1_firstChar = a.at(0);
	L2_firstChar = b.at(0);
	L1_lastChar = a.at(a.length() - 1);
	//L2_lastChar = b.at(b.length() - 1);

	if (
		((L2_firstChar == L1_lastChar))
		|| (L2_firstChar != L1_lastChar && (a.compare(b) < 0))
		)
		return true;
	else
		return false;
}

void Process(Elem*& L, Elem*& L1, Elem*& L2, int& N, Info& val)
{
	Info inf;
	Elem* L1_last = NULL,
		* L2_last = NULL;

	int i = 1;
	while (L != NULL)
	{
		inf = L->info;
		if (i < N) {
			//cout << "i < N : " << "L->info : " << L->info << " L : " << L << " L->prev : " << L->prev << " L->next : " << L->next << " \n";
			Enqueue(L1, L1_last, inf);
		}
		else if (i == N) {
			//cout << "i == N : " << "L->info : " << L->info << " L : " << L << " L->prev : " << L->prev << " L->next : " << L->next << " \n";
			Enqueue(L1, L1_last, inf);
			Enqueue(L1, L1_last, val);
			Enqueue(L2, L2_last, val);
		}
		else {
			//cout << "i > N : " << "L->info : " << L->info << " L : " << L << " L->prev : " << L->prev << " L->next : " << L->next << " \n";
			Enqueue(L2, L2_last, inf);
		}
		L = L->next;
		i++;
	}

}


int main()
{
	Elem* first = NULL,
		* last = NULL;
	Elem* L1 = NULL,
		* L2 = NULL;

	string str;

	char ch;
	cout << "Do you want to read string from the text.txt (Y/N) (Default:N) : "; cin >> ch; cout << endl;
	if (ch == 'y' || ch == 'Y') {
		ifstream f;
		f.open("text.txt");
		while (!f.eof())
			getline(f, str);
		f.close();
	}
	else
	{
		cin.get();
		cin.sync();
		cout << "Enter string : ";
		getline(cin, str);
		cout << endl;
	}
	SplitStrAndPutIntoQueue(first, last, str);

	Print(first, "List words before changes : ");

	Info val;
	int N;
	cout << "Enter N for split List : "; cin >> N;
	cout << "Enter additional value : "; cin >> val;
	cout << endl;
	Process(first, L1, L2, N, val);

	Print(L1, "List L1 : ");
	Print(L2, "List L2 : ");

	return 0;
}
