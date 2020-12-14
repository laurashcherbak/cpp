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

//void Create(Goods* p, const int N)
//{
//	int unitOfMeasurement;
//
//	for (int i = 0; i < N; i++)
//	{
//		cout << "Product No " << i + 1 << ":" << endl;
//
//		cout << " title: "; cin >> p[i].title;
//		p[i].price = GetAndCheckDoubleValue(" price: ");
//		p[i].amount = GetAndCheckUnsignedValue(" amount: ", 0, 10000);
//		unitOfMeasurement = GetAndCheckUnsignedValue("unit of measurement (0 - KG, 1 - Packet, 2 - Piece): ", 0, 2);
//		p[i].unitOfMeasurement = (UnitOfMeasurement)unitOfMeasurement;
//		cout << endl;
//	}
//}

void Print(const string filename)
{
	int N;
	ifstream fin(filename);
	fin >> N;
	Goods* p = new Goods[N];
	int unitOfMeasurement;

	cout << "+==========================================================+" << endl;
	cout << "| No |     Title    | Price | Amount | Unit of measurement |" << endl;
	cout << "+----------------------------------------------------------+" << endl;

	for (int i = 0; i < N; i++)
	{
		fin >> p[i].title;
		fin >> p[i].price;
		fin >> p[i].amount;
		fin >> unitOfMeasurement;
		p[i].unitOfMeasurement = (UnitOfMeasurement)unitOfMeasurement;

		cout << "| " << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << p[i].title
			<< "| " << setw(5) << right << p[i].price << " "
			<< "| " << setw(6) << right << p[i].amount << " "
			<< "| " << setw(20) << left << unitOfMeasurmentStr[p[i].unitOfMeasurement]
			<< "|" << endl;
	}

	cout << "+==========================================================+" << endl;
	cout << endl;
	fin.close();
}

