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
	Elem* link;
	Info info;
};

void Enqueue(Elem*& first, Elem*& last, Info val)
{
	Elem* tmp = new Elem; // 1
	tmp->info = val; // 2
	tmp->link = NULL; // 3
	if (last != NULL)
		last->link = tmp; // 4
	last = tmp; // 5
	if (first == NULL)
		first = tmp; // 6
}

Info Dequeue(Elem*& first, Elem*& last)
{
	Elem* tmp = first->link; // 1
	Info value = first->info; // 2
	delete first; // 3
	first = tmp; // 4
	if (first == NULL)
		last = NULL; // 5
	return value; // 6
}

void Print(Elem* L, string desc)
{
	cout << desc << endl;
	while (L != NULL)
	{
		cout << L->info << " ";
		//cout << "L->info : " << L->info << " L->link : " << L->link << " \n";
		L = L->link;
	}
	cout << endl << endl;
}

int Count(Elem* L)
{
	int k = 0;

	while (L != NULL)
	{
		k++;
		L = L->link;
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
		|| (L2_firstChar != L1_lastChar  && (a.compare(b) < 0))
		)
		return true;
	else
		return false;
}

void Process(Elem*& first, Elem*& last)
{
	Elem* L1 = NULL,
		* L2 = NULL;

	Info inf;

	int N = Count(first);
	//cout << "N : " << N << endl;

	L1 = first;
	L2 = first;
	for (int i0 = 0; i0 < N - 0; i0++) {
		for (int i1 = 0; i1 < N - i0 - 0; i1++) {
			if (cmp(L1->info, L2->info)) 
			{
				inf = L1->info;
				L1->info = L2->info;
				L2->info = inf;
				//cout << "L1->info : " << L1->info << " L1->link : " << L1->link << " 1\n";
				//cout << "L2->info : " << L2->info << " L2->link : " << L2->link << " 2\n";
			}
			if (L1->link != NULL)
				L1 = L1->link;
		}
		if (L2->link != NULL)
			L2 = L2->link;
	}

}

int main()
{
	Elem* first = NULL,
		* last = NULL;

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

	cout << "Processing (custom sort) ..." << endl;
	Process(first, last);

	Print(first, "List words after changes : ");

	return 0;
}
