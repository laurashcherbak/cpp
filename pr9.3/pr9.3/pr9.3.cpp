#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

enum UnitOfMeasurement { KG, Packet, Piece};
string unitOfMeasurmentStr[] = { "KG", "Packet", "Piece" };

struct Goods 
{
	string title;
	double price;
	unsigned amount;
	UnitOfMeasurement unitOfMeasurement;
};

unsigned GetAndCheckUnsignedValue(string s, unsigned minVal, unsigned maxVal)
{
	unsigned t;
	bool e;
	e = true;

	while (e) {
		cout << s; cin >> t;

		if (cin.fail())
			e = true;
		else if (t < minVal || t > maxVal)
			e = true;
		else
			e = false;

		if (e) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Error: Incorrect value. Please enter again." << endl;
		}
	}

	return t;
}

double GetAndCheckDoubleValue(string s)
{
	double t;
	bool e;
	e = true;

	while (e) {
		cout << s; cin >> t;

		if (cin.fail())
			e = true;
		else if (t <= 0.0)
			e = true;
		else
			e = false;

		if (e) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Error: Incorrect value. Please enter again." << endl;
		}
	}

	return t;
}

void Create(Goods* p, const int N)
{
	int unitOfMeasurement;

	for (int i = 0; i < N; i++)
	{
		cout << "Product No " << i + 1 << ":" << endl;

		cout << " title: "; cin >> p[i].title;
		p[i].price = GetAndCheckDoubleValue(" price: ");
		p[i].amount = GetAndCheckUnsignedValue(" amount: ", 0, 10000);
		unitOfMeasurement = GetAndCheckUnsignedValue("unit of measurement (0 - KG, 1 - Packet, 2 - Piece): ", 0, 2);
		p[i].unitOfMeasurement = (UnitOfMeasurement)unitOfMeasurement;
		cout << endl;
	}
}

void Print(Goods* p, const int N)
{
	cout << "+==========================================================+" << endl;
	cout << "| No |     Title    | Price | Amount | Unit of measurement |" << endl;
	cout << "+----------------------------------------------------------+" << endl;

	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << p[i].title
			<< "| " << setw(5) << right << p[i].price << " "
			<< "| " << setw(6) << right << p[i].amount << " "
			<< "| " << setw(20) << left << unitOfMeasurmentStr[p[i].unitOfMeasurement]
			<< "|" << endl;
	}

	cout << "+==========================================================+" << endl;
	cout << endl;
}

void PrintByTitle(Goods* p, const int N)
{
	string title;
	cout << "Input title: ";
	cin >> title;
	cout << endl;

	cout << "+==========================================================+" << endl;
	cout << "| No |     Title    | Price | Amount | Unit of measurement |" << endl;
	cout << "+----------------------------------------------------------+" << endl;

	for (int i = 0; i < N; i++)
	{
		if (p[i].title == title)
		{
			cout << "| " << setw(2) << right << i + 1 << " ";
			cout << "| " << setw(13) << left << p[i].title
				<< "| " << setw(5) << right << p[i].price << " "
				<< "| " << setw(6) << right << p[i].amount << " "
				<< "| " << setw(20) << left << unitOfMeasurmentStr[p[i].unitOfMeasurement]
				<< "|" << endl;
		}
	}

	cout << "+==========================================================+" << endl;
	cout << endl;
}

void PrintByPriceRange(Goods* p, const int N)
{
	double Min, Max;
	Min = GetAndCheckDoubleValue("Enter min value: ");
	Max = GetAndCheckDoubleValue("Enter max value: ");

	cout << "+==========================================================+" << endl;
	cout << "| No |     Title    | Price | Amount | Unit of measurement |" << endl;
	cout << "+----------------------------------------------------------+" << endl;

	for (int i = 0; i < N; i++)
	{
		if (p[i].price >= Min && p[i].price <= Max)
		{
			cout << "| " << setw(2) << right << i + 1 << " ";
			cout << "| " << setw(13) << left << p[i].title
				<< "| " << setw(5) << right << p[i].price << " "
				<< "| " << setw(6) << right << p[i].amount << " "
				<< "| " << setw(20) << left << unitOfMeasurmentStr[p[i].unitOfMeasurement]
				<< "|" << endl;
		}
	}

	cout << "+==========================================================+" << endl;
	cout << endl;
}