void PrintByTitle(const string filename)
{
	int N;
	ifstream fin(filename);
	fin >> N;
	Goods* p = new Goods[N];
	int unitOfMeasurement;

	string title;
	cout << "Input title: ";
	cin >> title;
	cout << endl;

	cout << "+==========================================================+" << endl;
	cout << "| No |     Title    | Price | Amount | Unit of measurement |" << endl;
	cout << "+----------------------------------------------------------+" << endl;

	for (int i = 0; i < N; i++)
	{
		fin >> p[i].title;
		fin >> p[i].price;
		fin >> p[i].amount;
		fin >> unitOfMeasurement;
		p[i].unitOfMeasurement = (UnitOfMeasurement)unitOfMeasurement;

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
	fin.close();
}

void PrintByPriceRange(const string filename)
{
	int N;
	ifstream fin(filename);
	fin >> N;
	Goods* p = new Goods[N];
	int unitOfMeasurement;

	double Min, Max;
	Min = GetAndCheckDoubleValue("Enter min value: ");
	Max = GetAndCheckDoubleValue("Enter max value: ");

	cout << "+==========================================================+" << endl;
	cout << "| No |     Title    | Price | Amount | Unit of measurement |" << endl;
	cout << "+----------------------------------------------------------+" << endl;

	for (int i = 0; i < N; i++)
	{
		fin >> p[i].title;
		fin >> p[i].price;
		fin >> p[i].amount;
		fin >> unitOfMeasurement;
		p[i].unitOfMeasurement = (UnitOfMeasurement)unitOfMeasurement;

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
	fin.close();
}

//void SaveToFile(Goods* p, const int N, const char* filename)
//{
//	ofstream fout(filename);
//	fout << N << endl;
//	for (int i = 0; i < N; i++)
//	{
//		fout << p[i].title << " " << p[i].price << " " << p[i].amount << " " << p[i].unitOfMeasurement << endl;
//	}
//	fout.close();
//}
//
//void LoadFromFile(const string filename)
//{
//	int N;
//	ifstream fin(filename);
//	fin >> N;
//	Goods* p = new Goods[N];
//	int unitOfMeasurement;
//	for (int i = 0; i < N; i++)
//	{
//		fin >> p[i].title;
//		fin >> p[i].price;
//		fin >> p[i].amount;
//		fin >> unitOfMeasurement;
//		p[i].unitOfMeasurement = (UnitOfMeasurement)unitOfMeasurement;
//	}
//	fin.close();
//}

UnitOfMeasurement GetEnumUnitOfMeasurement(const int unitOfMeasurement) {
	return (UnitOfMeasurement)unitOfMeasurement;
}

void RemoveItem(const string filename)
{
	int index;
	int unitOfMeasurement;
	Goods t;
	int N;

	Print(filename);

	ifstream fin(filename);
	fin >> N;

	index = GetAndCheckUnsignedValue("Enter No: ", 1, N);
	index--;

	if (index <= N) {
		ofstream fout(filename);
		fout << N - 1 << endl;
		for (int i = 0; i < N; i++) {
			fin >> t.title;
			fin >> t.price;
			fin >> t.amount;
			fin >> unitOfMeasurement;
			t.unitOfMeasurement = GetEnumUnitOfMeasurement(unitOfMeasurement);// (UnitOfMeasurement)unitOfMeasurement;

			if (i != index)
			{
				fout << t.title << " " << t.price << " " << t.amount << " " << t.unitOfMeasurement << endl;
			}
		}
		fout.close();
	}
	fin.close();
}

void AddItem(const string filename)
{
	int N;
	ifstream fin(filename);
	fin >> N;
	fin.close();

	Goods t;
	int unitOfMeasurement;
	fstream fapp(filename, ios::app);
	cout << "Product No " << N + 1 << ":" << endl;
	cout << " title: "; cin >> t.title;
	t.price = GetAndCheckDoubleValue(" price: ");
	t.amount = GetAndCheckUnsignedValue(" amount: ", 0, 10000);
	unitOfMeasurement = GetAndCheckUnsignedValue("unit of measurement (0 - KG, 1 - Packet, 2 - Piece): ", 0, 2);
	t.unitOfMeasurement = (UnitOfMeasurement)unitOfMeasurement;
	cout << endl;
	fapp << t.title << " " << t.price << " " << t.amount << " " << t.unitOfMeasurement << endl;
	fapp.close();

	fstream fout(filename, ios::in | ios::out);
	fout << N + 1 << endl;
	fout.close();
}

void ChangeItem(const string filename)
{
	int index;
	int unitOfMeasurement;
	Goods t;
	int N;

	Print(filename);

	ifstream fin(filename);
	fin >> N;

	index = GetAndCheckUnsignedValue("Enter No: ", 1, N);
	index--;

	if (index <= N) {
		ofstream fout(filename);
		fout << N << endl;
		for (int i = 0; i < N; i++) {
			if (i == index)
			{
				cout << "Product No " << i << ":" << endl;
				cout << " title: "; cin >> t.title;
				t.price = GetAndCheckDoubleValue(" price: ");
				t.amount = GetAndCheckUnsignedValue(" amount: ", 0, 10000);
				unitOfMeasurement = GetAndCheckUnsignedValue("unit of measurement (0 - KG, 1 - Packet, 2 - Piece): ", 0, 2);
				t.unitOfMeasurement = (UnitOfMeasurement)unitOfMeasurement;
				cout << endl;
				fout << t.title << " " << t.price << " " << t.amount << " " << t.unitOfMeasurement << endl;
			}
			else {
				fin >> t.title;
				fin >> t.price;
				fin >> t.amount;
				fin >> unitOfMeasurement;
				t.unitOfMeasurement = (UnitOfMeasurement)unitOfMeasurement;
				fout << t.title << " " << t.price << " " << t.amount << " " << t.unitOfMeasurement << endl;
			}
		}
		fout.close();
	}
	fin.close();
}

void Menu()
{
	string filename = "t.txt";

	int menuItem;

	do {
		cout << endl << endl;
		cout << "Select an action:" << endl << endl;
		cout << " [1] - enter/add data" << endl;
		cout << " [2] - delete data" << endl;
		cout << " [3] - change data" << endl;
		cout << " [4] - print data" << endl;
		cout << " [5] - print product's information by title" << endl;
		cout << " [6] - print products' information by the specified price range" << endl;
		cout << " [0] - exit" << endl << endl;
		cout << "Enter a number: "; cin >> menuItem;
		cout << endl << endl;

		switch (menuItem)
		{
		case 1:
			AddItem(filename);
			break;
		case 2:
			RemoveItem(filename);
			break;
		case 3:
			ChangeItem(filename);
			break;
		case 4:
			Print(filename);
			break;
		case 5:
			PrintByTitle(filename);
			break;
		case 6:
			PrintByPriceRange(filename);
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