void SortByTitle(Goods* p, const int N)
{
	Goods t;
	for (int i0 = 0; i0 < N - 1; i0++) // метод "бульбашки"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if (p[i1].title > p[i1 + 1].title)
			{
				t = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = t;
			}
}

void SortByPrice(Goods* p, const int N)
{
	Goods t;
	for (int i0 = 0; i0 < N - 1; i0++) // метод "бульбашки"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if (p[i1].price > p[i1 + 1].price)
			{
				t = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = t;
			}
}

void SaveToFile(Goods* p, const int N, const char* filename)
{
	ofstream fout(filename, ios::binary); // відкрили бінарний файл запису
	fout.write((char*)&N, sizeof(N)); // записали кількість елементів
	for (int i = 0; i < N; i++)
		fout.write((char*)&p[i], sizeof(Goods)); // записали елементи масиву
	fout.close(); // закрили файл
}

void LoadFromFile(Goods*& p, int& N, const char* filename)
{
	delete[] p; // знищили попередні дані
	ifstream fin(filename, ios::binary); // відкрили бінарний файл зчитування
	fin.read((char*)&N, sizeof(N)); // прочитали кількість елементів
	p = new Goods[N]; // створили динамічний масив
	for (int i = 0; i < N; i++)
		fin.read((char*)&p[i], sizeof(Goods)); // прочитали елементи масиву
	fin.close(); // закрили файл
}

void Remove(Goods* &p, int& N)
{
	int index;

	Print(p, N);
	index = GetAndCheckUnsignedValue("Enter No: ", 1, N);
	index--;
	
	Goods* t = new Goods[N - 1];

	int j = 0;
	for (int i = 0; i < N; i++)
		if (i != index)
		{
			t[j++] = p[i];
		}

	//delete[] p;
	p = t;
	N = j;
}

void Change(Goods* &p, int& N)
{
	int i;

	Print(p, N);

	i = GetAndCheckUnsignedValue("Enter No: ", 1, N);
	i--;

	int unitOfMeasurement;

	cout << "Product No " << i + 1 << ":" << endl;

	cout << " title: "; cin >> p[i].title;
	p[i].price = GetAndCheckDoubleValue(" price: ");
	p[i].amount = GetAndCheckUnsignedValue(" amount: ", 0, 10000);
	unitOfMeasurement = GetAndCheckUnsignedValue("unit of measurement (0 - KG, 1 - Packet, 2 - Piece): ", 0, 2);
	p[i].unitOfMeasurement = (UnitOfMeasurement)unitOfMeasurement;
	cout << endl;
}

void Menu()
{
	char filename[100];

	int menuItem;

	int N;
	N = GetAndCheckUnsignedValue("Enter N: ", 1, 1000);
	Goods* p = new Goods[N];

	do {
		cout << endl << endl;
		cout << "Select an action:" << endl << endl;
		cout << " [1] - enter/add data" << endl;
		cout << " [2] - delete data" << endl;
		cout << " [3] - change data" << endl;
		cout << " [4] - print data" << endl;
		cout << " [5] - sort by title" << endl;
		cout << " [6] - sort by price" << endl;
		cout << " [7] - print product's information by title" << endl;
		cout << " [8] - print products' information by the specified price range" << endl;
		cout << " [9] - load data from file" << endl;
		cout << " [10] - save data to file" << endl;
		cout << " [0] - exit" << endl << endl;
		cout << "Enter a number: "; cin >> menuItem;
		cout << endl << endl;

		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Remove(p, N);
			break;
		case 3:
			Change(p, N);
			break;
		case 4:
			Print(p, N);
			break;
		case 5:
			SortByTitle(p, N);
			break;
		case 6:
			SortByPrice(p, N);
			break;
		case 7:
			PrintByTitle(p, N);
			break;
		case 8:
			PrintByPriceRange(p, N);
			break;
		case 9:
			cout << "Input file name: "; cin >> filename;
			LoadFromFile(p, N, filename);
			break;
		case 10:
			cout << "Input file name: "; cin >> filename;
			SaveToFile(p, N, filename);
			break;
		case 0:
			break;
		default:
			cout << "You have entered an incorrect value! "
				"You must enter the number - the number of the selected menu item" << endl;
		}

	} while (menuItem != 0);
}

int main()
{ 
	Menu();

	return 0;
}
